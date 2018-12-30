#ifndef TRANSPORT_HH_
#define TRANSPORT_HH_

#include "Robot.h"

class Transport : public Robot {
    int maks_zaladunek;

public:
    Transport();
    ~Transport();
    virtual void zmienParametrUrzadzenia(const int& nowa_wartosc);
    void wyswietl_status();

    friend std::ostream& operator << (std::ostream& s, Transport& Transport);
};

#endif
