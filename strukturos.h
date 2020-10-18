#ifndef STRUKTUROS_H
#define STRUKTUROS_H

#include "biblioteka.h"
#include "outputai.h"
#include "funkcijos.h"

struct informacija
{
    std::string vardai;
    std::string pavardes;
    std::vector<std::string> iverciai;
};

struct studentas
{
    std::string vardai;
    std::string pavardes;
    std::vector<int> iverciai;
};

//STRUKTURA UZDUOCIAI V0.2 VERSIJAI
struct studentas_sort
{
    std::string vardai;
    std::string pavardes;
    double vidurkiai;
    double medianos;
}; 

//STRUKTURA UZDUOCIAI V0.4 VERSIJAI
/*
struct studentai_sort {
    std::string vardai;
    std::string pavardes;
    double galutiniai;
};


struct nuskriaustieji {
    std::string vardai;
    std::string pavardes;
    double galutiniai;
};

struct galvociai {
    std::string vardai;
    std::string pavardes;
    double galutiniai;
}; */

// naudojama palyginimo funckija,kurios reikia sortui

bool compareV(studentas_sort& a, studentas_sort& b) { return a.vardai < b.vardai; };
bool compareP(studentas_sort& a, studentas_sort& b) { return a.pavardes < b .pavardes; };

#endif
