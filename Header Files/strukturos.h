#ifndef STRUKTUROS_H
#define STRUKTUROS_H

#include <type_traits>
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <sstream> 
#include <random>
#include <chrono>


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


struct nuskriaustieji
{
    std::string vardai;
    std::string pavardes;
    double iverciai;
};

struct galvociai
{
    std::string vardai;
    std::string pavardes;
    double iverciai;
};

#endif