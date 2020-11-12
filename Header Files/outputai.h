#ifndef OUTPUTAI_H
#define OUTPUTAI_H

#include "C:\Users\urte.LAPTOP-6PGCDFBJ\Desktop\3 sem\Objektinis programavimas\Uzduotis_1Dalis\Uzduotis\Header Files\strukturos.h"

void atsp_rez(std::list<std::string> vardai, std::list<std::string> pavardes, std::list<double> galutiniai);

std::list<studentas> failo_nuskaitymas(std::string failo_pav, std::ifstream& infile);

void rasymas_i_faila_kursiokiai(std::list<studentas_sort> list, std::string failo_pav);
void rasymas_i_faila_nuskriaustieji(std::vector<nuskriaustieji> nus, std::string failo_pav);
void rasymas_i_faila_galvociai(std::vector<galvociai> gal, std::string failo_pav);

void failu_generavimas();

#endif
