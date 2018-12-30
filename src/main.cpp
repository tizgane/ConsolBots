#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Robot.h"
#include "Rover.h"
#include "Transport.h"
//#define DEBUG

using namespace std;

void validity()
{
    system("cls");
    cout << "Dzialanie nieprawidlowe." << endl;
    cin.clear();
    cin.ignore();
    fflush(stdin);
    cout << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
    cin.get();
}

void test(Robot& robot) {
    int opcja, pamiec, nowy_parametr;

    do {
        cout << "------------- PROGRAM TESTOWY -------------" << endl;
        cout << "Witam w symulatorze robota, wybierz opcje:" << endl;
        cout << "1. Wyswietl raport o robocie" << endl;
        cout << "2. Ruch robotem do przodu" << endl;
        cout << "3. Pit-stop" << endl;
        cout << "4. Modyfikacja pamieci robota" << endl;
        cout << "5. Modyfikacja parametru specjalnego" << endl;
        cout << "6. Wyjscie" << endl;
        cout << "-------------------------------------------" << endl << endl;
        cout << "Opcja: ";
        cin >> opcja;

        if(cin.good()==false) {
            validity();
            break;
        }

        switch(opcja) {
        case 1:
            system("cls");
            robot.raport();
            fflush(stdin);
            cout << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
            cin.get();
            system("cls");
            opcja = 0;
            break;

        case 2:
            system("cls");
            cout << "------------- PROGRAM TESTOWY -------------" << endl;
            robot.ruch();
            cout << "-------------------------------------------" << endl << endl;
            fflush(stdin);
            cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
            cin.get();
            system("cls");
            opcja = 0;
            break;

        case 3:
            system("cls");
            cout << "------------- PROGRAM TESTOWY -------------" << endl;
            robot.ladowanie();
            cout << "-------------------------------------------" << endl << endl;
            fflush(stdin);
            cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
            cin.get();
            system("cls");
            opcja = 0;
            break;

        case 4:
            system("cls");
            cout << "------------------ PROGRAM TESTOWY ------------------" << endl;
            cout << "Podaj ilosc, o jaka chcesz zmodyfikowac pamiec robota\n(podaj liczbe ujemna, gdy chcesz ja zmniejszyc" << endl;
            cout << "-----------------------------------------------------" << endl << endl;
            cout << "Modyfikuj o: ";
            cin >> pamiec;

            if(cin.good()==false) {
                validity();
                break;
            }
            robot+pamiec;
            fflush(stdin);
            cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
            cin.get();
            system("cls");
            opcja = 0;
            break;
        case 5:
            system("cls");
            cout << "------------------ PROGRAM TESTOWY ------------------" << endl;
            cout << "Podaj nowa wartosc parametru robota: " << endl;
            cout << "-----------------------------------------------------" << endl << endl;
            cout << "Nowa wartosc: ";
            cin >> nowy_parametr;

            if(cin.good()==false) {
                validity();
                break;
            }
            robot.zmienParametrUrzadzenia(nowy_parametr);
            fflush(stdin);
            cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
            cin.get();
            system("cls");
            opcja = 0;
            break;
        }
    } while (opcja!=6);

    system("cls");
    cout << "--------- PROGRAM TESTOWY ----------" << endl;
    cout << "        Robot dezaktywowany!" << endl;
    cout << "------------------------------------" << endl;
}

