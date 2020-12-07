#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "strukturos.h"

double medianos_skaiciavimas(int egr, std::list<int> nd_rez);

double balo_skaiciavimas(int egr, std::list<int> nd_rez);

std::list<double> vidurkiai_funkcija(std::list<studentas> studentai);

std::list<double> medianos_funkcija(std::list<studentas> studentai);

void testas_list(std::string failo_pav, int irasu_sk, int testas);

bool isNumber(std::string s);

#endif
