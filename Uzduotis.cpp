
#include "C:\Users\urte.LAPTOP-6PGCDFBJ\Desktop\3 sem\Objektinis programavimas\Uzduotis_1Dalis\Uzduotis\Header Files\funkcijos.h"
#include "C:\Users\urte.LAPTOP-6PGCDFBJ\Desktop\3 sem\Objektinis programavimas\Uzduotis_1Dalis\Uzduotis\Header Files\outputai.h"
#include "C:\Users\urte.LAPTOP-6PGCDFBJ\Desktop\3 sem\Objektinis programavimas\Uzduotis_1Dalis\Uzduotis\Header Files\strukturos.h"

int main()
{

	int sk, egr{}, tmp, tmp2;
	std::list<int> nd_rez;
	std::list<std::string> vardai;
	std::list<std::string> pavardes;
	std::list<double> galutiniai;
	std::list<double> galutiniai2;
	std::string vardas, pavarde, vardas_i, pavarde_i;
	std::string mv;
	int egzaminai;
	std::string opt;
	std::string ats;
	std::string ats2;
	std::string tn;
	std::string tn2;
	std::string failo_pav1;
	std::ifstream infile1;

	std::string failo_pav;
	std::ifstream infile;

	//Generuojami failai
	//failu_generavimas();
		
	testas("stud1000.txt", 1000, 1);
	testas("stud10000.txt", 10000, 2);
	testas("stud100000.txt", 100000, 3);
	testas("stud1000000.txt", 1000000, 4);
	testas("stud10000000.txt", 10000000, 5);

}
