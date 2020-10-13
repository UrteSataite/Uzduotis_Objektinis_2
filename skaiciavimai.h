
// Double funkcija, apskaiciuojanti ir grazianti nd bei egzamino pazymiu mediana

double gal_mediana(int egr, std::vector<int> nd_rez)
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

// Double funkcija, apskaiciuojanti kiekvieno studento nd pazymiu vidurki ir grazinanti galutini bala, apskaiciuota pagal salygoje nurodyta formule

double gal_rez(int egr, std::vector<int> nd_rez)
{
    double vidurkis, galutinis1;

    vidurkis = accumulate(nd_rez.begin(), nd_rez.end(), 0.000) / nd_rez.size();
    galutinis1 = (0.4 * vidurkis) + (0.6 * egr);

    return galutinis1;
}

// naudojama palyginimo funckija,kurios reikia sortui


bool isNumber(std::string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}
