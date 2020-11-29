#include "outputai.h"
#include "funkcijos.h"
#include "strukturos.h"

// Funkcija, nuskaitanti duomenis is failo i lista
std::list<studentas> failo_nuskaitymas(std::string failo_pav, std::ifstream& infile)
{
	std::list<studentas> studentai;

	std::string vardas_i, pavarde_i, vardas, pavarde;

	std::list<int> patikrinti;

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
	std::list<std::string> visi_rezultatai;

	std::getline(infile, eilute);

	// nuskaitoma likusi dokumento dalis (be etikeciu, tik duomenys)

	for (int i = 1; i < rows; i++)
	{
		infile >> vardas >> pavarde;

		for (int j = 0; j < cols - 2; j++)
		{
			infile >> rez;
			visi_rezultatai.push_back(rez);

			for (auto const& i : visi_rezultatai) {
				if (!isNumber(i))
				{
					std::cout << "Klaida: faile rezultatu vietose yra raides! \n";
				}
				else
				{
					patikrinti.push_back(stoi(i));
				}
			}
			visi_rezultatai.clear();
			std::list<std::string>().swap(visi_rezultatai);
		}
		studentai.push_back(studentas{ vardas, pavarde, patikrinti });
		patikrinti.clear();
		std::list<int>().swap(patikrinti);
	}
	infile.close();

	return studentai;
}

// Duomenu rasymas i faila nuskriaustieji.txt 
void rasymas_i_faila_nuskriaustieji(std::list<nuskriaustieji> nus, std::string failo_pav)
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
	for (auto const& i : nus)
	{
		myfile << i.vardai << std::setw(25) << i.pavardes << std::setw(25) << i.iverciai << "\n";
	}

}

// Duomenu rasymas i faila galvociai.txt 
void rasymas_i_faila_galvociai(std::list<studentas_sort> gal, std::string failo_pav)
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

	for (auto const& i : gal)
	{
		myfile << i.vardai << std::setw(25) << i.pavardes << std::setw(25) << i.vidurkiai << "\n";
	}

}
