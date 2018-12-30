#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Robot.h"

using namespace std;

int Robot::liczba_obiektow = 0;
int Robot::poczatek_numerow = 123;

Robot::Robot()
{
#ifdef DEBUG
    cout << "Wywolano domyslny konstruktor Robot" << endl;
#endif // DEBUG
    liczba_obiektow++;
    kola = new Wheels;
    numer_seryjny = poczatek_numerow++;
    parametry_robota = new RobotParameters;
    parametry_pracy = new RobotOperatingParameters;
}

Robot::Robot(const int& wpisznr)
{
#ifdef DEBUG
    cout << "Wywolano konstruktor Robot z parametrem" << endl;
#endif // DEBUG
    numer_seryjny=wpisznr;
    liczba_obiektow++;
    kola = new Wheels;
    parametry_robota = new RobotParameters;
    parametry_pracy = new RobotOperatingParameters;
}

void Robot::ruch()
{
    cout << "Robot nr " << numer_seryjny <<" poruszyl sie do przodu!" << endl;
    parametry_pracy->aktual_baterii(-(( std::rand() % 500 ) + 100 ));
    parametry_pracy->aktual_pamieci((( std::rand() % 32) + 1 ));
    parametry_pracy->aktual_czesci((( std::rand() % 3 ) + 1 ));
    wyswietl_stan();
}

void Robot::ladowanie()
{
    cout << "Robot nr " << numer_seryjny <<" zatrzymal sie, by sie zregenerowac!" << endl;
    parametry_pracy->aktual_baterii(5000);
    parametry_pracy->aktual_czesci(-100);
    parametry_pracy->stan();
}

void Robot::wyswietl_stan()
{
    parametry_pracy->stan();
}

void Robot::wymiana_kosci(const int& nowa_kosc)
{
    cout << "Wymieniono kosc pamieci robota nr: " << numer_seryjny << "!" << endl;
    cout << "Dotychczasowa max pamiec: " << parametry_robota->wyswietl_pamiec() << " KB" << endl;
    parametry_robota->dodanie_kosci(nowa_kosc);
    cout << "Max pamiec po zmianie: " << parametry_robota->wyswietl_pamiec() << " KB" << endl;
}

void Robot::raport()
{
    wyswietl_status();
    parametry_robota->wyswietl_wszystko();
    kola->parametry_kol();
    wyswietl_stan();

}

int Robot::wyswietl_ilosc()
{
    return liczba_obiektow;
}

int Robot::wyswietl_numer()
{
    return numer_seryjny;
}

// Operatory

bool operator== (const Robot& r1, const Robot& r2)
{
    //Porownywanie nr seryjnych
    if(r1.numer_seryjny == r2.numer_seryjny) {cout << "Roboty maja identyczny nr seryjny"<< endl << endl;; return true;}
    else {cout <<"Roboty roznia sie numerami seryjnymi"<< endl << endl;; return false;};
}

bool operator> (const Robot& r1, const Robot& r2)
{
    //Porownywanie nr seryjnych
    if(r1.numer_seryjny > r2.numer_seryjny) {cout << "Pierwszy robot jest mlodszy od drugiego"<< endl << endl;; return true;}
    else {cout <<"Pierwszy robot jest starszy lub rowny wiekiem drugiemu"<< endl << endl;; return false;};
}

bool operator< (const Robot& r1, const Robot& r2)
{
    //Porownywanie nr seryjnych
    if(r1.numer_seryjny < r2.numer_seryjny) {cout << "Pierwszy robot jest starszy od drugiego"<< endl << endl;; return true;}
    else {cout <<"Pierwszy robot jest mlodszy lub rowny wiekiem drugiemu"<< endl << endl; return false;};
}

void operator+ (Robot& r, int ile)
{
    r.wymiana_kosci(ile);
}

void operator- (Robot& r, int ile)
{
    r.wymiana_kosci(-ile);
}

Robot& Robot::operator=(const Robot&r)
{
    numer_seryjny=r.numer_seryjny;
    parametry_robota=r.parametry_robota;
    parametry_pracy=r.parametry_pracy;

    return* this;
}

Robot::~Robot()
{
#ifdef _DEBUG
    cout << "Wywolano destruktor Robot" << endl;
#endif // DEBUG
    liczba_obiektow--;
    delete kola;
    delete parametry_robota;
    delete parametry_pracy;
}
