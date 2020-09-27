/*
v0.1 uzduotis realizuota naudojant C tipo masyvus.
Buvo nukopijuota pradine programa (kurioj naudojau vektorius), perdaryta naudojant masyvus ir
sis failas ikeltas i bendra projekta. Sios programos veikimo principas yra
panasus kaip ir programos su vektoriais, tad komentarai islieka panasus 
*/

#define array_size 100

#include <iostream>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <cstring>

int nbr = 0;
int counter = 0;
int stud_sk = 0;

std::string* vrd;
std::string* pvrd;
double* gal1;
double* gal2;
double* nd_r = new double[array_size];

double gal_rez_mas(int egr, double arr[], int nbr);
double gal_mediana_mas(int egr, double arr[], int nbr);
void atsp_rez_mas(std::string vardai[], std::string pavardes[], double galutiniai[], int stud_sk);

int main()
{


    int sk, ndr_sk, egr = 0, tmp, tmp2;
    double galutinis1, galutinis2;

    std::string vardas, pavarde;

    char mv;

    std::cout << "Iveskite studentu skaiciu: \n";
    std::cin >> sk;
    vrd = new std::string[sk];
    pvrd = new std::string[sk];
    gal1 = new double[sk];
    gal2 = new double[sk];

    if (sk > 0)
    {
        for (int i = 0; i < sk; i++) {

            stud_sk = sk;

            std::cout << "Iveskite studento varda: \n";
            std::cin >> vardas;
            if (std::isdigit(vardas[i]))
            {
                std::cout << "Klaida: vardas negali buti skaicius\n";
            }
            else {

                vrd[i] = vardas;

                std::cout << "Iveskite studento pavarde: \n";
                std::cin >> pavarde;
                if (std::isdigit(pavarde[i]))
                {
                    std::cout << "Klaida: pavarde negali buti skaicius \n";
                }
                else
                {
                    pvrd[i] = pavarde;


                    std::cout << "Ar balus sugeneruoti automatiskai? (T/N) \n";
                    std::string ats;
                    std::cin >> ats;

                    if (ats == "T") {

                        while (true) {

                            int max = 10;
                            srand(time(0));
                            tmp = rand() % max;

                            std::cout << "Sugeneruotas balas:" << tmp << "\n";

                            std::cout << "Ar jau ivesti visi rezulatatai (T/N)? \n";
                            std::string tn;
                            std::cin >> tn;

                            if (tn == "T") {
                                nd_r[nbr] = tmp;
                                nbr++;

                                break;
                            }
                            else if (tn == "N")
                            {
                                nd_r[nbr] = tmp;
                                nbr++;


                            }

                        }
                    }
                    else if (ats == "N") {

                        while (true) {

                            std::cout << "Iveskite namu darbu rezultatus \n";
                            std::cin >> tmp;
                            if (tmp > 0 && tmp <= 10)
                            {

                                std::cout << "Ar jau ivesti visi rezulatatai (T/N)? \n";
                                std::string tn;
                                std::cin >> tn;

                                if (tn == "T") {
                                    nd_r[nbr] = tmp;
                                    nbr++;

                                    break;
                                }
                                else if (tn == "N")
                                {
                                    nd_r[nbr] = tmp;
                                    nbr++;

                                }
                            }
                            else {
                                std::cout << "Klaida: rezultatas turi buti pateiktas 10-baleje sistemoje.\n";
                            }
                        }
                    }
                    else
                    {
                        std::cout << "Klaida: reikia pasirinkti T arba N \n";
                    }

                    std::cout << "Ar egzamino bala sugeneruoti automatiskai? (T/N) \n";
                    std::string ats2;
                    std::cin >> ats2;

                    if (ats2 == "T")
                    {
                        int max = 10;
                        srand(time(0));
                        egr = rand() % max;
                    }
                    else if (ats2 == "N")
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
                        std::cout << "Klaida: reikia pasirinkti T arba N \n";
                    }

                    gal1[i] = gal_rez_mas(egr, nd_r, nbr);
                    gal2[i] = gal_mediana_mas(egr, nd_r, nbr);

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

        atsp_rez_mas(vrd, pvrd, gal2, stud_sk);
    }
    else
    {
        atsp_rez_mas(vrd, pvrd, gal1, stud_sk);
    }

    //Atlaisvinama atmintis
    delete[] vrd, pvrd, nd_r, gal1, gal2;
}

// Double funkcija, apskaiciuojanti kiekvieno studento nd pazymiu vidurki ir grazinanti galutini bala, apskaiciuota pagal salygoje nurodyta formule
double gal_rez_mas(int egr, double arr[], int sk)
{

    int i, sum = 0;

    for (i = 0; i < sk; ++i) {
        sum += arr[i];
    }

    return ((0.4 * (double(sum) / sk)) + (0.6 * egr));
}

// Double funkcija, apskaiciuojanti ir grazinanti nd bei egzamino pazymiu mediana
double gal_mediana_mas(int egr, double arr[], int sk)
{
    std::sort(arr, arr + sk);


    if (sk % 2 != 0)
        return (double)arr[sk / 2];

    return (double)(arr[(sk - 1) / 2] + arr[sk / 2]) / 2.0;
}

// Void funkcija, spausdinanti rezulatatu lentele
void atsp_rez_mas(std::string vardai[], std::string pavardes[], double galutiniai[], int stud_sk)
{
    std::cout << std::setw(25) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(25) << "Galutinis" << std::endl;
    std::cout << "---------------------------------------------------------------------------------\n";
    for (int i = 0; i < stud_sk; i++) {

        std::cout << std::setw(25) << vardai[i] << std::setw(25) << pavardes[i] << std::setw(25) << galutiniai[i] << std::endl;

    }
}