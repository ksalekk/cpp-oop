#include <iostream>
#include "Lista.h"
#include "internetowy.h"
#include "restauracja.h"
using namespace std;


void main1();

void interfejs(char);

void dodajObiekt(int, char);
void usunObiekt(char);
void przeniesObiekt(char);
void zamienObiekty(char);
void wyswietlObiekty(char);
void edytujObiekt(char);
void wykonajAkcje(char);
void zapiszObiekty(char);
void wczytajObiekty(char);
void usunWszystkie(char);

void obslugaBledow();

void testOperatora();
void stopka(string);
void pokazList();

Lista<int> lInt;
Lista<Sklep> lSklep;
Lista<Internetowy> lInternetowy;
Lista<Restauracja> lRestauracja;



int main()
{
    main1();
    return 0;
}



void main1()
{

    bool main_koniec = 0;

    do {
        int wybor;

        cout << " ____________________________________________________ " << endl;
        cout << "|      1. Utworz liste obiektow int                  |" << endl;
        cout << "|      2. Utworz liste obiektow Sklep                |" << endl;
        cout << "|      3. Utworz liste obiektow Sklep Internetowy    |" << endl;
        cout << "|      4. Utworz liste obiektow Restauracja          |" << endl;
        cout << "|      5. Pokaz test operatorow +, =, ==             |" << endl;
        cout << "|      0. Zakoncz                                    |" << endl;
        cout << " ---------------------------------------------------- " << endl;


        cout << "Wybierz opcje: ";
        try {
            cin >> wybor;
            obslugaBledow();
        }
            catch(runtime_error err) {
                cout << err.what() << endl;
                cout << "Sprobuj ponownie" << endl;
                continue;
            }


        switch(wybor) {
            case 0:
                main_koniec = 1;
                break;

            case 1:
                interfejs('q');
                break;

            case 2:
                interfejs('s');
                break;

            case 3:
                interfejs('i');
                break;

            case 4:
                interfejs('r');
                break;

            case 5:
                testOperatora();
                break;

            default:
                cout << " Nie ma takiego numeru. Wybierz ponownie " << endl;
                break;
        }

    } while(!main_koniec);

}





void interfejs(char klasa)
{
    bool koniec = 0;
    do {
        int wybor1;
        cout << " _________________________________________ " << endl;
        cout << "|      1. Dodaj obiekt na poczatek        |" << endl;
        cout << "|      2. Dodaj obiekt na koniec          |" << endl;
        cout << "|      3. Wstaw obiekt do srodka          |" << endl;
        cout << "|      4. Usun obiekt                     |" << endl;
        cout << "|      5. Przenies obiekt na poczatek     |" << endl;
        cout << "|      6. Wyswietl dostepne obiekty       |" << endl;
        cout << "|      7. Zamien obiekty kolejnoscia      |" << endl;
        cout << "|      8. Edytuj obiekt                   |" << endl;
        cout << "|      9. Wykonaj akcje na obiekcie       |" << endl;
        cout << "|     10. Zapisz obiekt(y) do pliku       |" << endl;
        cout << "|     11. Wczytaj obiekt(y) z pliku       |" << endl;
        cout << "|     12. Usun wszystkie obiekty          |" << endl;
        cout << "|      0. Zakoncz                         |" << endl;
        cout << " -----------------------------------------" << endl;

        cout << "Wybierz opcje: ";
        try {
            cin >> wybor1;
            obslugaBledow();
        }
            catch(runtime_error err) {
                cout << err.what() << endl;
                cout << "Sprobuj ponownie" << endl;
                continue;
            }



        switch(wybor1) {
            case 0: {
                koniec = 1;
                usunWszystkie(klasa);
                break;
            }

            case 1:
                dodajObiekt(0, klasa);
                break;

            case 2:
                dodajObiekt(1, klasa);
                break;

            case 3:
                dodajObiekt(2, klasa);
                break;

            case 4:
                usunObiekt(klasa);
                break;

            case 5:
                przeniesObiekt(klasa);
                break;

            case 6:
                wyswietlObiekty(klasa);
                break;

            case 7:
                zamienObiekty(klasa);
                break;

            case 8:
                edytujObiekt(klasa);
                break;

            case 9:
                wykonajAkcje(klasa);
                break;

            case 10:
                zapiszObiekty(klasa);
                break;

            case 11:
                wczytajObiekty(klasa);
                break;

            case 12:
                usunWszystkie(klasa);
                break;

            default:
                cout << " Nie ma takiego numeru. Wybierz ponownie " << endl;
                break;
        }

    }while(!koniec);
}



