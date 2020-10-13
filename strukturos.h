
// // Aprasomos trys strukturos, talpinancios ivedinamu/nuskaitomu duomenu (studentu) informacija 

struct informacija
{
    std::string vardai;
    std::string pavardes;
    std::vector<std::string> iverciai;
};

struct studentas
{
    std::string vardai;
    std::string pavardes;
    std::vector<int> iverciai;
};

struct studentas_sort
{
    std::string vardai;
    std::string pavardes;
    double vidurkiai;
    double medianos;
}; 

// naudojama palyginimo funckija,kurios reikia sortui

bool compareV(studentas_sort& a, studentas_sort& b) { return a.vardai < b.vardai; };
bool compareP(studentas_sort& a, studentas_sort& b) { return a.pavardes < b.pavardes; };

