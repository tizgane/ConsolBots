#include <iostream>
#include <string>
#include <fstream>
#include "Device.h"

Device::Device() {
#ifdef _DEBUG
    std::cout << "Wywolano domyslny konstruktor Urzadzenie" << std::endl;
#endif
    typ_urzadzenia = "domyslny_typ";
}

///Zdefiniowany operator strumieniowy
//std::ostream& operator << (std::ostream& s, Urzadzenie& urzadzenie){
//s << urzadzenie.typ_urzadzenia;
//return s;
//}

Device::~Device()
{
#ifdef _DEBUG
    std::cout << "Wywolano destruktor ~Urzadzenie" << std::endl;
#endif
}
