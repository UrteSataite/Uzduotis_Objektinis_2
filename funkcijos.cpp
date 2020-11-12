#include "C:\Users\urte.LAPTOP-6PGCDFBJ\Desktop\3 sem\Objektinis programavimas\Uzduotis_1Dalis\Uzduotis\Header Files\funkcijos.h"
#include "C:\Users\urte.LAPTOP-6PGCDFBJ\Desktop\3 sem\Objektinis programavimas\Uzduotis_1Dalis\Uzduotis\Header Files\strukturos.h"
#include "C:\Users\urte.LAPTOP-6PGCDFBJ\Desktop\3 sem\Objektinis programavimas\Uzduotis_1Dalis\Uzduotis\Header Files\outputai.h"

bool compareAVG(studentas_sort* a, studentas_sort* b) { return a->vidurkiai < b->vidurkiai; };
bool compareV(studentas_sort* a, studentas_sort* b) { return a->vardai < b->vardai; };
bool compareP(studentas_sort* a, studentas_sort* b) { return a->pavardes < b->pavardes; };


double gal_mediana(int egr, std::list<int> nd_rez)
{
	std::vector<double> eilute;
	for (auto const& i : eilute) {
		eilute.push_back(i);
	}

	eilute.push_back(egr);

	if (eilute.size() % 2 == 0)
	{
		return (eilute[eilute.size() / 2 - 1] + eilute[eilute.size() / 2]) / 2;
	}
	else
	{
		return eilute[eilute.size() / 2];
	}
}

double gal_rez(int egr, std::list<int> nd_rez)
{
	double vidurkis, galutinis1;

	vidurkis = accumulate(nd_rez.begin(), nd_rez.end(), 0.000) / nd_rez.size();
	galutinis1 = (0.4 * vidurkis) + (0.6 * egr);

	return galutinis1;
}

std::list<double> vid_skaiciavimas(std::list<studentas> studentai)
{
	std::list<double> vidurkiai;
	for (auto const& i : studentai)
	{
		std::cout << "Skaiciuojamas vidurkis \n";
		vidurkiai.push_back(gal_rez(i.iverciai.back(), i.iverciai));
	}


	return vidurkiai;
}

std::list<double> med_skaiciavimas(std::list<studentas> studentai)
{
	std::list<double> medianos;
	for (auto const& i : studentai)
	{
		std::cout << "Skaiciuojama mediana \n";
		medianos.push_back(gal_mediana(i.iverciai.back(), i.iverciai));
	}

	return medianos;
}

std::list<studentas_sort> rusiavimas(std::list<studentas> studentai, std::list<double> vidurkiai, std::list<double> medianos)
{
	std::list<studentas_sort> stud_rus;

	std::list<studentas>::iterator it1 = studentai.begin();
	std::list<double>::iterator it2 = vidurkiai.begin();
	std::list<double>::iterator it3 = medianos.begin();
	
	for (; it1 != studentai.end() && it2 != vidurkiai.end() && it3 != medianos.end(); ++it1, ++it2, ++it3)
	{
		stud_rus.push_back(studentas_sort{ it1->vardai, it1->pavardes, *it2, *it3 });
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
		//stud_rus.sort();
	}
	else if (var == "P")
	{
		//stud_rus.sort();
	}

	studentai.clear();
	std::list<studentas>().swap(studentai);
	vidurkiai.clear();
	std::list<double>().swap(vidurkiai);
	medianos.clear();
	std::list<double>().swap(medianos);

	return stud_rus;
}


void testas(std::string failo_pav, int irasu_sk, int testas)
{
	std::list<studentas_sort> stud_sort;
	std::ifstream infile;
	//Nuskaitomas failas

	auto startas = std::chrono::high_resolution_clock::now();

	auto start1 = std::chrono::high_resolution_clock::now();

	std::list<studentas> studentai = failo_nuskaitymas(failo_pav, infile);

	auto end1 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end1 - start1;

	std::cout << "Failo is " << irasu_sk << " irasu nuskaitymas laikas " << diff.count() << " s\n";

	for (auto const& i : studentai)
	{
		stud_sort.push_back(studentas_sort{ i.vardai, i.pavardes, gal_rez(i.iverciai.back(), i.iverciai) ,  gal_mediana(i.iverciai.back(), i.iverciai) });
	}

	//Issrusiuojama didejimo tvarka
	auto start2 = std::chrono::high_resolution_clock::now();

	stud_sort.sort(CompareAvg());

	auto end2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff1 = end2 - start2;

	std::cout << "Failo is " << irasu_sk << " irasu isrusiavimo didejimo tvarka laikas " << diff1.count() << " s\n";

	//Suskirstoma i nuskriaustuosius ir galvocius

	std::list<nuskriaustieji> nus;
	std::list<galvociai> gal;

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

	std::cout << " " << std::endl;
 
	////Rasymas i faila nuskriaustuju
	//auto start4 = std::chrono::high_resolution_clock::now();
	//rasymas_i_faila_nuskriaustieji(nus, "nuskriaustieji.txt");
	//auto end4 = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<double> diff3 = end4 - start4;

	//std::cout << "Failo is " << irasu_sk << " Nuskriaustuju irasymo laikas " << diff3.count() << " s\n";

	////Rasymas i faila galvociu
	//auto start5 = std::chrono::high_resolution_clock::now();

	//rasymas_i_faila_galvociai(gal, "galvociai.txt");

	//auto end5 = std::chrono::high_resolution_clock::now();


	//std::chrono::duration<double> diff4 = end5 - start5;

	//std::cout << "Failo is " << irasu_sk << " Galvociu irasymo laikas " << diff4.count() << " s\n";

	//auto endas = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<double> diff5 = endas - startas;

	//std::cout << "Failo is " << irasu_sk << " Testo nr " << testas <<" rezultatas " << diff5.count() << " s\n";

	nus.clear();
	
	std::list<nuskriaustieji>().swap(nus);
	gal.clear();
	std::list<galvociai>().swap(gal);
	studentai.clear();
	std::list<studentas>().swap(studentai);
	stud_sort.clear();
	std::list<studentas_sort>().swap(stud_sort);

}


bool isNumber(std::string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

