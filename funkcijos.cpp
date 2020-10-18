#include "funkcijos.h"
#include "strukturos.h"
#include "outputai.h"

double gal_mediana(int egr, std::vector<int> nd_rez)
{
	std::vector<double> eilute;
	for (int i = 0; i < nd_rez.size(); i++) {
		eilute.push_back(nd_rez.at(i));
	}

	eilute.push_back(egr);

	std::sort(eilute.begin(), eilute.end());

	if (eilute.size() % 2 == 0)
	{
		return (eilute[eilute.size() / 2 - 1] + eilute[eilute.size() / 2]) / 2;
	}
	else
	{
		return eilute[eilute.size() / 2];
	}
}

// Double funkcija, apskaiciuojanti kiekvieno studento nd pazymiu vidurki ir grazinanti galutini bala, apskaiciuota pagal salygoje nurodyta formule

double gal_rez(int egr, std::vector<int> nd_rez)
{
	double vidurkis, galutinis1;

	vidurkis = accumulate(nd_rez.begin(), nd_rez.end(), 0.000) / nd_rez.size();
	galutinis1 = (0.4 * vidurkis) + (0.6 * egr);

	return galutinis1;
}

std::vector<double> vid_skaiciavimas(std::vector<studentas> studentai)
{
	std::vector<double> vidurkiai;
	for (int i = 0; i < studentai.size(); i++)
	{
		std::cout << "Skaiciuojamas vidurkis \n";
		vidurkiai.push_back(gal_rez(studentai[i].iverciai.back(), studentai[i].iverciai));
	}


	return vidurkiai;
}

std::vector<double> med_skaiciavimas(std::vector<studentas> studentai)
{
	std::vector<double> medianos;
	for (int i = 0; i < studentai.size(); i++)
	{
		std::cout << "Skaiciuojama mediana \n";
		medianos.push_back(gal_mediana(studentai[i].iverciai.back(), studentai[i].iverciai));
	}


	return medianos;

}

std::vector<studentas_sort> rusiavimas(std::vector<studentas> studentai, std::vector<double> vidurkiai, std::vector<double> medianos)
{


	std::vector<studentas_sort> stud_rus;

	for (int i = 0; i < studentai.size(); i++)
	{
		stud_rus.push_back(studentas_sort{ studentai[i].vardai, studentai[i].pavardes, vidurkiai[i], medianos[i] });
	}

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

	studentai.clear();
	std::vector<studentas>().swap(studentai);
	vidurkiai.clear();
	std::vector<double>().swap(vidurkiai);
	medianos.clear();
	std::vector<double>().swap(medianos);

	return stud_rus;
}


void testas(std::string failo_pav, int irasu_sk, int testas)
{
	std::vector<studentas_sort> stud_sort;
	std::ifstream infile;
	//Nuskaitomas failas
	auto startas = std::chrono::high_resolution_clock::now();

	auto start1 = std::chrono::high_resolution_clock::now();
	std::vector<studentas> studentai = failo_nuskaitymas(failo_pav, infile);
	auto end1 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end1 - start1;

	std::cout << "Failo is " << irasu_sk << " irasu nuskaitymas laikas " << diff.count() << " s\n";

	for (int i = 1; i < studentai.size(); i++)
	{
		stud_sort.push_back(studentas_sort{ studentai[i].vardai, studentai[i].pavardes, gal_rez(studentai[i].iverciai.back(), studentai[i].iverciai) ,  gal_mediana(studentai[i].iverciai.back(), studentai[i].iverciai) });
	}

	//Issrusiuojama didejimo tvarka
	auto start2 = std::chrono::high_resolution_clock::now();

	std::sort(stud_sort.begin(), stud_sort.end(), compareAVG);

	auto end2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff1 = end2 - start2;

	std::cout << "Failo is " << irasu_sk << " irasu isrusiavimo didejimo tvarka laikas " << diff1.count() << " s\n";

	//Suskirstoma i nuskriaustuosius ir galvocius
	std::vector<nuskriaustieji> nus;
	std::vector<galvociai> gal;

	auto start3 = std::chrono::high_resolution_clock::now();
	for (auto& it : stud_sort) {
		if (it.vidurkiai < 5)
		{

			nus.push_back(nuskriaustieji{ it.vardai, it.pavardes, it.vidurkiai });
		}
		else if (it.vidurkiai >= 5)
		{
			gal.push_back(galvociai{ it.vardai, it.pavardes, it.vidurkiai });
		}
	}
	auto end3 = std::chrono::high_resolution_clock::now();


	std::chrono::duration<double> diff2 = end3 - start3;

	std::cout << "Failo is " << irasu_sk << " irasu padalijimo i dvi grupes laikas " << diff2.count() << " s\n";

	//Rasymas i faila nuskriaustuju
	auto start4 = std::chrono::high_resolution_clock::now();
	rasymas_i_faila_nuskriaustieji(nus, "nuskriaustieji.txt");
	auto end4 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff3 = end4 - start4;

	std::cout << "Failo is " << irasu_sk << " Nuskriaustuju irasymo laikas " << diff3.count() << " s\n";

	//Rasymas i faila galvociu
	auto start5 = std::chrono::high_resolution_clock::now();

	rasymas_i_faila_galvociai(gal, "galvociai.txt");

	auto end5 = std::chrono::high_resolution_clock::now();


	std::chrono::duration<double> diff4 = end5 - start5;

	std::cout << "Failo is " << irasu_sk << " Galvociu irasymo laikas " << diff4.count() << " s\n";

	auto endas = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff5 = endas - startas;
	std::cout << "Failo is " << irasu_sk << " Testo nr " << testas <<" rezultatas " << diff5.count() << " s\n";
}


bool isNumber(std::string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

bool compareV(studentas_sort& a, studentas_sort& b) { return a.vardai < b.vardai; };
bool compareP(studentas_sort& a, studentas_sort& b) { return a.pavardes < b.pavardes; };
bool compareAVG(studentas_sort& a, studentas_sort& b) { return a.vidurkiai < b.vidurkiai; };