
#include "outputai.h"
#include "strukturos.h"
#include "biblioteka.h"
#include "funkcijos.h"

void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai)
{
	std::cout << std::setw(25) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(25) << "Galutinis" << std::endl;
	std::cout << "---------------------------------------------------------------------------------\n";
	for (int i = 0; i < vardai.size(); i++) {

		std::cout << std::setw(25) << vardai[i] << std::setw(25) << pavardes[i] << std::setw(25) << std::fixed << std::setprecision(2) << galutiniai[i] << std::endl;

	}
}

std::vector<studentas> failo_nuskaitymas()
{
	std::vector<studentas> studentai;
	std::vector<informacija> info;

	std::string vardas_i, pavarde_i, vardas, pavarde;

	std::vector<int> patikrinti;

	std::fstream infile;

	int rows = 0, cols = 0;
	std::string eilute, reiksme;

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
			perror(nullptr);
			std::cout << "Ivestas failo pavadinimas: " << failo_pav << std::endl;
			std::cout << "Iveskite failo pavadinima dar karta! " << std::endl;
		}
	} while (infile.fail());

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
	infile.close();

	return studentai;
}



void rasymas_i_faila(std::vector<studentas_sort> stud_rus)
{
	std::fstream myfile;
	myfile.open("kursiokai.txt");
	for (int i = 0; i < 1; i++)
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
}
