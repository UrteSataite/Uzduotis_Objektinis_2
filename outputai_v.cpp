#include "outputai_v.h"
#include "funkcijos_v.h"
#include "strukturos_v.h"

// Funkcija, nuskaitanti duomenis is failo i vektoriu
std::vector<vec_studentas> vec_failo_nuskaitymas(std::string failo_pav, std::ifstream& infile)
{
	std::vector<vec_studentas> vec_studentai;

	std::string vardas_i, pavarde_i, vardas, pavarde;

	std::vector<int> patikrinti;

	int rows = 0, cols = 0;
	std::string eilute, reiksme;

	infile.open(failo_pav);

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
	std::vector<std::string> visi_rezultatai;

	std::getline(infile, eilute);

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
				if (!vec_isNumber(visi_rezultatai[i]))
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
		vec_studentai.push_back(vec_studentas{ vardas, pavarde, patikrinti,0,0 });
		patikrinti.clear();
		std::vector<int>().swap(patikrinti);
	}
	infile.close();

	return vec_studentai;
}

// Duomenu rasymas i faila nuskriaustieji.txt
void vec_rasymas_i_faila_nuskriaustieji(std::vector<vec_nuskriaustieji> nus, std::string failo_pav)
{
	std::ofstream myfile;
	myfile.open(failo_pav);
	if (myfile.fail())
	{
		perror(nullptr);
	}

	for (int i = 0; i < 1; i++)
	{
		myfile << "Vardas" << std::setw(25) << "Pavarde" << std::setw(25) << "Galutinis(Vid.)" << "\n";
	}
	for (int i = 0; i < nus.size(); i++)
	{
		myfile << nus[i].vec_vardai << std::setw(25) << nus[i].vec_pavardes << std::setw(25) << nus[i].vec_iverciai << "\n";
	}

}

// Duomenu rasymas i faila galvociai.txt
void vec_rasymas_i_faila_galvociai(std::vector<vec_studentas> gal, std::string failo_pav)
{
	std::ofstream myfile;
	myfile.open(failo_pav);
	if (myfile.fail())
	{
		perror(nullptr);
	}
	for (int i = 0; i < 1; i++)
	{
		myfile << "Vardas" << std::setw(25) << "Pavarde" << std::setw(25) << "Galutinis(Vid.)" << "\n";
	}

	for (int i = 0; i < gal.size(); i++)
	{
		myfile << gal[i].vec_vardai << std::setw(25) << gal[i].vec_pavardes << std::setw(25) << gal[i].vec_galutiniai_vidurkiai << "\n";
	}

}
