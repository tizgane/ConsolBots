#include <iostream>
#include <string>
#include <fstream>
#include "Rover.h"

using namespace std;

string nazwa_pliku_l = "Rover.txt"; ///<Nazwa pliku do zapisu stanu obiektu

Rover::Rover()
{
#ifdef _DEBUG
    cout << "Wywolano domyslny konstruktor Rover" << endl;
#endif
    nazwa = "Rover marsjanski";
    maks_probki = 4;
    liczba_obiektow++;
}

void Rover::zmienParametrUrzadzenia(const int& nowa_wartosc) {
    maks_probki = nowa_wartosc;
}

void Rover::wyswietl_status()
{
    cout << "Numer seryjny: " << numer_seryjny << endl << "Zbiornik na probki: " << maks_probki << " probki" << endl;
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream& s, Rover& Rover) {
    cout << "------------------ PROTOKOL -----------------" << endl;
    cout << "Wyswietlam pelen protokol robota nr: " << Rover.numer_seryjny << endl;
    Rover.raport();
    cout << "---------------------------------------------" << endl;
    return s;
}

Rover::~Rover()
{
#ifdef _DEBUG
    cout << "Wywolano destruktor ~Rover" << endl;
#endif
    --liczba_obiektow;
}
