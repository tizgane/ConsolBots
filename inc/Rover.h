#ifndef ROVER_HH_
#define ROVER_HH_

#include "Robot.h"

class Rover : public Robot {
    int maks_probki;

public:
    Rover();
    ~Rover();
    virtual void zmienParametrUrzadzenia(const int& nowa_wartosc);
    void wyswietl_status();

    friend std::ostream& operator << (std::ostream& s, Rover& Rover);
};

#endif
