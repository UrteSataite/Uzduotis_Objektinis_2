#include <iostream>
#include <fstream>

int main()
{
	std::ofstream failas1;
	std::ofstream failas2;
	std::ofstream failas3;
	std::ofstream failas4;
	std::ofstream failas5;

	failas1.open("random1000.txt");

	for (int i = 0; i < 1000; i++)
	{
		failas1 << "Vardas" << i << "Pavarde" << i;
	}


}