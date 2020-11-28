#ifndef OUTPUTAI_V_H
#define OUTPUTAI_V_H

#include "strukturos_v.h"

void vec_atsp_rez(std::vector<std::string> vec_vardai, std::vector<std::string> vec_pavardes, std::vector<double> galutiniai);

std::vector<vec_studentas> vec_failo_nuskaitymas(std::string failo_pav, std::ifstream& infile);

void vec_rasymas_i_faila_kursiokiai(std::vector<vec_studentas_sort> vector, std::string failo_pav);
void vec_rasymas_i_faila_nuskriaustieji(std::vector<vec_nuskriaustieji> nus, std::string failo_pav);
void vec_rasymas_i_faila_galvociai(std::vector<vec_galvociai> gal, std::string failo_pav);

void vec_failu_generavimas();

#endif