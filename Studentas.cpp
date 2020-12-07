    #include "Studentas.h"

    Studentas::Studentas(std::string v, std::string p, std::vector<int> i, double vid, double med) {
        vec_vardai = v;
        vec_pavardes = p;
        vec_iverciai = i;
        vec_galutiniai_vidurkiai = vid;
        vec_galutiniai_medianos = med;
    }

    Studentas& Studentas::operator=(const Studentas& st) {
        if (&st == this) return *this;
    }

    // Funkcijos, reikalingos sort veikimui. Palyginami vidurkiai.
    bool vec_compareAVG(Studentas& a, Studentas& b) { return a.getVec_galutiniai_vidurkiai() < b.getVec_galutiniai_vidurkiai(); };
    // Trynimo is vektoriaus studentai salyga
    bool tryntimo_salyga(Studentas& vector)
    {
        return vector.getVec_galutiniai_vidurkiai() < 5;
    }
    // Duomenu is failo skaitumo patikrinimas
    bool vec_isNumber(std::string s)
    {
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i]) == false)
                return false;

        return true;
    }

    // Funkcija, nuskaitanti duomenis is failo i vektoriu
    std::vector<Studentas> vec_failo_nuskaitymas(std::string failo_pav, std::ifstream& infile)
    {
        std::vector<Studentas> vec_studentai;

        std::string vardas_i, pavarde_i, vardas, pavarde;

        std::vector<int> patikrinti;

        int rows = 0, cols = 0;
        std::string eilute, reiksme;

        infile.open(failo_pav);

        // while ciklas skirtas suzinoti, kiek failas turi eiluciu ir stulpeliu
        while (std::getline(infile, eilute)) {
            rows++;
            if (rows == 1)
            {
                std::stringstream ss(eilute);
                while (ss >> reiksme)
                    cols++;
            }
        }
        infile.close();
        infile.open(failo_pav);

        std::string rez;
        std::vector<std::string> visi_rezultatai;

        std::getline(infile, eilute);

        // nuskaitoma likusi dokumento dalis (be etikeciu, tik duomenys)
        for (int i = 1; i < rows; i++)
        {
            infile >> vardas >> pavarde;

            for (int j = 0; j < cols - 2; j++)
            {
                infile >> rez;
                visi_rezultatai.push_back(rez);

                for (int i = 0; i < visi_rezultatai.size(); i++)
                {
                    if (!vec_isNumber(visi_rezultatai[i]))
                    {
                        std::cout << "Klaida: faile rezultatu vietose yra raides! \n";
                    }
                    else
                    {
                        patikrinti.push_back(std::stoi(visi_rezultatai[i]));
                    }
                    visi_rezultatai.clear();
                    std::vector<std::string>().swap(visi_rezultatai);
                }
            }

            Studentas stud;

            stud.setVec_vardai(vardas);
            stud.setVec_pavardes(pavarde);
            stud.setVec_iverciai(patikrinti);
            stud.setVec_galutiniai_medianos(0);
            stud.setVec_galutiniai_vidurkiai(0);

            vec_studentai.push_back(stud);

            patikrinti.clear();
            std::vector<int>().swap(patikrinti);
        }
        infile.close();
        std::cout<<vec_studentai.size()<<std::endl;


        return vec_studentai;
    }

    // Funkcija, skaiciuojanti galutines medianos reiksmes
    double vec_medianos_skaiciavimas(int egr, std::vector<int> nd_rez)
    {
        std::vector<double> eilute;
        for (int i = 0; i < nd_rez.size(); i++) {
            eilute.push_back(nd_rez.at(i));
        }

        eilute.push_back(egr);

        std::sort(eilute.begin(), eilute.end());

        if (eilute.size() % 2 == 0)
        {
            return (eilute[eilute.size() / 2 - 1] + eilute[eilute.size() / 2]) / 2;
        }
        else
        {
            return eilute[eilute.size() / 2];
        }
    }

    // Funkcija, skaiciuojanti vidurki ir galutini bala
    double vec_balo_skaiciavimas(int egr, std::vector<int> nd_rez)
    {
        double vidurkis, galutinis1;

        vidurkis = accumulate(nd_rez.begin(), nd_rez.end(), 0.000) / nd_rez.size();
        galutinis1 = (0.4 * vidurkis) + (0.6 * egr);

        return galutinis1;
    }

    // Funckija, irasanti vidurkiu reiksmes studentams
    std::vector<double> vec_vidurkiai_funkcija(std::vector<Studentas>& studentai)
    {

        std::vector<double> vec_vidurkiai;
        for (int i = 0; i < studentai.size(); i++)
        {
            std::cout << "Skaiciuojamas vidurkis \n";
            vec_vidurkiai.push_back(vec_balo_skaiciavimas(studentai[i].getVec_iverciai().back(), studentai[i].getVec_iverciai()));
        }
        return vec_vidurkiai;
    }

    // Funckija, irasanti medianos reiksmes studentams
    std::vector<double> vec_medianos_funkcija(std::vector<Studentas> studentai)
    {
        std::vector<double> vec_medianos;
        for (int i = 0; i < studentai.size(); i++)
        {
            std::cout << "Skaiciuojama mediana \n";
            vec_medianos.push_back(vec_medianos_skaiciavimas(studentai[i].getVec_iverciai().back(), studentai[i].getVec_iverciai()));
        }
        return vec_medianos;
    }
