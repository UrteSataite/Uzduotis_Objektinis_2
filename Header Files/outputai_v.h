#ifndef OUTPUTAI_V_H
#define OUTPUTAI_V_H

#include "strukturos_v.h"

std::vector<vec_studentas> vec_failo_nuskaitymas(std::string failo_pav, std::ifstream& infile);

void vec_rasymas_i_faila_nuskriaustieji(std::vector<vec_nuskriaustieji> nus, std::string failo_pav);
void vec_rasymas_i_faila_galvociai(std::vector<vec_studentas_sort> gal, std::string failo_pav);

#endif