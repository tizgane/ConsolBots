#include <string>
#include <iostream>
#include <fstream>
#include "RobotParameters.h"

using namespace std;

RobotParameters::RobotParameters()
{
#ifdef DEBUG
    cout << "Wywolano domyslny konstruktor ParametryRobota" << endl;
#endif // DEBUG

    pojemnosc_baterii = 5000;
    kosc_pamieci = 1024;
}

void RobotParameters::dodanie_kosci(const int& nowa_kosc)
{
    kosc_pamieci += nowa_kosc;
}

int RobotParameters::wyswietl_pamiec()
{
    return kosc_pamieci;
}

void RobotParameters::wyswietl_wszystko()
{
    cout << "Kosc pamieci: " << kosc_pamieci << " KB" << endl;
    cout << "Pojemnosc baterii: " << pojemnosc_baterii << " mAh" << endl;
}

RobotParameters::~RobotParameters()
{
#ifdef DEBUG
    cout << "Wywolano destruktor" << endl;
#endif // DEBUG
}
