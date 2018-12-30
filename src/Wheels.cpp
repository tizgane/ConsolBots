#include <iostream>
#include <fstream>
#include "Wheels.h"

Wheels::Wheels()
{
#ifdef DEBUG
    cout << "Wywolano domyslny konstruktor Kola" << endl;
#endif // DEBUG

    ilosc=6;
    srednica=30;
}

void Wheels::parametry_kol()
{
    std::cout << "Ilosc kol: " << ilosc << std::endl;
    std::cout << "Srednica kola: " << srednica << " cm" << std::endl;
}
