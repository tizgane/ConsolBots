#ifndef ROBOT_PARAMETERS_HH_
#define ROBOT_PARAMETERS_HH_

#include <string>
#include <iostream>
#include <fstream>

using std::string;

class RobotParameters {
    int pojemnosc_baterii;
    int kosc_pamieci;

public:
    RobotParameters();
    ~RobotParameters();
    void dodanie_kosci(const int& nowa_kosc);
    void wyswietl_wszystko();
    int wyswietl_pamiec();
};

#endif
