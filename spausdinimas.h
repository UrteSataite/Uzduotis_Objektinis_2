// funkcija spausdinanti rezultatu lentele

void atsp_rez(std::vector<std::string> vardai, std::vector<std::string> pavardes, std::vector<double> galutiniai)
{
    std::cout << std::setw(25)  << "Vardas" << std::setw(25) << "Pavarde" << std::setw(25) << "Galutinis" << std::endl;
    std::cout << "---------------------------------------------------------------------------------\n";
    for (int i = 0; i < vardai.size(); i++) {

        std::cout << std::setw(25) << vardai[i] << std::setw(25) << pavardes[i] << std::setw(25)<< std::fixed << std::setprecision(2) << galutiniai[i] << std::endl;

    }
}