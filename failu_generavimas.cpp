/* 
5 skirtingu dydziu failu generavivmo funkcija. 

Veikimo principas:
* Vartotojas gali pasirinkti, kiek namu darbu rezultatu sugeneruoti studentams.
* Kiekvienas is 5 failu yra generuojamas analogiskai: pasinaudojant pries tai ivestu nd skaiciumi sukuriamos antrastes,
studentu vardai bei pavardes. Pazymiams generuoti naudojamas std::random_device ir std::mt19937. Prie sugeneruotu namu darbu pazymiu taip pat
sugeneruojamas ir egzamino rezultatas. 
*/

#include "failu_generavimas.h"
#include "outputai_v.h"
#include "strukturos_v.h"


void failu_generavimas()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);

	std::vector<int> kiek_nd_rez;
	int kiek_nd;

	std::cout << "Iveskite, kiek nd ivertinimu sugeneruoti: " << std::endl;
	std::cin >> kiek_nd;
	std::cout << "Pasirinktas nd skaicius: " << kiek_nd << std::endl;

	for (int i = 1; i < kiek_nd + 1; i++)
	{
		kiek_nd_rez.push_back(i);
	}

	//1000 duomenu failo generavimas
	std::ofstream failas1;
	failas1.open("stud1000.txt");

	failas1 << "Vardas" << std::setw(25) << "Pavarde";
	for (int count = 0; count < kiek_nd; count++) {
		failas1 << std::setw(25) << "ND" << kiek_nd_rez[count];
	}
	failas1 << std::setw(25) << "EGZ" << std::endl;

	for (int i = 1; i < 1001; i++)
	{

		failas1 << "Vardas" << i << std::setw(25) << "Pavarde" << i;

		for (int j = 0; j < kiek_nd + 1; j++)
		{
			failas1 << std::setw(25) << dist(mt) << std::setw(25);
		}
		failas1 << "\n";
	}
	failas1.close();

	//10000 duomenu failo generavimas
	std::ofstream failas2("stud10000.txt");

	failas2 << "Vardas" << std::setw(25) << "Pavarde";
	for (int count = 0; count < kiek_nd; count++) {
		failas2 << std::setw(25) << "ND" << kiek_nd_rez[count];
	}
	failas2 << std::setw(25) << "EGZ" << std::endl;

	for (int i = 1; i < 10001; i++)
	{

		failas2 << "Vardas" << i << std::setw(25) << "Pavarde" << i;

		for (int j = 0; j < kiek_nd + 1; j++)
		{
			failas2 << std::setw(25) << dist(mt) << std::setw(25);
		}
		failas2 << "\n";
	}
	failas2.close();

	//100000 duomenu failo generavimas
	std::ofstream failas3("stud100000.txt");

	failas3 << "Vardas" << std::setw(25) << "Pavarde";
	for (int count = 0; count < kiek_nd; count++) {
		failas3 << std::setw(25) << "ND" << kiek_nd_rez[count];
	}
	failas3 << std::setw(25) << "EGZ" << std::endl;

	for (int i = 1; i < 100001; i++)
	{

		failas3 << "Vardas" << i << std::setw(25) << "Pavarde" << i;

		for (int j = 0; j < kiek_nd + 1; j++)
		{
			failas3 << std::setw(25) << dist(mt) << std::setw(25);
		}
		failas3 << "\n";
	}
	failas3.close();

	//1000000 duomenu failo generavimas
	std::ofstream failas4("stud1000000.txt");

	failas4 << "Vardas" << std::setw(25) << "Pavarde";
	for (int count = 0; count < kiek_nd; count++) {
		failas4 << std::setw(25) << "ND" << kiek_nd_rez[count];
	}
	failas4 << std::setw(25) << "EGZ" << std::endl;

	for (int i = 1; i < 1000001; i++)
	{

		failas4 << "Vardas" << i << std::setw(25) << "Pavarde" << i;

		for (int j = 0; j < kiek_nd + 1; j++)
		{
			failas4 << std::setw(25) << dist(mt) << std::setw(25);
		}
		failas4 << "\n";
	}
	failas4.close();

	//10000000 duomenu failo generavimas
	std::ofstream failas5("stud10000000.txt");

	failas5 << "Vardas" << std::setw(25) << "Pavarde";
	for (int count = 0; count < kiek_nd; count++) {
		failas5 << std::setw(25) << "ND" << kiek_nd_rez[count];
	}
	failas5 << std::setw(25) << "EGZ" << std::endl;

	for (int i = 1; i < 10000001; i++)
	{

		failas5 << "Vardas" << i << std::setw(25) << "Pavarde" << i;
		for (int j = 0; j < kiek_nd + 1; j++)
		{
			failas5 << std::setw(25) << dist(mt) << std::setw(25);
		}
		failas5 << "\n";
	}
	failas5.close();

}