void dodajObiekt(int wybor, char klasa)
{
    int numer;
    if (wybor == 2) {
        cout << "Za ktory element wstawic nowy obiekt? Podaj numer: ";
        try {
            cin >> numer;
            obslugaBledow();
        }
            catch(runtime_error err) {
                cout << err.what() << endl;
                return;
            }

    }


    try {
        if (klasa == 'q') {
            int nowa;
                cout << "Podaj liczbe: ";
                try {
                    cin >> nowa;
                    obslugaBledow();
                }
                    catch(runtime_error err) {
                        cout << err.what() << endl;
                        return;
                    }

            if (wybor == 0)
                lInt.dodajNaPoczatek(nowa);
            else if (wybor == 1)
                lInt.dodajNaKoniec(nowa);
            else if (wybor == 2)
                lInt.wstawElement(numer, nowa);

            return;
        }

        string nazwa;
        cout << "Podaj jednowyrazowa nazwe obiektu: ";
        cin >> nazwa;
            cin.ignore(1000, '\n');


        if(klasa == 's') {
            if (wybor == 0)
                lSklep.dodajNaPoczatek(Sklep(nazwa));
            else if (wybor == 1)
                lSklep.dodajNaKoniec(Sklep(nazwa));
            else if (wybor == 2)
                lSklep.wstawElement(numer, Sklep(nazwa));
        }

        else if (klasa == 'i') {
            if (wybor == 0)
                lInternetowy.dodajNaPoczatek(Internetowy(nazwa));
            else if (wybor == 1)
                lInternetowy.dodajNaKoniec(Internetowy(nazwa));
            else if (wybor == 2)
                lInternetowy.wstawElement(numer, Internetowy(nazwa));
        }

        else if(klasa == 'r') {
            if(wybor == 0)
                lRestauracja.dodajNaPoczatek(Restauracja(nazwa));
            else if (wybor == 1)
                lRestauracja.dodajNaKoniec(Restauracja(nazwa));
            else if (wybor == 2)
                lRestauracja.wstawElement(numer, Restauracja(nazwa));
        }


    }
        catch(out_of_range error) {
            cout << error.what() << endl;
            return;
        }

}




void usunObiekt(char klasa)
{
    int numer;
    cout << "Podaj numer obiektu do usuniecia: ";
    try {
        cin >> numer;
        obslugaBledow();
    }
        catch(runtime_error err) {
            cout << err.what() << endl;
            return;
        }



    try {
        if(klasa == 'q')
            lInt.usunElement(numer);

        else if(klasa == 's')
            lSklep.usunElement(numer);

        else if(klasa == 'i')
            lInternetowy.usunElement(numer);

        else if(klasa == 'r')
            lRestauracja.usunElement(numer);
    }
        catch(out_of_range error) {
            cout << error.what() << endl;
            return;
        }
}




void przeniesObiekt(char klasa)
{
    int numer;
    cout << "Podaj numer obiektu do przeniesienia na poczatek: ";
    try {
        cin >> numer;
        obslugaBledow();
    }
        catch(runtime_error err) {
            cout << err.what() << endl;
            return;
        }


    try {
        if(klasa == 'q')
            lInt.moveToFront(numer);

        else if(klasa == 's')
            lSklep.moveToFront(numer);

        else if(klasa == 'i')
            lInternetowy.moveToFront(numer);

        else if(klasa == 'r')
            lRestauracja.moveToFront(numer);
    }
        catch(out_of_range error) {
            cout << error.what() << endl;
            return;
        }
}




void zamienObiekty(char klasa)
{
    int numer1, numer2;
    cout << "Podaj numery obiektow do zamiany" << endl;
    cout << "Numer 1: ";
    try {
        cin >> numer1;
        obslugaBledow();
        cout << "Numer 2: ";
        cin >> numer2;
        obslugaBledow();
    }
        catch(runtime_error err) {
            cout << err.what() << endl;
            return;
        }



    try {
        if(klasa == 'q')
            lInt.zmienKolejnosc(numer1, numer2);

        else if(klasa == 's')
            lSklep.zmienKolejnosc(numer1, numer2);

        else if(klasa == 'i')
            lInternetowy.zmienKolejnosc(numer1, numer2);

        else if(klasa == 'r')
            lRestauracja.zmienKolejnosc(numer1, numer2);

    }
        catch(out_of_range error) {
            cout << error.what() << endl;
            return;
        }
}





void wyswietlObiekty(char klasa)
{


    if(klasa == 'q')
        lInt.pokaz();

    else if (klasa == 's')
        lSklep.pokaz();

    else if (klasa == 'i')
        lInternetowy.pokaz();

    else if (klasa == 'r')
        lRestauracja.pokaz();
}





void edytujObiekt(char klasa)
{
    int numer;
    cout << "Podaj numer obiektu do edycji: ";
    try {
        cin >> numer;
        obslugaBledow();
    }
        catch(runtime_error err) {
            cout << err.what() << endl;
            return;
        }



    try {
        if (klasa == 'q') {
            int nowa;
            cout << "Podaj nowa wartosc liczby: ";
            cin >> nowa;
            lInt.getElement(numer) = nowa;

            return;
        }


        else if (klasa == 's')
            lSklep.getElement(numer).edytuj();

        else if (klasa == 'i')
            lInternetowy.getElement(numer).edytuj();

        else if (klasa == 'r')
            lRestauracja.getElement(numer).edytuj();
    }
        catch(out_of_range error) {
            cout << error.what() << endl;
            return;
        }
}





