
// DOKUMENTACIJA
// v0.2 uzduotis, realizuota naudojant std::vector tipo konteineri bei ikelta pavyzdini faila.
// Pridetas duomenu skaitymas is .txt failo, realizuotas rusiavimas bei duomenu rasymas i .txt faila.
// v0.3 uzduotis, is main'o i .h failus iskeltos funkcijos, strukturos, naudojamos bibliotekos bei aprasyti kintamieji. Taip pat programa papildyta try {} catch {}.

#include "funkcijos.h"
#include "outputai.h"
#include "strukturos.h"

int main()
{

	int sk, egr{}, tmp, tmp2;
	std::vector<int> nd_rez;
	std::vector<std::string> vardai;
	std::vector<std::string> pavardes;
	std::vector<double> galutiniai;
	std::vector<double> galutiniai2;
	std::string vardas, pavarde, vardas_i, pavarde_i;
	std::string mv;
	int egzaminai;
	std::string opt;
	std::string ats;
	std::string ats2;
	std::string tn;
	std::string tn2;
	std::string failo_pav1;
	std::ifstream infile1;



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

		do {
			try {
				std::cout << "Iveskite failo, is kurio bus skaitomi duomenys, pavadinima: \n";
				std::cin >> failo_pav1;
				infile1.open(failo_pav1);

				if (infile1.fail())
				{
					throw std::runtime_error("Nepavyksta atverti duomenu failo. Patikrinkite, ar failo pavadinimas ivestas teisingai!");
				}
			}
			catch (std::runtime_error& x) {
				std::cout << x.what() << std::endl;
				perror(nullptr);
				std::cout << "Ivestas failo pavadinimas: " << failo_pav1 << std::endl;
				std::cout << "Iveskite failo pavadinima dar karta! " << std::endl;
			}
		} while (infile1.fail());

		std::vector<studentas> studentai = failo_nuskaitymas(failo_pav1, infile1);
		std::vector<double> vidurkiai = vid_skaiciavimas(studentai);
		std::vector<double> medianos = med_skaiciavimas(studentai);
		std::vector<studentas_sort> stud_rus = rusiavimas(studentai, vidurkiai, medianos);
		rasymas_i_faila_kursiokiai(stud_rus, "kursiokai.txt");
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

	std::string failo_pav;
	std::ifstream infile;

	//Generuojami failai
	failu_generavimas();

	
	testas("stud1000.txt", 1000, 1);
	testas("stud10000.txt", 10000, 2);
	/*testas("stud100000.txt", 100000, 3);
	testas("stud1000000.txt", 1000000, 4);
	testas("stud10000000.txt", 10000000, 5);*/

}

