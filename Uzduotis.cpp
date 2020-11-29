/* Programos v1.0 realizuota naudojant 2 strategija: panaudojant tik viena nauja konteineri : "vargsiukai". T.y.studentai, kuriu vidurkis yra < 5, yra perkeliami i nauja
konteineri, bei istrinami is senojo, naudojant algoritma remove_if bei erase(vektoriaus atjevu). Pastarajame lieka tik tie studentai, kuriu vidurkis yra > 5.

Projekto/programos stuktura:
* Uzduotis.cpp (main cpp failas);
* Failu generavimui: failu_generavivmas.cpp, failu_generavimas.h;
* Darbui su std::vector tipo konteineriu: funkcijos_v.cpp, funkcijos_v.h, outputai_v.cpp, outputai_v.h, sturukturos_v.h;
* Darbui su std::list tipo konteineriu: funkcijos.cpp, funkcijos.h, outputai.cpp, outputai.h, sturukturos.h;

Programos veikimo principas: 
* Varototojas pradzioje gali pasirinkti, koki konteinerio tipa nori naudoti programoje. 
* Priklausomai nuo vartotojo pasirinkimo, is pries tai sugeneruotu 5 skirtingo dydzio duomenu failu nuskaitomi duomenys ir patalpinami std::vector arba std::list. 
* Atliekami programos veikimo bei spartos testai, matuojamas laikas.
* Testo rezultatai spausdinami ekrane.

Failu generavimas:
Failai generuojami naudojant std::vector konteineri. Generavimas iskvieciamas Uzduotis.cpp faile.
(Buvo naudojami anksciau sugeneruoti failai, todel funkcijos iskvietimas uzkomentuotas)
*/

#include "funkcijos.h"
#include "outputai.h"
#include "strukturos.h"

#include "funkcijos_v.h"
#include "outputai_v.h"
#include "strukturos_v.h"

#include "failu_generavimas.h"

int main()
{
	//Generuojami failai
	//failu_generavimas();

	std::string konteineris;
	do
	{
		try {
			std::cout << "Naudoti std::list ar std::vector konteineri? L/V" << std::endl;
			std::cin >> konteineris;
			std::cout << "\n";
			if (konteineris != "L" && konteineris != "V") {
				throw std::runtime_error("Neteisingas pasirinkimas! Galima pasirinkti L(list) arba V(vector)!");
			}
		}
		catch (std::runtime_error& a) {
			std::cout << a.what() << std::endl;
			std::cout << "Jusu pasirinkimas: " << konteineris << std::endl;
			std::cout << "Pasirinkite dar karta." << std::endl;
		}
	} while (konteineris != "L" && konteineris != "V");
	
	if (konteineris == "L")
	{
		testas_list("stud1000.txt", 1000, 1);
		testas_list("stud10000.txt", 10000, 2);
		testas_list("stud100000.txt", 100000, 3);
		testas_list("stud1000000.txt", 1000000, 4);
		testas_list("stud10000000.txt", 10000000, 5);
	}
	else if (konteineris == "V")
	{
		vec_testas("stud1000.txt", 1000, 1);
		vec_testas("stud10000.txt", 10000, 2);
		vec_testas("stud100000.txt", 100000, 3);
		vec_testas("stud1000000.txt", 1000000, 4);
		vec_testas("stud10000000.txt", 10000000, 5);
	}

}
