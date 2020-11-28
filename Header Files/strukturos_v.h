#ifndef STRUKTUROS_V_H
#define STRUKTUROS_V_H

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


struct vec_studentas
{
    std::string vec_vardai;
    std::string vec_pavardes;
    std::vector<int> vec_iverciai;
};

struct vec_studentas_sort
{
    std::string vec_vardai;
    std::string vec_pavardes;
    double vec_vidurkiai;
    double vec_medianos;
};


struct vec_nuskriaustieji
{
    std::string vec_vardai;
    std::string vec_pavardes;
    double vec_iverciai;
};

struct vec_galvociai
{
    std::string vec_vardai;
    std::string vec_pavardes;
    double vec_iverciai;
};

#endif
