
#include "funkcijos_v.h"
#include "outputai_v.h"
#include "strukturos_v.h"

#include "Studentas.h"

int main()
{
    std::cout<<"Programa realizuota naudojant klases bei std::vector konteineri." << std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"Atliekami programos spartos testai: " << std::endl;
    std::cout<<""<<std::endl;

//      vec_testas("stud1000.txt", 1000, 1);
//		vec_testas("stud10000.txt", 10000, 2);
        vec_testas("stud100000.txt", 100000, 3);
		vec_testas("stud1000000.txt", 1000000, 4);
//		vec_testas("stud10000000.txt", 10000000, 5);

}
