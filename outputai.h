#ifndef OUTPUTAI_H
#define OUTPUTAI_H

#include "biblioteka.h"
#include "strukturos.h"
#include "funkcijos.h"

void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai);
std::vector<studentas> failo_nuskaitymas();
void rasymas_i_faila(std::vector<studentas_sort> stud_rus);


#endif