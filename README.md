@mainpage Objektinio progamavimo užduoties dokumentacija.

@author Urtė Šataitė, Duomenų mokslas, 2 kursas, 1 grupė

**[v2.0 https://github.com/UrteSataite/Uzduotis_Objektinis_2/releases/tag/v2.0](https://github.com/UrteSataite/Uzduotis_Objektinis_2/releases/tag/v2.0)**

**Sukurta v1.5 projekto dokumentacija**, naudojant [Doxygen](https://www.doxygen.nl/index.html) .
Dokumentacija kurta v1.5 projektui. Kodas pakeistas tik papildomais komentarais, kuriuos suprastu doxygen.

Taip pat pakeistas README.md failas, kurio pagrindu kurtas dokumentacijos pagrindinis puslapis.

**v1.5 projektui atlikti Unit Test'ai**, naudojant testavimo biblioteka Boost. Testuojamos dvi skaiciavimo funckijos: 
	+ 'vec_medianos_skaiciavimas()'
	+ 'vec_balo_skaiciavimas()'

Testai atlikti naudojant CodeBlocks.

*Testų ir jų rezultatų ekrano iškarpos įkeltos į github.*

**Testu rezultatai:**

**Kodas test.cpp faile:**

    #define BOOST_TEST_DYN_LINK
    #define BOOST_TEST_MODULE Hello
    #include <boost/test/included/unit_test.hpp>
    #include <Studentas.h>


    BOOST_AUTO_TEST_CASE(medianosTestas)
    {
    	BOOST_CHECK(vec_medianos_skaiciavimas(8,{5,6,8,7}) == 7);
    }

    BOOST_AUTO_TEST_CASE(baloTestas)
    {
	    BOOST_CHECK(vec_balo_skaiciavimas(8,{5,6,7,8}) == 7.4);
    }

**Į ekraną išvestas rezultas:**

	> Running 2 test cases...

	> No errors detected
	
**Kodas test.cpp faile:**

    #define BOOST_TEST_DYN_LINK
    #define BOOST_TEST_MODULE Hello
    #include <boost/test/included/unit_test.hpp>
    #include <Studentas.h>

    BOOST_AUTO_TEST_CASE(medianosTestas)
    {
	    BOOST_CHECK(vec_medianos_skaiciavimas(8,{5,6,8,7}) == 5);
    }

    BOOST_AUTO_TEST_CASE(baloTestas)
    {
	    BOOST_CHECK(vec_balo_skaiciavimas(8,{5,6,7,8}) == 8);
    }

**Į ekraną išvestas rezultas:**

	> Running 2 test cases...
	> C:/Users/urte.LAPTOP-6PGCDFBJ/Desktop/3 sem/Objektinis programavimas/Darbine_Aplinka/UnitTesting/test.cpp(9): error: in "medianosTestas": check vec_medianos_skaiciavimas(8,{5,6,8,7}) == 5 has failed
	> C:/Users/urte.LAPTOP-6PGCDFBJ/Desktop/3 sem/Objektinis programavimas/Darbine_Aplinka/UnitTesting/test.cpp(14): error: in "baloTestas": check vec_balo_skaiciavimas(8,{5,6,7,8}) == 8 has failed

	> 2 failures are detected in the test module "Hello"


**[v1.5 https://github.com/UrteSataite/Uzduotis_Objektinis_2/releases/tag/v1.5] (https://github.com/UrteSataite/Uzduotis_Objektinis_2/releases/tag/v1.5)**

*Pakeista programos struktūra, t.y. atsisakyta galimybės vartotojui leisti pasirinkti std::list konteinerį. Taip pat iš projekto panaikintas failų generavimas.*

Studentas klasei sukurta bazinė abstrakčioji klasė (BazineKlase), kurioje aprašomas žmogus. Šiam žmogui aprašyti nuspręsta naudoti iš duomenų failo skaitomus duomenis, t.y. vardus, pavardes, bei įverčius. Šią klasę paveldi Studentas, kurios pagalba yra atliekamos visos funkcijos bei metodai, tokie kaip duomenų nuskaitymas, rūšiavimas, medianos/vidurkių skaičiavimas ir t.t.

**v1.5 projektą sudaro:**

  **- Penki .h failai:**
    + "BazineKlase.h", kuriame aprasyta abstrakcioji bazine klase BazineKlase, kuria paveldi klase Studentas;
 	+ "Studentas.h", kuriame aprasyta Studentas klase, inicijuojamos funkcijos darbui su sios klases objektais;
 	+ "funkcijos_v.h", kuriame inicijuojama programos spartos testo funckija;
 	+ "outputai_v.h", skirtas inicijuoti isvedimu i failus funkcijas;
 	+ "struktus_v", kuriame nurodomos naudojamos bibliotekos, aprasyta viena struktura vec_nuskriastieji;

  **- Penki .cpp failai:**
 	+ "Uzduotis.cpp", kuriame yra main funckija, iskvieciamas spartos testas;
 	+ "BazineKlase.cpp", kurioje yra bazines klases BazineKlase konstruktoriaus, destruktoriaus ir operator= realizacijos;
 	+ "Studentas.cpp", kuriame realizuotos visos funckijos darbui su klase Studentas, taip pat konstruktorius ir operator=;
 	+ "funkcijos_v.cpp", kuriame realizuojama vienintele programos spartos testo funckija vec_testas();
    + "outputai_v.cpp", kuriame realizuojamos dvi isvedimo i skirtingus failus funkcijos: vec_rasymas_i_faila_nuskriaustieji() ir vec_rasymas_i_faila_galvociai();

**[v1.2 https://github.com/UrteSataite/Uzduotis_Objektinis_2/releases/tag/v1.2] (https://github.com/UrteSataite/Uzduotis_Objektinis_2/releases/tag/v1.2)**

*"Rule of three" realizacija. Pakeisti failai Studentas.h bei Studentas.cpp.

Pridėtas destruktorius ir operator=. Copy constructor nėra realizuojamas.

**[v1.1 https://github.com/UrteSataite/Uzduotis_Objektinis_2/releases/tag/v1.1](https://github.com/UrteSataite/Uzduotis_Objektinis_2/releases/tag/v1.1)**

*Nuo v1.1 vietoje Visual Studio pradėtas naudoti CodeBlocks.*

Programos spartos testai atliekami naudojant **std::vector konteinerį** ir **v1.0 versijoje realizuotą 2 strategiją**.

Prieš pakeičiant Studnetas struktūra į Studentas klasę, buvo atlikti pakeitimai v1.0 kode: prieš tai buvusios 2 atskiros Studentas ir Studentas_sort struktūros pertvarkytos į vieną Studentas struktūrą. Todėl iš naujo alikti programos veikimo sportos testai. **Gauti tokie rezultatai**:

> Failo iš 100000 įrašų nuskaitymo laikas 0.510672 s

> Failo iš 100000 įrašų išrūšiavimo didėjimo tvarka laikas 0.0482478 s

> Failo iš 100000 įrašų padalijimo į dvi grupes laikas 0.133969 s

> Failo iš 100000 Nuskriaustūjų įrašymo laikas 0.161028 s

> Failo iš 100000 Galvociu įrašymo laikas 0.164556 s 

> Failo iš 100000 Testo nr 1 rezultatas 0.986057 s


> Failo iš 1000000 įrašų nuskaitymo laikas 5.07314 s

> Failo iš 1000000 įrašų išrūšiavimo didėjimo tvarka laikas 0.524049 s

> Failo iš 1000000 įrašų padalijimo į dvi grupes laikas 0.127039 s

> Failo iš 1000000 Nuskriaustūjų įrašymo laikas 1.12045 s

> Failo iš 1000000 Galvociu įrašymo laikas 1.42357 s 

> Failo iš 1000000 Testo nr 1 rezultatas 8.96883 s


**Programos veikimo spartos testo rezultatai, pakeitus struktūrą į klasę:**

> Failo iš 100000 įrašų nuskaitymo laikas 0.421333 s

> Failo iš 100000 įrašų išrūšiavimo didėjimo tvarka laikas 0.781074 s

> Failo iš 100000 įrašų padalijimo į dvi grupes laikas 0 s

> Failo iš 100000 Nuskriaustūjų įrašymo laikas 0.0937261 s

> Failo iš 100000 Galvociu įrašymo laikas 0.0937295 s 

> Failo iš 100000 Testo nr 1 rezultatas 0.73376 s


> Failo iš 1000000 įrašų nuskaitymo laikas 4.2021 s

> Failo iš 1000000 įrašų išrūšiavimo didėjimo tvarka laikas 0.999765 s

> Failo iš 1000000 įrašų padalijimo į dvi grupes laikas 0.0781066 s

> Failo iš 1000000 Nuskriaustūjų įrašymo laikas 0.843552 s

> Failo iš 1000000 Galvociu įrašymo laikas 0.937279 s 

> Failo iš 1000000 Testo nr 1 rezultatas 7.51381 s


Toliau matomi rezultatai, atlikus programos spartos testus, pakeitus kompiliatoriaus optimizavimo lygį, nurodomą per flag'us: O1, O2, O3:

**Naudojant O1 (Optimize more(for speed)):**

> Failo iš 100000 įrašų nuskaitymo laikas 0.437453 s

> Failo iš 100000 įrašų išrūšiavimo didėjimo tvarka laikas 0.0312434 s

> Failo iš 100000 įrašų padalijimo į dvi grupes laikas 0.0156206 s

> Failo iš 100000 Nuskriaustūjų įrašymo laikas 0.0937312 s

> Failo iš 100000 Galvociu įrašymo laikas 0.0937228 s 

> Failo iš 100000 Testo nr 1 rezultatas 0.7342 s


> Failo iš 1000000 įrašų nuskaitymo laikas 4.17093 s

> Failo iš 1000000 įrašų išrūšiavimo didėjimo tvarka laikas 0.374931 s

> Failo iš 1000000 įrašų padalijimo į dvi grupes laikas 0.124949 s

> Failo iš 1000000 Nuskriaustūjų įrašymo laikas 0.943609 s

> Failo iš 1000000 Galvociu įrašymo laikas 1.14247 s 

> Failo iš 1000000 Testo nr 1 rezultatas 7.2099 s


**Naudojant O2 (Optimize even more (for speed))**

> Failo iš 100000 įrašų nuskaitymo laikas 0.40584 s

> Failo iš 100000 įrašų išrūšiavimo didėjimo tvarka laikas 0.0312447 s

> Failo iš 100000 įrašų padalijimo į dvi grupes laikas 0 s

> Failo iš 100000 Nuskriaustūjų įrašymo laikas 0.109349 s

> Failo iš 100000 Galvociu įrašymo laikas 0.0937306 s 

> Failo iš 100000 Testo nr 1 rezultatas 0.718272 s


> Failo iš 1000000 įrašų nuskaitymo laikas 4.23337 s

> Failo iš 1000000 įrašų išrūšiavimo didėjimo tvarka laikas 0.390495 s

> Failo iš 1000000 įrašų padalijimo į dvi grupes laikas 0.125023 s

> Failo iš 1000000 Nuskriaustūjų įrašymo laikas 0.843499 s

> Failo iš 1000000 Galvociu įrašymo laikas 1.01538 s 

> Failo iš 1000000 Testo nr 1 rezultatas 7.12531 s 


**Naudojant O3 (Optimize fully (for speed))**

> Failo iš 100000 įrašų nuskaitymo laikas 0.421775 s

> Failo iš 100000 įrašų išrūšiavimo didėjimo tvarka laikas 0.046867 s

> Failo iš 100000 įrašų padalijimo į dvi grupes laikas 0.015622 s

> Failo iš 100000 Nuskriaustūjų įrašymo laikas 0.0781041 s

> Failo iš 100000 Galvociu įrašymo laikas 0.109348 s 

> Failo iš 100000 Testo nr 1 rezultatas 0.718578 s


> Failo iš 1000000 įrašų nuskaitymo laikas 4.12407 s

> Failo iš 1000000 įrašų išrūšiavimo didėjimo tvarka laikas 0.453019 s

> Failo iš 1000000 įrašų padalijimo į dvi grupes laikas 0.124975 s

> Failo iš 1000000 Nuskriaustūjų įrašymo laikas 0.843581 s

> Failo iš 1000000 Galvociu įrašymo laikas 0.937303 s 

> Failo iš 1000000 Testo nr 1 rezultatas 6.99841 s 


**Išvados:**
- Greičiausiai nuskaitytas 100 tūkst. duomenų failas, naudojant O2 (O2 ir O3 skirtumas ~ 0.02s).
- Greičiausiai nuskaitytas 1 mln. duomenų failas, naudojant O3 (O3 ir O1 skirtumas ~ 0.05s).
- Failo iš 1 mln įrašų dalijimo trukmė labai panaši naudojant visus flag'us (skirtumas tarp O1 ir O3 vos 0.000026 s).
- Duomenų įrašymo į 2 failus: Nuskriaustieji.txt ir Galvociai.txt laikas greičiausias naudojant O3 flag'ą.
- Visas testas atliekamas greičiausiai naudojant O3 flag'ą.

**[v1.0 https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v1.0](https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v1.0)**

**Galutinės versijos veikimo principas:**
- Sugeneruojami 5 .txt failai, talpinantys studentų duomenis;
- Vartotojas tuomet gali pasirinkti, kurį konteinerio tipą naudoti;
- Studentai padalijami į dvi grupes jų pagal galutinį balą. Nauji sąrašai yra išvedami į atitinkamus .txt failus;
- Atliekami programos spartos testai kiekvienam failui. Testo rezultatus vartotojas mato ekrane;


#### Projekto stuktūra:
- Uzduotis.cpp (main cpp failas);
- Failų generavimui: failu_generavivmas.cpp, failu_generavimas.h;
- Darbui su std::vector tipo konteineriu: funkcijos_v.cpp, funkcijos_v.h, outputai_v.cpp, outputai_v.h, sturukturos_v.h;
- Darbui su std::list tipo konteineriu: funkcijos.cpp, funkcijos.h, outputai.cpp, outputai.h, sturukturos.h;

Patobulinta programa, vartotojas gali pasirinkti, kokį konteinerio tipą: std:vector ar std::list nori naudoti. Programa veikia sklandžiau, kodas atrodo švaresis. Taip pat į naują .cpp failą iškeltas failų generavimas. Dėl to pasikeičia projekto struktūra.
Optimizuota studentų dalijimo į dvi grupes realizacija pagal 2 strategiją: panaudojamas tik vienas naujas konteineris (tipas priklauso nuo vartotojo pasirinkimo), skirtas talpinti studentų, kurių galutinis balas < 5.0, duomenis. 
Atlikti programos spartos testai, skirti palyginti ne tik skirtingų konteinerių, bet ir skirtingų dalijimo į dvi grupes būtų veikimą. Testų rezultatai pateikiami nuotraukose. 

*Svarbu paminėti, jog didelio atminties sunaudojimo bandoma išvendti naudojant swap() funkciją. Be šios funkcijos iškyla problemų dėl atminties, kurių paprastas clear() nesutvarko.*

#### 1 strategija

Programos spartos testo rezultatai (su 10 milijonų failu) bei programos metu naudojamos atminties bei CPU rodmenys, naudojant **std::vector** tipo konteinerį.

> Failo iš 10000000 įrašų nuskaitymo laikas 42.4775 s

> Failo iš 10000000 įrašų išrūšiavimo didėjimo tvarka laikas 1.23897 s

> Failo iš 10000000 įrašų padalijimo į dvi grupes laikas 1.39399 s

> Failo iš 10000000 Nuskriaustūjų įrašymo laikas 6.04084 s

> Failo iš 10000000 Galvociu įrašymo laikas 5.98747 s 

> Failo iš 10000000 Testo nr 1 rezultatas 64.3153 s


Programos metu sunaudojama atmintis: 4GB.

Programos spartos testo rezultatai (su 10 milijonų failu) bei programos metu naudojamos atminties bei CPU rodmenys, naudojant std::list tipo konteinerį.

> Failo iš 10000000 įrašų nuskaitymo laikas 46.5075 s

> Failo iš 10000000 įrašų išrūšiavimo didėjimo tvarka laikas 10.5413 s

> Failo iš 10000000 įrašų padalijimo į dvi grupes laikas 3.06114 s

> Failo iš 10000000 Nuskriaustūjų įrašymo laikas 8.62982 s

> Failo iš 10000000 Galvociu įrašymo laikas 7.48226 s 

> Failo iš 10000000 Testo nr 1 rezultatas 85.4523 s


Programos metu sunaudojama atmintis: 6GB.

**1 strategijos išvados:**
- Šis realizavimo būdas užima daug atminties: naudojant std::vector užimama atmintis sieka 4 GB, tuo tarpu naudojant std::list, užimama atmintis sieka net 6 GB;
- Failo iš 10 milijonų įrašų padalijimas į dvi grupes, naudojant std::vector užtunka 1.39s, o std::list 3.06s;

#### 2 strategija

Programos spartos testo rezultatai (su 10 milijonų failu) bei programos metu naudojamos atminties bei CPU rodmenys, naudojant **std::vector** tipo konteinerį.

> Failo iš 10000000 įrašų nuskaitymo laikas 42.47794 s

> Failo iš 10000000 įrašų išrūšiavimo didėjimo tvarka laikas 1.24096 s

> Failo iš 10000000 įrašų padalijimo į dvi grupes laikas 0.838024 s

> Failo iš 10000000 Nuskriaustūjų įrašymo laikas 6.36926 s

> Failo iš 10000000 Galvociu įrašymo laikas 6.43967 s 

> Failo iš 10000000 Testo nr 1 rezultatas 64.8801 s


Programos metu sunaudojama atmintis: 3GB.

Programos spartos testo rezultatai (su 10 milijonų failu) bei programos metu naudojamos atminties bei CPU rodmenys, naudojant **std::list** tipo konteinerį.

> Failo iš 10000000 įrašų nuskaitymo laikas 51.3205 s

> Failo iš 10000000 įrašų išrūšiavimo didėjimo tvarka laikas 10.7792 s

> Failo iš 10000000 įrašų padalijimo į dvi grupes laikas 3.66386 s

> Failo iš 10000000 Nuskriaustūjų įrašymo laikas 7.38802 s

> Failo iš 10000000 Galvociu įrašymo laikas 8.97813 s 

> Failo iš 10000000 Testo nr 1 rezultatas 92.5054 s


Programos metu sunaudojama atmintis: 5GB.

**2 strategijos išvados:**
- Šis realizavimo būdas yra kur kas efektyvesnis dėl atminties naudojimo: naudojant std::vector užimama atmintis siekia 3 GB, o naudojant std::list 5 GB, t.y. 1 GB mažiau, negu sunaudoja programa, atilikta pagal pirmąją strategiją;
- Naudojant std::vector, failo iš 10 milijonų įrašų padalijimas į dvi grupes užtrunka 0.84s, tuo tarpu naudojant std::list užtunka 3.66s;

**[v0.5 https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.5](https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.5)**

Atliekamas dviejų tipų konteinerių testavimas su 5 skirtingais failas:
- iš 1000 įrašų (stud1000.txt)
- iš 10000 įrašų (stud10000.txt)
- iš 100000 įrašų (stud100000.txt)
- iš 1000000 įrašų (stud1000000.txt)
- iš 10000000 įrašų (stud10000000.txt)

Matuojamas laikas, pateikiami testavimo sistemos paramterai, vykdant:
- Duomenų nuskaitymą iš failo
- Duomenų suskirstymą į 2 grupes

#### Testo rezultatai, naudojant std:vector<> konteinerį:

> Failo iš 1000 įrašų nuskaitymo laikas 0.0048294 s

> Failo iš 1000 įrašų išrūšiavimo didėjimo tvarka laikas 0.000118 s

> Failo iš 1000 įrašų padalijimo į dvi grupes laikas 0.0001377 s


> Failo iš 10000 įrašų nuskaitymo laikas 0.0437696 s

> Failo iš 10000 įrašų išrūšiavimo didėjimo tvarka laikas 0.0010522 s

> Failo iš 10000 įrašų padalijimo į dvi grupes laikas 0.0011707 s


> Failo iš 100000 įrašų nuskaitymo laikas 0.550995 s

> Failo iš 100000 įrašų išrūšiavimo didėjimo tvarka laikas 0.0111981 s

> Failo iš 100000 įrašų padalijimo į dvi grupes laikas 0.0140781 s


> Failo iš 1000000 įrašų nuskaitymo laikas 5.04061 s

> Failo iš 1000000 įrašų išrūšiavimo didėjimo tvarka laikas 0.11654 s

> Failo iš 1000000 įrašų padalijimo į dvi grupes laikas 0.167933 s


> Failo iš 10000000 įrašų nuskaitymo laikas 42.8342 s

> Failo iš 10000000 įrašų išrūšiavimo didėjimo tvarka laikas 1.28417 s

> Failo iš 10000000 įrašų padalijimo į dvi grupes laikas 1.60707 s


Programos metu naudojama atmintis: 4GB.

#### Testo rezultatai, naudojant std:list<> konteinerį:

> Failo iš 1000 įrašų nuskaitymo laikas 0.0055334 s

> Failo iš 1000 įrašų išrūšiavimo didėjimo tvarka laikas 6.57e-05 s

> Failo iš 1000 įrašų padalijimo į dvi grupes laikas 0.0001412 s


> Failo iš 10000 įrašų nuskaitymo laikas 0.0488351 s

> Failo iš 10000 įrašų išrūšiavimo didėjimo tvarka laikas 0.0037388 s

> Failo iš 10000 įrašų padalijimo į dvi grupes laikas 0.0023535 s


> Failo iš 100000 įrašų nuskaitymo laikas 0.685207 s

> Failo iš 100000 įrašų išrūšiavimo didėjimo tvarka laikas 0.042569 s

> Failo iš 100000 įrašų padalijimo į dvi grupes laikas 0.0215335 s


> Failo iš 1000000 įrašų nuskaitymo laikas 6.3742 s

> Failo iš 1000000 įrašų išrūšiavimo didėjimo tvarka laikas 0.584031 s

> Failo iš 1000000 įrašų padalijimo į dvi grupes laikas 0.185873 s


> Failo iš 10000000 įrašų nuskaitymo laikas 47.2911 s

> Failo iš 10000000 įrašų išrūšiavimo didėjimo tvarka laikas 10.6117 s

> Failo iš 10000000 įrašų padalijimo į dvi grupes laikas 2.79924 s


Programos metu naudojama atmintis: 5GB.

#### Išvados:
- Programa, kurioje naudojami std::vector<> tipo konteineriai, veikia greičiau nuskaitant failus (matomas 5-7 sekundžių skirtumas);
- Programa, kurioje naudojami std::vector<> tipo konteineriai, vykdymo procese taip pat sunaudoja mažiau atminties (1 GB skirtumas);

**[v0.4 https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.4](https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.4)**

Sutvarkyta, patobulinta programa. Funkcijos iškeltos į kitus failus. 
Taip pat realizuojamas penkių skirtingų dydžių failų generavimas. 
Studentai išrūšiuojami į dvi grupes: kurių galutinis balas < 5.0 ir kurių galutinis balas >= 5.0. Tam sukuriamos 2 naujos struktūros.
Šių skirtingų grupių studentų duomenys išvedami į skirtingus .txt failus: "nuskriaustieji.txt" ir "galvociai.txt".
Atliktas programos spartos testas (releaso metu buvo nebaigtas). 

Testo rezultatai:

> Failo iš 1000 įrašų nuskaitymo laikas 0.0001657 s

> Failo iš 1000 įrašų išrūšiavimo didėjimo tvarka laikas 4e-06 s

> Failo iš 1000 įrašų padalijimo į dvi grupes laikas 4e-07 s

> Failo iš 1000 Nuskriaustūjų įrašymo laikas 0.0003684 s

> Failo iš 1000 Galvociu įrašymo laikas 0.0003484 s 

> Failo iš 1000 Testo nr 1 rezultatas 0.99562 s


> Failo iš 10000 įrašų nuskaitymo laikas 0.000237 s

> Failo iš 10000 įrašų išrūšiavimo didėjimo tvarka laikas 3.3e-06 s

> Failo iš 10000 įrašų padalijimo į dvi grupes laikas 6e-07 s

> Failo iš 10000 Nuskriaustūjų įrašymo laikas 0.0004246 s

> Failo iš 10000 Galvociu įrašymo laikas 0.0003571 s 

> Failo iš 10000 Testo nr 1 rezultatas 0.0055667 s


#### Projekto struktūra:
- funckijos.h
- outputai.h
- strukturos.h 
- funckijos.cpp
- outputai.cpp
- Uzduotis.cpp

**[v0.3 https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.3](https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.3)**

Programoje naudojamos funkcijos, struktūros, bibliotekos bei naudojami aprašyti kintamieji iškelti į pagalbinius header failus. Taip pat programoje panaudotas išimčių valdymas (angl. Exception Handling).

#### Projekto struktūra:
- biblioteka.h
- skaiciavimai.h
- spausdinimas.h
- strukturos.h
- Uzduotis.cpp

**[v0.2 https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.2](https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.2)**

v.01 versija papildyta duomenų nuskaitymu iš .txt failo bei išvedimu į .txt failą. Duomenis pradedami talpinti į struktūras.

#### v0.2 veikimo principas:
- Vartotojas paklausiamas, ar nori įvesti duomenis, ar nuskaityti iš failo;
- Vartotojui pasirinkus duomenų nuskaitymą iš failo, rezultatai yra išvedami į failą, prieš tai jam pasirinkus, pagal ką rūšiuoti studentus: vardus ar pavardes;

#### Programoje realizuotos tos pačios 3 funkcijos, kaip ir v0.1.

**[v0.1 https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.1](https://github.com/UrteSataite/Uzduotis_Objektinis/releases/tag/v0.1)**

#### v0.1 veikimo principas:
- Vartotojas įveda norimą studentų skaičių bei tų studentų duomenis: vardus, pavardes;
- Vartotojui pateikiama galimybė sugeneruoti tiek namų darbų rezultatus, tiek egzamino rezultatus;
- Vedami/generuojami balai tol, kol vartotojas nusprendžia sustoti;
- Vartotojas pasirenka, rodyti studentų pažymių medianas ar vidurkius;

#### Programoje realizuotos trys funckijos:
- Medianos skaičiavimas;
- Vidurkio skaičiavimas;
- Spausdinimas į ekraną;

Atskirame .cpp faile užduotis atlikta naujant C masyvą.
