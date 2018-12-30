#ifndef DEVICE_HH_
#define DEVICE_HH_

#include <iostream>
#include <fstream>

class Device {
    std::string typ_urzadzenia;

public:
    Device();
    virtual ~Device();
    virtual void zmienParametrUrzadzenia(const int& nowa_wartosc) = 0;
    virtual void wyswietl_status() = 0;

//    friend std::ostream& operator << (std::ostream& s, Urzadzenie& urzadzenie);
};

#endif
