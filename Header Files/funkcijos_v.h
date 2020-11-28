#ifndef FUNKCIJOS_V_H
#define FUNKCIJOS_V_H

#include "strukturos_v.h"

double vec_gal_mediana(int egr, std::vector<int> nd_rez);

double vec_gal_rez(int egr, std::vector<int> nd_rez);

std::vector<double> vec_vid_skaiciavimas(std::vector<vec_studentas> studentai);

std::vector<double> vec_med_skaiciavimas(std::vector<vec_studentas> studentai);

void vec_testas(std::string failo_pav, int irasu_sk, int testas);

bool vec_isNumber(std::string s);

bool vec_compareV(vec_studentas_sort& a, vec_studentas_sort& b);

bool vec_compareP(vec_studentas_sort& a, vec_studentas_sort& b);

bool vec_compareAVG(vec_studentas_sort& a, vec_studentas_sort& b);

#endif
