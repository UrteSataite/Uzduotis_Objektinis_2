// Biblioteka, talinanti visas programoje naudojamas bibliotekas bei aprasytus kintamuosius
#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

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

std::ofstream myfile;
std::fstream infile;

int sk, egr{}, tmp, tmp2;
std::vector<int> nd_rez;
std::vector<std::string> vardai;
std::vector<std::string> pavardes;
std::vector<double> galutiniai;
std::vector<double> galutiniai2;
std::string vardas, pavarde, vardas_i, pavarde_i;
std::string mv;
int egzaminai;
std::string opt;
std::string ats;
std::string ats2;
std::string tn;
std::string tn2;


#endif