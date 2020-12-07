#include "funkcijos_v.h"
#include "strukturos_v.h"
#include "outputai_v.h"

// 2 stratedijos igyvendinimo dalis. Funkcija grazina tuos vektoriaus elementus, kuriu vidurkis mazesnis nei 5
bool tryntimo_salyga(const vec_studentas& vector)
{
	return vector.vec_galutiniai_vidurkiai < 5;
}

// Funkcija, skaiciuojanti galutines medianos reiksmes
double vec_medianos_skaiciavimas(int egr, std::vector<int> nd_rez)
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

// Funkcija, skaiciuojanti vidurki ir galutini bala
double vec_balo_skaiciavimas(int egr, std::vector<int> nd_rez)
{
	double vidurkis, galutinis1;

	vidurkis = accumulate(nd_rez.begin(), nd_rez.end(), 0.000) / nd_rez.size();
	galutinis1 = (0.4 * vidurkis) + (0.6 * egr);

	return galutinis1;
}

// Funckija, irasanti vidurkiu reiksmes studentams
std::vector<double> vec_vidurkiai_funkcija(std::vector<vec_studentas> studentai)
{
	std::vector<double> vec_vidurkiai;
	for (int i = 0; i < studentai.size(); i++)
	{
		std::cout << "Skaiciuojamas vidurkis \n";
		vec_vidurkiai.push_back(vec_balo_skaiciavimas(studentai[i].vec_iverciai.back(), studentai[i].vec_iverciai));
	}
	return vec_vidurkiai;
}

// Funckija, irasanti medianos reiksmes studentams
std::vector<double> vec_medianos_funkcija(std::vector<vec_studentas> studentai)
{
	std::vector<double> vec_medianos;
	for (int i = 0; i < studentai.size(); i++)
	{
		std::cout << "Skaiciuojama mediana \n";
		vec_medianos.push_back(vec_medianos_skaiciavimas(studentai[i].vec_iverciai.back(), studentai[i].vec_iverciai));
	}
	return vec_medianos;
}

// Programos testavimo funkcija
void vec_testas(std::string failo_pav, int irasu_sk, int testas)
{
	// Patikrinimas, ar egzistuoja norimas testuoti failas.
	std::ifstream infile(failo_pav);
	if (infile.fail()) {
		std::cout << "KLAIDA: failas tokiu pavadinimu neegzistuoja! \n" << std::endl;
	}
	else {

		std::ifstream infile;

		auto startas = std::chrono::high_resolution_clock::now();

		// Failo nuskaitymas
		auto start1 = std::chrono::high_resolution_clock::now();

		std::vector<vec_studentas> vec_studentai = vec_failo_nuskaitymas(failo_pav, infile);

		auto end1 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff = end1 - start1;

		std::cout << "Failo is " << irasu_sk << " irasu nuskaitymas laikas " << diff.count() << " s\n";

		for (int i = 1; i < vec_studentai.size(); i++)
		{
		    if(vec_studentai[i].vec_galutiniai_vidurkiai == 0)
            {
                vec_studentai[i].vec_galutiniai_vidurkiai = vec_balo_skaiciavimas(vec_studentai[i].vec_iverciai.back(), vec_studentai[i].vec_iverciai);
            }
            if(vec_studentai[i].vec_galutiniai_medianos == 0)
            {
                vec_studentai[i].vec_galutiniai_medianos = vec_medianos_skaiciavimas(vec_studentai[i].vec_iverciai.back(), vec_studentai[i].vec_iverciai);
            }
        }

		//Issrusiuojama didejimo tvarka
		auto start2 = std::chrono::high_resolution_clock::now();

		std::sort(vec_studentai.begin(), vec_studentai.end(), vec_compareAVG);

		auto end2 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff1 = end2 - start2;

		std::cout << "Failo is " << irasu_sk << " irasu isrusiavimo didejimo tvarka laikas " << diff1.count() << " s\n";

		//Suskirstoma dvi grupes: i nuskriaustuosius ir galvocius. Nuskriaustieji perkeliami i kita vektoriu, istrinami is studentai vektoriaus
		std::vector<vec_nuskriaustieji> vec_nus;

		auto start3 = std::chrono::high_resolution_clock::now();

		for (auto& it : vec_studentai) {
			if (it.vec_galutiniai_vidurkiai < 5)
			{
				vec_nus.push_back(vec_nuskriaustieji{ it.vec_vardai, it.vec_pavardes, it.vec_galutiniai_vidurkiai });
			}
		}

		vec_studentai.erase(std::remove_if(vec_studentai.begin(), vec_studentai.end(), tryntimo_salyga), vec_studentai.end());

		auto end3 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff2 = end3 - start3;

		std::cout << "Failo is " << irasu_sk << " irasu padalijimo i dvi grupes laikas " << diff2.count() << " s\n";

		//Rasymas i faila nuskriaustuju
		auto start4 = std::chrono::high_resolution_clock::now();
		vec_rasymas_i_faila_nuskriaustieji(vec_nus, "nuskriaustieji.txt");
		auto end4 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff3 = end4 - start4;

		std::cout << "Failo is " << irasu_sk << " Nuskriaustuju irasymo laikas " << diff3.count() << " s\n";

		////Rasymas i faila galvociu
		auto start5 = std::chrono::high_resolution_clock::now();
		vec_rasymas_i_faila_galvociai(vec_studentai, "galvociai.txt");
		auto end5 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> diff4 = end5 - start5;

		std::cout << "Failo is " << irasu_sk << " Galvociu irasymo laikas " << diff4.count() << " s\n";

		auto endas = std::chrono::high_resolution_clock::now();

		// Suskaiciuojamas bendras testo laikas
		std::chrono::duration<double> diff5 = endas - startas;

		std::cout << "Failo is " << irasu_sk << " Testo nr " << testas << " rezultatas " << diff5.count() << " s\n";

		std::cout << " " << std::endl;

		vec_nus.clear();
		std::vector<vec_nuskriaustieji>().swap(vec_nus);
		vec_studentai.clear();
		std::vector<vec_studentas>().swap(vec_studentai);
	}

}

bool vec_isNumber(std::string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

// Funkcijos, reikalingos sort veikimui. Palyginami vidurkiai.
bool vec_compareAVG(vec_studentas& a, vec_studentas& b) { return a.vec_galutiniai_vidurkiai < b.vec_galutiniai_vidurkiai; };

