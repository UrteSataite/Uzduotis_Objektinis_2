#ifndef BAZINEKLASE_H_INCLUDED
#define BAZINEKLASE_H_INCLUDED

#include "strukturos_v.h"

class BazineKlase
{

public:
    BazineKlase() {};
    BazineKlase(std::string v, std::string p, std::vector<int> i);

    BazineKlase& operator=(const BazineKlase& bk);

    virtual ~BazineKlase() = 0;

    virtual const std::string &getVec_vardai() = 0;

    virtual const std::string &getVec_pavardes() = 0;

    virtual const std::vector<int> &getVec_iverciai() = 0;

    void setVec_vardai(std::string v)
    {
        vec_vardai = v;
    }

    void setVec_pavardes(std::string p)
    {
        vec_pavardes = p;
    }

    void setVec_iverciai(std::vector<int> i)
    {
        vec_iverciai = i;
    }

protected:
    std::string vec_vardai;
    std::string vec_pavardes;
    std::vector<int> vec_iverciai;

};

#endif // BAZINEKLASE_H_INCLUDED
