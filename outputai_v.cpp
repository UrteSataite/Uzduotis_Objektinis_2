#include "outputai_v.h"
#include "funkcijos_v.h"
#include "strukturos_v.h"
#include "Studentas.h"

/**
 * Duomenu rasymas i faila nuskriaustieji.txt
 */
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

/**
 * Duomenu rasymas i faila galvociai.txt
 */
void vec_rasymas_i_faila_galvociai(std::vector<Studentas> gal, std::string failo_pav)
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
		myfile << gal[i].getVec_vardai() << std::setw(25) << gal[i].getVec_pavardes() << std::setw(25) << gal[i].getVec_galutiniai_vidurkiai() << "\n";
	}

}
