#ifndef ROBOT_HH_
#define ROBOT_HH_

#include <iostream>
#include <fstream>
#include <string>
#include "RobotParameters.h"
#include "RobotOperatingParameters.h"
#include "Device.h"
#include "Wheels.h"

class Robot : public Device {
    RobotOperatingParameters* parametry_pracy;
    RobotParameters* parametry_robota;
    Wheels* kola;

protected:
    std::string nazwa;

public:
    Robot();
    Robot(const int& numer_seryjny);
    virtual void wyswietl_stan();
    virtual int wyswietl_numer();
    virtual void zmienParametrUrzadzenia(const int& nowa_wartosc) = 0;
    void ruch();
    void ladowanie();
    void wymiana_kosci(const int& nowa_kosc);
    void raport();
    int wyswietl_ilosc();
    ~Robot();

    static int liczba_obiektow;
    static int poczatek_numerow;
    int numer_seryjny;

    friend bool operator == (const Robot& r1, const Robot& r2); //porownanie nr seryjnych dwoch robotow
    friend bool operator > (const Robot& r1, const Robot& r2); //porownanie nr seryjnych dwoch robotow
    friend bool operator < (const Robot& r1, const Robot& r2); //porownanie nr seryjnych dwoch robotow
    friend void operator + (Robot& r, int nowa_kosc); //dodanie  do maksymalnej ilosci pamieci
    friend void operator - (Robot& r, int nowa_kosc); // odjecie od maksymalnej ilosci pamieci
    Robot& operator=(const Robot& r); //pierwszy robot otrzymuje ten sam nr, parametry stale oraz zmienne
};

#endif
