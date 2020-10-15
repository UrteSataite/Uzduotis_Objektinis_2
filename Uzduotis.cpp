
// DOKUMENTACIJA
// v0.2 uzduotis, realizuota naudojant std::vector tipo konteineri bei ikelta pavyzdini faila.
// Pridetas duomenu skaitymas is .txt failo, realizuotas rusiavimas bei duomenu rasymas i .txt faila.
// v0.3 uzduotis, is main'o i .h failus iskeltos funkcijos, strukturos, naudojamos bibliotekos bei aprasyti kintamieji. Taip pat programa papildyta try {} catch {}.

#include "biblioteka.h"

int main()
{
	
	do {
		try {
			std::cout << "Ar norite nuskaityti is failo duomenis ar ivesti ? (N-nuskaityti/I-ivesti)\n";
			std::cin >> opt;
			if (opt != "N" && opt != "I")
			{
				throw std::runtime_error("Galima arba Nuskaityti(N), arba Ivesti(I) duomenis!");
			}
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Jusu pasirinkimas: " << opt << std::endl;
			std::cout << "Pasirinkite dar karta. " << std::endl;
		}
	} while (opt != "N" && opt != "I");

	if (opt == "N")
	{
		std::vector<studentas> studentai;
		std::vector<informacija> info;
		std::vector<int> patikrinti;
		std::string failo_pav;

		do {
			try {
				std::cout << "Iveskite failo, is kurio bus skaitomi duomenys, pavadinima: \n";
				std::cin >> failo_pav;
				infile.open(failo_pav);

				if (infile.fail())
				{
					throw std::runtime_error("Nepavyksta atverti duomenu failo. Patikrinkite, ar failo pavadinimas ivestas teisingai!");
				}
			}
			catch (std::runtime_error& x) {
				std::cout << x.what() << std::endl;
				std::cout << "Ivestas failo pavadinimas: " << failo_pav << std::endl;
				std::cout << "Iveskite failo pavadinima dar karta! " << std::endl;
			}
		} while (infile.fail());

		int rows = 0, cols = 0;
		std::string eilute, reiksme;

		// while ciklas skirtas suzinoti, kiek failas turi eiluciu ir stulpeliu
		while (std::getline(infile, eilute)) {
			rows++;
			if (rows == 1)
			{
				std::stringstream ss(eilute);
				while (ss >> reiksme)
					cols++;
			}
		}
		infile.close();
		infile.open(failo_pav);

		std::string rez;
		std::vector<std::string> visi_rezultatai_i;
		std::vector<std::string> visi_rezultatai;

		for (int i = 0; i < 1; i++)
		{
			infile >> vardas_i >> pavarde_i;
			for (int j = 0; j < cols - 2; j++)
			{
				infile >> rez;
				visi_rezultatai_i.push_back(rez);
			}
			info.push_back(informacija{ vardas_i, pavarde_i, visi_rezultatai_i });
			visi_rezultatai_i.clear();
			// swap funckija naudojama visame kode tam, kad sukeistu nauja sukurta vektoriu su isvalytu reikiamu vektoriu
			// be swap funkcijos iskyla problemu del atminties, kurios paprastas clear() neisvalo
			std::vector<std::string>().swap(visi_rezultatai_i);
		}
		// nuskaitoma likusi dokumento dalis (be etikeciu, tik duomenys)
		for (int i = 1; i < rows; i++)
		{
			infile >> vardas >> pavarde;
			for (int j = 0; j < cols - 2; j++)
			{
				infile >> rez;
				visi_rezultatai.push_back(rez);
				for (int i = 0; i < visi_rezultatai.size(); i++)
				{
					if (!isNumber(visi_rezultatai[i]))
					{
						std::cout << "Klaida: faile rezultatu vietose yra raides! \n";
					}
					else
					{
						patikrinti.push_back(std::stoi(visi_rezultatai[i]));
					}
					visi_rezultatai.clear();
					std::vector<std::string>().swap(visi_rezultatai);
				}
			}
			studentai.push_back(studentas{ vardas, pavarde, patikrinti });
			patikrinti.clear();
			std::vector<int>().swap(patikrinti);
		}
		std::vector<double> vidurkiai;
		std::vector<double> medianos;
		for (int i = 0; i < studentai.size(); i++)
		{
			std::cout << "Skaiciuojama mediana ir vidurkis \n";
			vidurkiai.push_back(gal_rez(studentai[i].iverciai.back(), studentai[i].iverciai));
			medianos.push_back(gal_mediana(studentai[i].iverciai.back(), studentai[i].iverciai));
		}
		std::vector<studentas_sort> stud_rus;
		for (int i = 0; i < studentai.size(); i++)
		{
			stud_rus.push_back(studentas_sort{ studentai[i].vardai, studentai[i].pavardes, vidurkiai[i], medianos[i] });
		}

		vidurkiai.clear();
		medianos.clear();
		studentai.clear();

		std::vector<double>().swap(vidurkiai);
		std::vector<double>().swap(medianos);
		std::vector<studentas>().swap(studentai);

		// rusiavimas
		std::string var;
		do {
			try {
				std::cout << "Rusiuoti pagal vardus ar pavardes ? (V/P)";
				std::cin >> var;

				if (var != "V" && var != "P")
				{
					throw std::runtime_error("Neteisingas pasirinkimas! Galima pasirinkti V arba P");
				}
			}
			catch (std::runtime_error& a) {
				std::cout << a.what() << std::endl;
				std::cout << "Jusu pasirinkimas: " << var << std::endl;
				std::cout << "Pasirinkite dar karta." << std::endl;
			}
		} while (var != "V" && var != "P");

		if (var == "V")
		{
			std::sort(stud_rus.begin(), stud_rus.end(), compareV);
		}
		else if (var == "P")
		{
			std::sort(stud_rus.begin(), stud_rus.end(), compareP);
		}

		// skaitymas i faila
		myfile.open("kursiokai.txt");
		for (int i = 0; i < info.size(); i++)
		{
			myfile << "Vardas" << std::setw(25) << "Pavarde" << std::setw(25) << std::fixed << std::setprecision(2) << "Galutinis(Vid.)" << std::setw(25) << std::fixed << std::setprecision(2) << "Galutinis(Med.)" << "\n";
		}
		for (int i = 0; i < stud_rus.size(); i++)
		{
			myfile << stud_rus[i].vardai << std::setw(25) << stud_rus[i].pavardes << std::setw(25) << stud_rus[i].vidurkiai << std::setw(25) << stud_rus[i].medianos << "\n";
		}

		myfile.close();
		stud_rus.clear();
		std::vector<studentas_sort>().swap(stud_rus);
		std::vector<studentas_sort>().swap(stud_rus);

	}

	else if (opt == "I")
	{
		do {
			try {
				std::cout << "Iveskite studentu skaiciu: \n";
				std::cin >> sk;

				if (sk < 0)
				{
					throw std::invalid_argument("Ivesta reiksme turi buti skaicius didesnis uz 0! \n");
				}
			}
			catch (std::invalid_argument& y) {
				std::cout << y.what() << std::endl;
				std::cout << "Ivesta reiksme: " << sk << std::endl;
				std::cout << "Iveskite dar karta. " << std::endl;
			}
		} while (sk < 0);

		for (int i = 0; i < sk; i++)
		{
			int p = 0;
			while (p == 0)
			{
				try {
					std::cout << "Iveskite studento varda: \n";
					std::cin >> vardas;

					for (int i = 0; i < vardas.size(); i++)
					{
						if (std::isdigit(vardas[i]))
						{
							throw std::invalid_argument("Varde negali buti skaiciu! \n");

						}
						else {

							p = 1;
						}
					}
				}
				catch (std::invalid_argument& a) {
					p = 0;
					std::cout << a.what() << std::endl;
					std::cout << "Iveskite varda dar karta: " << std::endl;
				}

			}

			vardai.push_back(vardas);

			int r = 0;
			while (r == 0) {
				try {

					std::cout << "Iveskite studento pavarde: \n";
					std::cin >> pavarde;

					for (int i = 0; i < pavarde.size(); i++)
					{
						if (std::isdigit(pavarde[i]))
						{

							throw std::invalid_argument("Pavardeje negali buti skaiciu! \n");
						}
						else {
							r = 1;
						}
					}
				}
				catch (std::invalid_argument& a) {
					r = 0;
					std::cout << a.what() << std::endl;
					std::cout << "Iveskite pavarde dar karta: " << std::endl;
				}
			}

			pavardes.push_back(pavarde);

			do {
				try {
					std::cout << "Ar balus sugeneruoti automatiskai? (T/N) \n";
					std::cin >> ats;

					if (ats != "T" && ats != "N")
					{
						throw std::runtime_error("Bloga ivestis! Pasirinkti galima T arba N!");
					}
				}
				catch (std::runtime_error& e)
				{
					std::cout << e.what() << std::endl;
					std::cout << "Jusu pasirinkimas: " << ats << std::endl;
					std::cout << "Pasirinkite dar karta. " << std::endl;
				}
			} while (ats != "T" && ats != "N");

			if (ats == "T") {
				while (true) {

					int max = 10;
					srand(time(0));
					tmp = rand() % max;
					nd_rez.push_back(tmp);

					std::cout << "SUGENERUOTAS NAMU DARBU BALAS  " << tmp << "\n";

					do {
						try {
							std::cout << "Ar jau ivesti visi rezulatatai (T/N)? \n";
							std::cin >> tn;

							if (tn != "T" && tn != "N")
							{
								throw std::runtime_error("Bloga ivestis! Pasirinkti galima T arba N!");
							}
						}
						catch (std::runtime_error& e)
						{
							std::cout << e.what() << std::endl;
							std::cout << "Jusu pasirinkimas: " << tn << std::endl;
							std::cout << "Pasirinkite dar karta. " << std::endl;
						}
					} while (tn != "T" && tn != "N");

					if (tn == "T") {
						break;
					}
				}
			}
			else if (ats == "N") {
				while (true) {
					std::cout << "Iveskite namu darbu rezultatus \n";
					std::cin >> tmp;
					if (tmp > 0 && tmp <= 10)
					{
						nd_rez.push_back(tmp);
						std::cout << "Ar jau ivesti visi rezulatatai (T/N)? \n";

						std::cin >> tn2;
						if (tn == "T") {
							break;
						}
					}
					else {
						std::cout << "Klaida: rezultatas turi buti pateiktas 10-baleje sistemoje.\n";
					}
				}
			}
			do {
				try {

					std::cout << "Ar egzamino bala sugeneruoti automatiskai? (T/N) \n";
					std::cin >> ats2;

					if (ats2 != "T" && ats2 != "N")
					{
						throw std::runtime_error("Bloga ivestis! Pasirinkti galima T arba N!");
					}
				}
				catch (std::runtime_error& e)
				{
					std::cout << e.what() << std::endl;
					std::cout << "Jusu pasirinkimas: " << ats2 << std::endl;
					std::cout << "Pasirinkite dar karta. " << std::endl;
				}
			} while (ats2 != "T" && ats2 != "N");

			if (ats2 == "T")
			{
				int max = 10;
				srand(time(0));
				egr = rand() % max;
				std::cout << "SUGENERUOTAS EGZAMINO BALAS  " << egr << "\n";
			}
			else
			{
				std::cout << "Iveskite egzamino rezultata: \n";
				std::cin >> egr;
				if (egr < 0 || egr > 11)
				{
					std::cout << "Klaida: rezultatas turi buti pateiktas 10-baleje sistemoje.\n";
				}
			}

			galutiniai.push_back(gal_rez(egr, nd_rez));
			galutiniai2.push_back(gal_mediana(egr, nd_rez));
			nd_rez.clear();
		}
		do {
			try {
				std::cout << "Mediana ar Vidurkis (M/V): \n";
				std::cin >> mv;

				if (mv != "M" && mv != "V")
				{
					throw std::runtime_error("Bloga ivestis! Pasirinkti galima T arba N!");
				}

			}
			catch (std::runtime_error& e) {
				std::cout << e.what() << std::endl;
				std::cout << "Jusu pasirinkimas: " << mv << std::endl;
				std::cout << "Pasirinkite dar karta. " << std::endl;
			}
		} while (mv != "M" && mv != "V");

		if (mv == "M")
		{
			atsp_rez(vardai, pavardes, galutiniai2);
		}
		else
		{
			atsp_rez(vardai, pavardes, galutiniai);
		}
	}
}