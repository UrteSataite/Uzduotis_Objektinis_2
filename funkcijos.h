
#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H


#include "biblioteka.h"
#include "outputai.h"
#include "strukturos.h"

void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai);
std::vector<studentas> failo_nuskaitymas();
void rasymas_i_faila(std::vector<studentas_sort> stud_rus);

double gal_mediana(int egr, std::vector<int> nd_rez);

double gal_rez(int egr, std::vector<int> nd_rez);

std::vector<double> vid_skaiciavimas(std::vector<studentas> studentai);

std::vector<double> med_skaiciavimas(std::vector<studentas> studentai);

std::vector<studentas_sort> rusiavimas(std::vector<studentas> studentai, std::vector<double> vidurkiai, std::vector<double> medianos);

bool isNumber(std::string s);

#endif
