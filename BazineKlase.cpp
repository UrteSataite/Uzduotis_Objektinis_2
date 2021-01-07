#include "BazineKlase.h"

 /**
  * Konstruktorius
  */
BazineKlase::BazineKlase(std::string v, std::string p, std::vector<int> i)
{
    vec_vardai = v;
    vec_pavardes = p;
    vec_iverciai = i;
}

 /**
  * Destruktorius
  */
BazineKlase::~BazineKlase() {}

 /**
  * Operator=
  */
BazineKlase& BazineKlase::operator=(const BazineKlase& bk)
{
    vec_vardai = bk.vec_vardai;
    vec_pavardes = bk.vec_pavardes;
    vec_iverciai = bk.vec_iverciai;
    return *this;
}


