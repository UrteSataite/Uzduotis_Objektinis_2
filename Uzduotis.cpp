
/*
DOKUMENTACIJA
v0.2 uzduotis, realizuota naudojant std::vector tipo konteineri bei ikelta pavyzdini faila.
Pridetas duomenu skaitymas is .txt failo, realizuotas rusiavimas bei duomenu rasymas i .txt faila.
v0.3 uzduotis, is main'o i .h failus iskeltos funkcijos bei strukturos. Taip pat programa papildyta try {} catch {}.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <sstream> 
#include "spausdinimas.h"
#include "skaiciavimai.h"
#include "strukturos.h"

int main()
{
	std::ofstream myfile;
	std::fstream infile;

	int sk, egr{}, tmp, tmp2;

	std::vector<int> nd_rez;
	std::vector<std::string> vardai;
	std::vector<std::string> pavardes;
	std::vector<double> galutiniai;
	std::vector<double> galutiniai2;

	std::string vardas, pavarde, vardas_i, pavarde_i;

	char mv;

	int egzaminai;

	std::string opt;

	try {
		std::cout << "Ar norite nuskaityti is failo duomenis ar ivesti ? (N-nuskaityti/I-ivesti)\n";
		std::cin >> opt;
		if (opt == "N" || opt == "I")
		{
			if (opt == "N")
			{
				std::vector<studentas> studentai;
				std::vector<informacija> info;
				std::vector<int> patikrinti;


				std::string failo_pav;

				std::cout << "Iveskite failo, is kurio bus skaitomi duomenys, pavadinima: \n";
				std::cin >> failo_pav;

				infile.open(failo_pav);

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

				try
				{
					if (!infile.fail())
					{
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
						std::cout << "Rusiuoti pagal pavardes ar vardus ? (V/P)";
						std::cin >> var;

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
					else { throw std::runtime_error("Nepavyksta atverti duomenu failo. Patikrinkite, ar failo pavadinimas ivestas teisingai!"); }
				}
				catch (std::runtime_error& e) {
					std::cout << e.what() << std::endl;
					std::cout << "Ivestas failo pavadinimas: " << failo_pav << std::endl;
				}
			}

			// nuskaitoma pirma failo eilute (etiketes)

			else if (opt == "I")
			{	
				try {
					std::cout << "Iveskite studentu skaiciu: \n";
					std::cin >> sk;

					if (!isdigit(sk) || sk < 0)
					{
						throw std::invalid_argument("Ivesta reiksme turi buti skaicius didesnis uz 0! \n");
					}

					for (int i = 0; i < sk; i++) {

						std::cout << "Iveskite studento varda: \n";
						std::cin >> vardas;
						if (std::isdigit(vardas[i]))
						{
							std::cout << "Klaida: vardas negali buti skaicius\n";
						}
						else {
							vardai.push_back(vardas);

							std::cout << "Iveskite studento pavarde: \n";
							std::cin >> pavarde;
							if (std::isdigit(pavarde[i]))
							{
								std::cout << "Klaida: pavarde negali buti skaicius \n";
							}
							else
							{
								pavardes.push_back(pavarde);

								std::cout << "Ar balus sugeneruoti automatiskai? (T/N) \n";
								std::string ats;
								std::cin >> ats;

								if (ats == "T") {

									while (true) {

										int max = 10;
										srand(time(0));
										tmp = rand() % max;
										nd_rez.push_back(tmp);

										std::cout << "SUGENERUOTAS NAMU DARBU BALAS  " << tmp << "\n";


										std::cout << "Ar jau ivesti visi rezulatatai (T/N)? \n";
										std::string tn;
										std::cin >> tn;

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
											std::string tn;
											std::cin >> tn;

											if (tn == "T") {
												break;
											}
										}
										else {
											std::cout << "Klaida: rezultatas turi buti pateiktas 10-baleje sistemoje.\n";
										}
									}
								}
								else
								{
									std::cout << "Klaida: reikia pasirinkti T arba N";
								}

								std::cout << "Ar egzamino bala sugeneruoti automatiskai? (T/N) \n";
								std::string ats2;
								std::cin >> ats2;

								if (ats2 == "T")
								{
									int max = 10;
									srand(time(0));
									egr = rand() % max;
									std::cout << "SUGENERUOTAS EGZAMINO BALAS  " << egr << "\n";
								}
								else if (ats == "N")
								{
									std::cout << "Iveskite egzamino rezultata: \n";
									std::cin >> egr;
									if (egr < 0 || egr > 11)
									{
										std::cout << "Klaida: rezultatas turi buti pateiktas 10-baleje sistemoje.\n";
									}
								}
								else
								{
									std::cout << "Klaida: reikia pasirinkti T arba N";
								}

								galutiniai.push_back(gal_rez(egr, nd_rez));

								galutiniai2.push_back(gal_mediana(egr, nd_rez));

								nd_rez.clear();

							}

						}
					}

					std::cout << "Mediana ar Vidurkis (M/V): \n";
					std::cin >> mv;

					if (std::strcmp(&mv, "M"))
					{
						atsp_rez(vardai, pavardes, galutiniai2);
					}
					else
					{
						atsp_rez(vardai, pavardes, galutiniai);
					}
				}
				catch (std::invalid_argument& e) {
					std::cout << "Studentu skaicius turi buti teigiamas skaicius! \n";
					std::cout << "Ivesta reiksme: " << sk << std::endl;
				}
			}
		}
		else
		{
			throw std::runtime_error("Galima arba Nuskaityti(N), arba Ivesti(I) duomenis!");
		}
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Jusu pasirinkimas: " << opt << std::endl;
	}
}
