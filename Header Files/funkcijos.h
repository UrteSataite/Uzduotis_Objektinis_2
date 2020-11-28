#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "strukturos.h"

double gal_mediana(int egr, std::list<int> nd_rez);

double gal_rez(int egr, std::list<int> nd_rez);

std::list<double> vid_skaiciavimas(std::list<studentas> studentai);

std::list<double> med_skaiciavimas(std::list<studentas> studentai);

void testas_list(std::string failo_pav, int irasu_sk, int testas);

bool isNumber(std::string s);

#endif
