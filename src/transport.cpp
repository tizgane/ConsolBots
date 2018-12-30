#include <iostream>
#include <string>
#include <fstream>
#include "Transport.h"

using namespace std;

string nazwa_pliku_t = "Transportowy.txt"; ///<Nazwa pliku do zapisu stanu obiektu

Transport::Transport()
{
#ifdef _DEBUG
    cout << "Wywolano domyslny konstruktor Transportowy" << endl;
#endif
    nazwa = "Robot transportowy";
    maks_zaladunek = 800;
    liczba_obiektow++;
}

void Transport::zmienParametrUrzadzenia(const int& nowa_wartosc) {
    maks_zaladunek = nowa_wartosc;
}

void Transport::wyswietl_status()
{
    cout << "Numer seryjny: " << numer_seryjny << endl <<"Typ urzadzenia: "  << nazwa << endl << "Maksymalny zaladunek: " << maks_zaladunek << " kg" << endl;
}

///Zdefiniowany operator strumieniowy
std::ostream& operator << (std::ostream& s, Transport& transport){
    cout << "------------------ PROTOKOL -----------------" << endl;
    transport.raport();
    cout << "---------------------------------------------" << endl;
    return s;
}

Transport::~Transport()
{
#ifdef _DEBUG
    cout << "Wywolano destruktor ~Transportowy" << endl;
#endif
    --liczba_obiektow;
}

