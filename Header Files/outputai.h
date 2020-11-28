#ifndef OUTPUTAI_H
#define OUTPUTAI_H

#include "strukturos.h"

void atsp_rez(std::list<std::string> vardai, std::list<std::string> pavardes, std::list<double> galutiniai);

std::list<studentas> failo_nuskaitymas(std::string failo_pav, std::ifstream& infile);

void rasymas_i_faila_kursiokiai(std::list<studentas_sort> list, std::string failo_pav);
void rasymas_i_faila_nuskriaustieji(std::list<nuskriaustieji> nus, std::string failo_pav);
void rasymas_i_faila_galvociai(std::list<galvociai> gal, std::string failo_pav);

void failu_generavimas();

#endif
