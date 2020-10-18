#ifndef OUTPUTAI_H
#define OUTPUTAI_H

#include "strukturos.h"

void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai);

std::vector<studentas> failo_nuskaitymas(std::string failo_pav, std::ifstream& infile);

void rasymas_i_faila_kursiokiai(std::vector<studentas_sort> vector, std::string failo_pav);
void rasymas_i_faila_nuskriaustieji(std::vector<nuskriaustieji> nus, std::string failo_pav);
void rasymas_i_faila_galvociai(std::vector<galvociai> gal, std::string failo_pav);

void failu_generavimas();

#endif
