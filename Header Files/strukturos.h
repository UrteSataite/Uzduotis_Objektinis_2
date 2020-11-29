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
#include <list>

struct studentas
{
    std::string vardai;
    std::string pavardes;
    std::list<int> iverciai;
};

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

struct CompareAvg
{
    bool operator ()(const studentas_sort& a, const studentas_sort& b)
    {
        return a.vidurkiai < b.vidurkiai;
    }
};

#endif