#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "strukturos_v.h"

class Studentas {

private:
    std::string vec_vardai;
    std::string vec_pavardes;
    std::vector<int> vec_iverciai;
    double vec_galutiniai_vidurkiai;
    double vec_galutiniai_medianos;

public:

    Studentas() {};
    Studentas(std::string v, std::string p, std::vector<int> i, double vid, double med);

    const std::string &getVec_vardai() {
        return vec_vardai;
    }

    const std::string &getVec_pavardes() {
        return vec_pavardes;
    }

    const std::vector<int> &getVec_iverciai() {
        return vec_iverciai;
    }

    const double &getVec_galutiniai_vidurkiai() {
        return vec_galutiniai_vidurkiai;
    }

    const double &getVec_galutiniai_medianos() {
        return vec_galutiniai_medianos;
    }

    void setVec_vardai(std::string v) {
        vec_vardai = v;
    }

    void setVec_pavardes(std::string p) {
        vec_pavardes = p;
    }

    void setVec_iverciai(std::vector<int> i) {
        vec_iverciai = i;
    }

     void setVec_galutiniai_medianos(double med) {
        vec_galutiniai_medianos = med;
    }

      void setVec_galutiniai_vidurkiai(double vid) {
        vec_galutiniai_vidurkiai = vid;
    }


};

    bool vec_compareAVG(Studentas& a, Studentas& b);
    std::vector<Studentas> vec_failo_nuskaitymas(std::string failo_pav, std::ifstream& infile);
    double vec_medianos_skaiciavimas(int egr, std::vector<int> nd_rez);
    double vec_balo_skaiciavimas(int egr, std::vector<int> nd_rez);
    std::vector<double> vec_vidurkiai_funkcija(std::vector<Studentas> studentai);
    std::vector<double> vec_medianos_funkcija(std::vector<Studentas> studentai);
    bool tryntimo_salyga(Studentas &vector);

#endif // STUDENTAS_H_INCLUDED
