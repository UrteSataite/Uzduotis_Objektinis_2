
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

double gal_rez(int egr, std::vector<double> nd_rez);
void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai);

int main()
{
    int sk, ndr_sk, egr, tmp;
    double galutinis;

    std::string vardas, pavarde;

    std::vector<double> nd_rez;
    std::vector<std::string> vardai;
    std::vector<std::string> pavardes;
    std::vector<double> galutiniai;

    std::cout << "Iveskite studentu skaiciu: \n";
    std::cin >> sk;
    
    std::cout << "Iveskite namu darbu rezultatu skaiciu: \n";
    std::cin >> ndr_sk;

    for (int i = 0; i < sk; i++) {
        
        std::cout << "Iveskite studento varda: \n";
        std::cin >> vardas;
        vardai.push_back(vardas);

        std::cout << "Iveskite studento pavarde: \n";
        std::cin >> pavarde;
        pavardes.push_back(pavarde);

        std::cout << "Iveskite namu darbu rezultatus \n";
        for (int i = 0; i < ndr_sk; i++) {

            std::cin >> tmp;
            nd_rez.push_back(tmp);

        }

        std::cout << "Iveskite egzamino rezultata: \n";
        std::cin >> egr;

        galutinis = gal_rez(egr, nd_rez);
        galutiniai.push_back(galutinis);

    }

    atsp_rez(vardai, pavardes, galutiniai);

}

double gal_rez(int egr, std::vector<double> nd_rez)
{
    double vidurkis, galutinis;
    
    vidurkis = accumulate(nd_rez.begin(), nd_rez.end(), 0.000) / nd_rez.size();
    galutinis = (0.4 * vidurkis) + (0.6 * egr);

    return galutinis;
}
 void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai)
    {
     std::cout << std::setw(25) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(25) << "Galutinis" << std::endl;
        std::cout << "---------------------------------------------------------------------------------\n";
        for (int i = 0; i < vardai.size(); i++) {

            std::cout << std::setw(25) << vardai.at(i) << std::setw(25) << pavardes.at(i) << std::setw(25) << galutiniai.at(i) << std::endl;

        }
}


