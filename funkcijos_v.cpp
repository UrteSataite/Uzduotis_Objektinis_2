#include "funkcijos_v.h"
#include "strukturos_v.h"
#include "outputai_v.h"

#include "Studentas.h"

/**
 * Programos testavimo funkcija.
 */
void vec_testas(std::string failo_pav, int irasu_sk, int testas)
{
    /**
     * Patikrinama ar egzistuoja norimas testuoti failas.
     */
    std::ifstream infile(failo_pav);
    if (infile.fail())
    {
        std::cout << "KLAIDA: failas tokiu pavadinimu neegzistuoja! \n" << std::endl;
    }
    else
    {

        std::ifstream infile;

        auto startas = std::chrono::high_resolution_clock::now();

        /**
         * Failo nuskaitymas.
         */
        auto start1 = std::chrono::high_resolution_clock::now();

        std::vector<Studentas> vec_studentai = vec_failo_nuskaitymas(failo_pav, infile);

        auto end1 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end1 - start1;

        std::cout << "Failo is " << irasu_sk << " irasu nuskaitymas laikas " << diff.count() << " s\n";


        for (int i = 1; i < vec_studentai.size(); i++)
        {
            if(vec_studentai[i].getVec_galutiniai_vidurkiai() == 0)
            {
                vec_studentai[i].setVec_galutiniai_vidurkiai(vec_balo_skaiciavimas(vec_studentai[i].getVec_iverciai().back(), vec_studentai[i].getVec_iverciai()));
            }
            if(vec_studentai[i].getVec_galutiniai_medianos() == 0)
            {
                vec_studentai[i].setVec_galutiniai_medianos(vec_medianos_skaiciavimas(vec_studentai[i].getVec_iverciai().back(), vec_studentai[i].getVec_iverciai()));
            }
        }

         /**
         * Isrusiuojama didejimo tvarka.
         */
        auto start2 = std::chrono::high_resolution_clock::now();

        std::sort(vec_studentai.begin(), vec_studentai.end(), vec_compareAVG);

        auto end2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff1 = end2 - start2;

        std::cout << "Failo is " << irasu_sk << " irasu isrusiavimo didejimo tvarka laikas " << diff1.count() << " s\n";

         /**
         * Suskirstoma i dvi grupes: i nuskriaustuosius ir galvocius. Nuskriaustieji perkeliami i kita vektoriu, istrinami is studentai vektoriaus.
         */
        std::vector<vec_nuskriaustieji> vec_nus;

        auto start3 = std::chrono::high_resolution_clock::now();

        for (auto& it : vec_studentai)
        {
            if (it.getVec_galutiniai_vidurkiai() < 5)
            {
                vec_nus.push_back(vec_nuskriaustieji{ it.getVec_vardai(), it.getVec_pavardes(), it.getVec_galutiniai_vidurkiai() });
            }
        }

        vec_studentai.erase(std::remove_if(vec_studentai.begin(), vec_studentai.end(), tryntimo_salyga), vec_studentai.end());

        auto end3 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff2 = end3 - start3;

        std::cout << "Failo is " << irasu_sk << " irasu padalijimo i dvi grupes laikas " << diff2.count() << " s\n";

         /**
         * Rasymas i faila nuskriaustieji.txt
         */
        auto start4 = std::chrono::high_resolution_clock::now();
        vec_rasymas_i_faila_nuskriaustieji(vec_nus, "nuskriaustieji.txt");
        auto end4 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff3 = end4 - start4;

        std::cout << "Failo is " << irasu_sk << " Nuskriaustuju irasymo laikas " << diff3.count() << " s\n";

         /**
         * Rasymas i faila galvociai.txt
         */
        auto start5 = std::chrono::high_resolution_clock::now();
        vec_rasymas_i_faila_galvociai(vec_studentai, "galvociai.txt");
        auto end5 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff4 = end5 - start5;

        std::cout << "Failo is " << irasu_sk << " Galvociu irasymo laikas " << diff4.count() << " s\n";

        auto endas = std::chrono::high_resolution_clock::now();

         /**
         * Skaiciuojamas bendras testo laikas.
         */
        std::chrono::duration<double> diff5 = endas - startas;

        std::cout << "Failo is " << irasu_sk << " Testo nr " << testas << " rezultatas " << diff5.count() << " s\n";

        std::cout << " " << std::endl;

        vec_nus.clear();
        std::vector<vec_nuskriaustieji>().swap(vec_nus);
        vec_studentai.clear();
        std::vector<Studentas>().swap(vec_studentai);

    }

}




