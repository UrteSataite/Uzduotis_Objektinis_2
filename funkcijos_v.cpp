#include "funkcijos_v.h"
#include "strukturos_v.h"
#include "outputai_v.h"

double vec_gal_mediana(int egr, std::vector<int> nd_rez)
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

double vec_gal_rez(int egr, std::vector<int> nd_rez)
{
	double vidurkis, galutinis1;

	vidurkis = accumulate(nd_rez.begin(), nd_rez.end(), 0.000) / nd_rez.size();
	galutinis1 = (0.4 * vidurkis) + (0.6 * egr);

	return galutinis1;
}

std::vector<double> vec_vid_skaiciavimas(std::vector<vec_studentas> studentai)
{
	std::vector<double> vec_vidurkiai;
	for (int i = 0; i < studentai.size(); i++)
	{
		std::cout << "Skaiciuojamas vidurkis \n";
		vec_vidurkiai.push_back(vec_gal_rez(studentai[i].vec_iverciai.back(), studentai[i].vec_iverciai));
	}


	return vec_vidurkiai;
}

std::vector<double> vec_med_skaiciavimas(std::vector<vec_studentas> studentai)
{
	std::vector<double> vec_medianos;
	for (int i = 0; i < studentai.size(); i++)
	{
		std::cout << "Skaiciuojama mediana \n";
		vec_medianos.push_back(vec_gal_mediana(studentai[i].vec_iverciai.back(), studentai[i].vec_iverciai));
	}


	return vec_medianos;

}

void vec_testas(std::string failo_pav, int irasu_sk, int testas)
{
	std::vector<vec_studentas_sort> vec_stud_sort;
	std::ifstream infile;
	//Nuskaitomas failas

	auto startas = std::chrono::high_resolution_clock::now();

	auto start1 = std::chrono::high_resolution_clock::now();

	std::vector<vec_studentas> vec_studentai = vec_failo_nuskaitymas(failo_pav, infile);

	auto end1 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end1 - start1;

	std::cout << "Failo is " << irasu_sk << " irasu nuskaitymas laikas " << diff.count() << " s\n";

	for (int i = 1; i < vec_studentai.size(); i++)
	{
		vec_stud_sort.push_back(vec_studentas_sort{ vec_studentai[i].vec_vardai, vec_studentai[i].vec_pavardes, vec_gal_rez(vec_studentai[i].vec_iverciai.back(), vec_studentai[i].vec_iverciai) ,  vec_gal_mediana(vec_studentai[i].vec_iverciai.back(), vec_studentai[i].vec_iverciai) });
	}

	//Issrusiuojama didejimo tvarka
	auto start2 = std::chrono::high_resolution_clock::now();

	std::sort(vec_stud_sort.begin(), vec_stud_sort.end(), vec_compareAVG);

	auto end2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff1 = end2 - start2;

	std::cout << "Failo is " << irasu_sk << " irasu isrusiavimo didejimo tvarka laikas " << diff1.count() << " s\n";

	//Suskirstoma i nuskriaustuosius ir galvocius

	std::vector<vec_nuskriaustieji> vec_nus;
	std::vector<vec_galvociai> vec_gal;

	auto start3 = std::chrono::high_resolution_clock::now();
	//for(int i=0; i< )
	for (auto& it : vec_stud_sort) {
		if (it.vec_vidurkiai < 5)
		{

			vec_nus.push_back(vec_nuskriaustieji{ it.vec_vardai, it.vec_pavardes, it.vec_vidurkiai });


		}
		else if (it.vec_vidurkiai >= 5)
		{
			vec_gal.push_back(vec_galvociai{ it.vec_vardai, it.vec_pavardes, it.vec_vidurkiai });
		}
	}

	auto end3 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff2 = end3 - start3;

	std::cout << "Failo is " << irasu_sk << " irasu padalijimo i dvi grupes laikas " << diff2.count() << " s\n";

	//Rasymas i faila nuskriaustuju
	auto start4 = std::chrono::high_resolution_clock::now();
	vec_rasymas_i_faila_nuskriaustieji(vec_nus, "nuskriaustieji.txt");
	auto end4 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff3 = end4 - start4;

	std::cout << "Failo is " << irasu_sk << " Nuskriaustuju irasymo laikas " << diff3.count() << " s\n";

	//Rasymas i faila galvociu
	auto start5 = std::chrono::high_resolution_clock::now();

	vec_rasymas_i_faila_galvociai(vec_gal, "galvociai.txt");

	auto end5 = std::chrono::high_resolution_clock::now();


	std::chrono::duration<double> diff4 = end5 - start5;

	std::cout << "Failo is " << irasu_sk << " Galvociu irasymo laikas " << diff4.count() << " s\n";

	auto endas = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff5 = endas - startas;

	std::cout << "Failo is " << irasu_sk << " Testo nr " << testas <<" rezultatas " << diff5.count() << " s\n";

	std::cout << " " << std::endl;

	vec_nus.clear();
	std::vector<vec_nuskriaustieji>().swap(vec_nus);
	vec_gal.clear();
	std::vector<vec_galvociai>().swap(vec_gal);
	vec_studentai.clear();
	std::vector<vec_studentas>().swap(vec_studentai);
	vec_stud_sort.clear();
	std::vector<vec_studentas_sort>().swap(vec_stud_sort);

}


bool vec_isNumber(std::string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

bool vec_compareV(vec_studentas_sort& a, vec_studentas_sort& b) { return a.vec_vardai < b.vec_vardai; };
bool vec_compareP(vec_studentas_sort& a, vec_studentas_sort& b) { return a.vec_pavardes < b.vec_pavardes; };
bool vec_compareAVG(vec_studentas_sort& a, vec_studentas_sort& b) { return a.vec_vidurkiai < b.vec_vidurkiai; };