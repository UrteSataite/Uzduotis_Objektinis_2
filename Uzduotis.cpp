/* 
DOKUMENTACIJA 
v0.1 uzduotis, realizuota naudojant std::vector tipo konteineri. 
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


double gal_rez(int egr, std::vector<double> nd_rez);
double gal_mediana(int egr, std::vector<double> nd_rez);
void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai);

int main()
{
    int sk, ndr_sk, egr, tmp, tmp2;
    double galutinis1, galutinis2;

    char mv;

    std::vector<double> nd_rez;
    std::vector<std::string> vardai;
    std::vector<std::string> pavardes;
    std::vector<double> galutiniai;
    std::vector<double> galutiniai2;

    std::string vardas;
    std::string pavarde;

    std::cout << "Iveskite studentu skaiciu: \n";
    std::cin >> sk;

    if (sk > 0)
    {
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
                            if (tmp > 0 && tmp <=10 ) 
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
                            egr = rand()%max;
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
}
    else {
    std::cout << "Studentu skaicius turi buti teigiamas skaicius \n";
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

// Double funkcija, apskaiciuojanti kiekvieno studento nd pazymiu vidurki ir grazinanti galutini bala, apskaiciuota pagal salygoje nurodyta formule
double gal_rez(int egr, std::vector<double> nd_rez)
{
    double vidurkis, galutinis1;
    
    vidurkis = accumulate(nd_rez.begin(), nd_rez.end(), 0.000) / nd_rez.size();
    galutinis1 = (0.4 * vidurkis) + (0.6 * egr);

    return galutinis1;
}

// Double funkcija, apskaiciuojanti ir grazianti nd bei egzamino pazymiu mediana
double gal_mediana(int egr, std::vector<double> nd_rez)
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

// Void funkcija, spausdinanti rezulatatu lentele
void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai)
{
    std::cout << std::setw(25) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(25) << "Galutinis" << std::endl;
    std::cout << "---------------------------------------------------------------------------------\n";
    for (int i = 0; i < vardai.size(); i++) {

        std::cout << std::setw(25) << vardai.at(i) << std::setw(25) << pavardes.at(i) << std::setw(25) << galutiniai.at(i) << std::endl;

    }
}