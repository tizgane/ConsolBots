#include <iostream>
#include <fstream>
#include "RobotOperatingParameters.h"
#include "RobotParameters.h"

using namespace std;

RobotOperatingParameters::RobotOperatingParameters()
{
#ifdef DEBUG
    cout << "Wywolano konstruktor ParametryPracyRobota" << endl;
#endif // DEBUG

    poziom_baterii = 5000;
    zajeta_pamiec = 0;
    zuzycie_czesci = 0;
}

//Funkcja wyswietlajaca stan robota
void RobotOperatingParameters::stan()
{
    cout << "Aktualny stan:" << endl;
    cout << "Zajeta pamiec: " << zajeta_pamiec << " KB" << endl;
    cout << "Poziom baterii: " << poziom_baterii << " mAh"<< endl;
    cout << "Poziom zuzycia czesci: " << zuzycie_czesci << "%" << endl;
}

//Ponizsze funkcje aktualizuja wartosci parametrow pracy robota wraz z jego ruchem/czynnosciami:
void RobotOperatingParameters::aktual_baterii(const int& zmiana_poziomu_baterii)
{
    poziom_baterii += zmiana_poziomu_baterii;
    if(poziom_baterii < 0) {poziom_baterii=0;};
    if(poziom_baterii > 5000) {poziom_baterii=5000;};
}

void RobotOperatingParameters::aktual_pamieci(const int& zmiana_zajecia_pamieci)
{
    zajeta_pamiec += zmiana_zajecia_pamieci;
}

void RobotOperatingParameters::aktual_czesci(const int& zmiana_zuzycia_czesci)
{
    zuzycie_czesci += zmiana_zuzycia_czesci;
    if (zuzycie_czesci < 0) {
        zuzycie_czesci=0;
    };
}

RobotOperatingParameters::~RobotOperatingParameters()
{
#ifdef DEBUG
    cout << "Wywolano destruktor ParametryPracyRobota" << endl;
#endif // DEBUG
}
