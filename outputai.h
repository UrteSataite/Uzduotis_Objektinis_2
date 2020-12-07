#ifndef OUTPUTAI_H
#define OUTPUTAI_H

#include "strukturos.h"

std::list<studentas> failo_nuskaitymas(std::string failo_pav, std::ifstream& infile);

void rasymas_i_faila_nuskriaustieji(std::list<nuskriaustieji> nus, std::string failo_pav);
void rasymas_i_faila_galvociai(std::list<studentas_sort> gal, std::string failo_pav);

#endif
