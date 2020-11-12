#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "C:\Users\urte.LAPTOP-6PGCDFBJ\Desktop\3 sem\Objektinis programavimas\Uzduotis_1Dalis\Uzduotis\Header Files\strukturos.h"

double gal_mediana(int egr, std::list<int> nd_rez);

double gal_rez(int egr, std::list<int> nd_rez);

std::list<double> vid_skaiciavimas(std::list<studentas> studentai);

std::list<double> med_skaiciavimas(std::list<studentas> studentai);

std::list<studentas_sort> rusiavimas(std::list<studentas> studentai, std::list<double> vidurkiai, std::list<double> medianos);

void testas(std::string failo_pav, int irasu_sk, int testas);

bool isNumber(std::string s);


#endif
