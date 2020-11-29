#ifndef FUNKCIJOS_V_H
#define FUNKCIJOS_V_H

#include "strukturos_v.h"

double vec_medianos_skaiciavimas(int egr, std::vector<int> nd_rez);

double vec_balo_skaiciavimas(int egr, std::vector<int> nd_rez);

std::vector<double> vec_vidurkiai_funkcija(std::vector<vec_studentas> studentai);

std::vector<double> vec_medianos_funkcija(std::vector<vec_studentas> studentai);

void vec_testas(std::string failo_pav, int irasu_sk, int testas);

bool vec_isNumber(std::string s);

bool vec_compareAVG(vec_studentas_sort& a, vec_studentas_sort& b);

#endif