int main() {
#ifdef DEBUG
    {
        cout << "Wywolanie konstruktora domyslnego Robot:" << endl;
        Rover robot1;
        robot1.raport();
        cout << endl;

        Rover robot2,robot3,robot4;
        cout << "Aktualnie stworzonych zostalo: " << robot1.wyswietl_ilosc() << " robotow." << endl;

        //Test operatorow

        //==
        robot1==robot2;

        // >
        robot1>robot2;
        robot2>robot1;
        // +
        robot1+256; // Max pamiec = 2048

        // -
        robot2-512; // Max pamiec 1024-512=512
        //<<
        cout << "Protokol robot1:" << endl;
        cout << robot1; //Wypisanie pelnego protokolu
        //=
        cout << "Test operatora =" << endl;
        robot1=robot2; // Przypisanie wszystkich danych robota5 robotowi1
        cout << "Protokol robot1 po przypisaniu:" << endl;
        cout << robot1; //Wypisanie pelnego protokolu

        //Tworzenie obiektu dynamicznego
        Robot* robot6 = new Rover;
        cout << "Raport obiektu stworzonego dynamicznie:" << endl;
        robot6->raport();
        cout << endl;

        cout << "Aktualnie stworzonych zostalo: " << robot6->wyswietl_ilosc() << " robotow." << endl;

        cout << "Destrukcja obiektu dynamicznego: " << endl;
        delete robot6;

        cout << "Aktualnie stworzonych zostalo: " << robot1.wyswietl_ilosc() << " robotow." << endl;
        robot1.~Rover();
        robot2.~Rover();
        cout << "Aktualnie stworzonych zostalo: " << robot1.wyswietl_ilosc() << " robotow." << endl;
        robot3.~Rover();
        robot4.~Rover();
    }
#endif // _DEBUG

    Transport robot1;
    Rover robot2;
    int opcja;
    cout << "------------- PROGRAM TESTOWY -------------" << endl;
    cout << "1. Stworz robota transportowego" << endl;
    cout << "2. Stworz Rovera marsjanskiego" << endl;
    cout << "3. Testuj wektory" << endl;
    cout << "-------------------------------------------" << endl << endl;
    cout << "Opcja: ";
    cin >> opcja;

    if(cin.good()==false) {
        validity();
    }

    switch(opcja) {
    case 1:
        system("cls");
        test(robot1);
        fflush(stdin);
        cout << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
        cin.get();
        system("cls");
        opcja = 0;
        break;

    case 2:
        system("cls");
        test(robot2);
        fflush(stdin);
        cout << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
        cin.get();
        system("cls");
        opcja = 0;
        break;

    case 3:
        system("cls");
        cout << "Tworze 6 obiektow oraz vector wskaznikow. Przypisuje je w zmienionej kolejnosci do wektora";
        Rover Rover1, Rover2, Rover3;
        Transport trans1, trans2, trans3;
        vector <Robot*> roboty;
        roboty.push_back(&Rover2);
        roboty.push_back(&Rover1);
        roboty.push_back(&trans1);
        roboty.push_back(&trans3);
        roboty.push_back(&Rover3);
        roboty.push_back(&trans2);

        fflush(stdin);
        cout << endl << endl<< "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
        cin.get();
        cout << "Wyswietlam kolejno wszystkie obiekty, na ktore wskazuja elementy wektora:" << endl << endl;
        for (unsigned int i = 0; i < roboty.size(); i++)
        {
            roboty[i]->raport();
            cout << "---------------------------------------------" << endl << endl;
        }

        fflush(stdin);
        cout << endl << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
        cin.get();

        cout << "Usuwam pierwszy i trzeci wskaznik, a nastepnie wyswietlam wektor:" << endl << endl;
        roboty.erase(roboty.begin());
        roboty.erase(roboty.begin()+1);
        for (unsigned int i = 0; i < roboty.size(); i++)
        {
            roboty[i]->raport();
            cout << "---------------------------------------------" << endl << endl;
        }

        fflush(stdin);
        cout << endl << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
        cin.get();

        cout << "Sortuje elementy:" << endl << endl;

        sort(roboty.begin(), roboty.end());
        for (unsigned int i = 0; i < roboty.size(); i++)
        {
            roboty[i]->raport();
            cout << "---------------------------------------------" << endl << endl;
        }
        cin.get();
        system("cls");
        opcja = 0;
        break;
    }
    return 0;
}