void wykonajAkcje(char klasa)
{
    if(klasa == 'q') {
        cout << "Nie mozesz wykonac akcji na obiekcie typu int" << endl;
        return;
    }


    int numer;
    cout << "Podaj numer obiektu do wykonania akcji: ";
    try {
        cin >> numer;
        obslugaBledow();
    }
        catch(runtime_error err) {
            cout << err.what() << endl;
            return;
        }



    try {
        if (klasa == 's')
            lSklep.getElement(numer).interfejs();

        else if (klasa == 'i')
            lInternetowy.getElement(numer).interfejs();

        else if (klasa == 'r')
            lRestauracja.getElement(numer).interfejs();
    }
        catch(out_of_range error) {
            cout << error.what() << endl;
            return;
        }

}




void zapiszObiekty(char klasa)
{
    try {
        if (klasa == 'q')
            lInt.zapiszDoPliku("inty.txt");


        else if (klasa == 's')
            lSklep.zapiszDoPliku("sklep.txt");

        else if (klasa == 'i')
            lInternetowy.zapiszDoPliku("internetowy.txt");

        else if (klasa == 'r')
            lRestauracja.zapiszDoPliku("restauracja.txt");
    }
        catch(runtime_error err) {
            cout << err.what() << endl;
            return;
        }

}



void wczytajObiekty(char klasa)
{
    try {
        if (klasa == 'q')
            lInt.wczytajZPliku("inty.txt");


        else if (klasa == 's')
            lSklep.wczytajZPliku("sklep.txt");

        else if (klasa == 'i')
            lInternetowy.wczytajZPliku("internetowy.txt");

        else if (klasa == 'r')
            lRestauracja.wczytajZPliku("restauracja.txt");
    }
        catch(runtime_error err) {
            cout << err.what() << endl;
            return;
        }
}



void usunWszystkie(char klasa)
{
    if (klasa == 'q')
        lInt.~Lista();


    else if (klasa == 's')
        lSklep.~Lista();

    else if (klasa == 'i')
        lInternetowy.~Lista();

    else if (klasa == 'r')
        lRestauracja.~Lista();
}


void testOperatora()
{
    Lista<int> l1, l2, l3, l4;

    for (int i=0; i<5; i++)
        l1.dodajNaPoczatek(rand()%10);

    for (int i=0; i<3; i++)
        l2.dodajNaPoczatek(rand()%10);


        stopka("l1");
        l1.pokaz();
        stopka("l2");
        l2.pokaz();
        stopka("l3");
        l3.pokaz();
        stopka("l4");
        l4.pokaz();

        cout << endl << "[ l3 = l1 + l2 ]" << endl;
        l3 = l1 + l2;
        stopka("l1");
        l1.pokaz();
        stopka("l2");
        l2.pokaz();
        stopka("l3");
        l3.pokaz();

        cout << endl << "[ l3 = l2 + l1 ]" << endl;
        l3 = l2 + l1;
        stopka("l1");
        l1.pokaz();
        stopka("l2");
        l2.pokaz();
        stopka("l3");
        l3.pokaz();

        cout << endl << "[ l4 = l1 + l1 + l2 ]" << endl;
        l4 = l1 + l1 + l2;
        stopka("l1");
        l1.pokaz();
        stopka("l2");
        l2.pokaz();
        stopka("l4");
        l4.pokaz();


        cout << endl <<  "[ l1 = l1 + l1 ]" << endl;
        l1 = l1 + l1;
        stopka("l1");
        l1.pokaz();


        cout << endl <<  "[ (l2+l3).pokaz() ]" << endl;
        (l2+l3).pokaz();
        stopka("l2");
        l2.pokaz();
        stopka("l3");
        l3.pokaz();


        cout << endl << "[ l1 = l2 ]" << endl;
        l1 = l2;
        stopka("l1");
        l1.pokaz();
        stopka("l2");
        l2.pokaz();

        cout << endl << "Czy l1 == l2 ?" << endl;
        if(l1==l2)
            cout << "l1 == l2" << endl;
        else
            cout << "l1 != l2" << endl;

        cout << endl << "Czy l1 == l3 ?" << endl;
        if(l1==l3)
            cout << "l1==l3" << endl;
        else
            cout << "l1 != l3" << endl;
}

void obslugaBledow()
{
    if(cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw runtime_error(" [ERROR]   Blad wczytywania ");
    }
    cin.ignore(1000, '\n');
}


void stopka(string tekst)
{
    cout << "---------------------- " << tekst << " ----------------------" << endl;
}
