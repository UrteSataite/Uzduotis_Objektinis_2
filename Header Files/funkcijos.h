#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "strukturos.h"

double gal_mediana(int egr, std::vector<int> nd_rez);

double gal_rez(int egr, std::vector<int> nd_rez);

std::vector<double> vid_skaiciavimas(std::vector<studentas> studentai);

std::vector<double> med_skaiciavimas(std::vector<studentas> studentai);

std::vector<studentas_sort> rusiavimas(std::vector<studentas> studentai, std::vector<double> vidurkiai, std::vector<double> medianos);

void testas(std::string failo_pav, int irasu_sk, int testas);

bool isNumber(std::string s);

bool compareV(studentas_sort& a, studentas_sort& b);

bool compareP(studentas_sort& a, studentas_sort& b);

bool compareAVG(studentas_sort& a, studentas_sort& b);

#endif
