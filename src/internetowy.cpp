#include "internetowy.h"

int Internetowy::m_liczba_obiektow_i = 0;

Internetowy::Internetowy()
{
    m_liczba_obiektow_i++;


#ifdef _DEBUG
    cout << "/ Internetowy() /     liczba obiektow Internetowy: " << m_liczba_obiektow_i << endl;
#endif
}


Internetowy::Internetowy(string nazwa)
{
    m_liczba_obiektow_i++;
    m_nazwa = nazwa;

#ifdef _DEBUG
    cout << "/ Internetowy(string) /     liczba obiektow Internetowy: " << m_liczba_obiektow_i << endl;
#endif
}


Internetowy::~Internetowy()
{
    m_liczba_obiektow_i--;

#ifdef _DEBUG
    cout << "/ ~Internetowy() /     liczba obiektow Internetowy: " << m_liczba_obiektow_i << endl;
#endif
}


Internetowy::Internetowy(const Internetowy &s)
{
    m_nazwa = s.m_nazwa;
    m_sprzedawca = s.m_sprzedawca;

    m_artykuly = s.m_artykuly;

    m_login = s.m_login;
    m_haslo = s.m_haslo;
    m_www = s.m_www;

#ifdef _DEBUG
    cout << "/ Internetowy(const Internetowy &s) /     liczba obiektow Internetowy: " << m_liczba_obiektow_i << endl;
#endif
}

//---------------------------------------------------------------------------------------------------------

void Internetowy::setWww()
{
    string www;

    stopka();
    cout << "Podaj adres: ";
    cin >> www;
    cin.ignore(1000, '\n');

    m_www = www;
}

bool Internetowy::zalogujSie()
{
    string login, haslo;

    stopka();
    cout << "Podaj login: ";
    cin >> login;
    cin.ignore(1000, '\n');

    cout << "Podaj haslo: ";
    cin >> haslo;
    cin.ignore(1000, '\n');


    if(login == m_login && haslo == m_haslo)
        return 1;
    else {
        cout << "Dane niepoprawne" << endl;
        return 0;
    }
}

bool Internetowy::zarejestrujSie()
{
    stopka();
    cout << "Podaj login: ";
    cin >> m_login;
    cin.ignore(1000, '\n');

    cout << "Podaj haslo: ";
    cin >> m_haslo;
    cin.ignore(1000, '\n');

    cout << "Zarejestrowano pomyslnie. Teraz mozesz sie zalogowac" << endl;
    return 1;
}

//---------------------------------------------------------------------------------------------------------

string Internetowy::typ() { return "Internetowy"; }


void Internetowy::edytuj()
{
    bool koniec = 0;
    do {
        int wybor;

        stopka();
        cout << "1. Zmien nazwe" << endl;
        cout << "2. Dodaj artykul" << endl;
        cout << "3. Usun artykul" << endl;
        cout << "4. Zmien dane sprzedawcy" << endl;
        cout << "5. Zmien adres www" << endl;
        cout << "0. Zakoncz" << endl;

        cin >> wybor;
        if(cin.fail()) {
            komunikat("Nieprawidlowy wybor");
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch(wybor) {

            case 0:
                koniec = 1;
                break;

            case 1:
                setNazwa();
                break;

            case 2:
                dodajArtykul();
                break;

            case 3:
                usunArtykul();
                break;

            case 4:
                setSprzedawca();
                break;

            case 5:
                setWww();
                break;

            default:
                komunikat("Nie ma takiego numeru. Wybierz ponownie");
                break;

        }

    }while(!koniec);
}


/// interfejs wykonywania akcji na obiekcie Internetowy
/**
 *  wykonywanie akcji na obiekcie mozliwe tylko wtedy gdy metoda zalogujSie zwroci 1
 */
void Internetowy::interfejs()
{
    bool koniec = 0;

    do {
        int wybor;

        stopka();
        cout << "Zaloguj sie, aby obejrzec interfejs" << endl;
        cout << "1. Zaloguj sie" << endl;
        cout << "2. Zarejestruj sie" << endl;
        cout << "0. Wyjdz" << endl;

        cin >> wybor;

        if(cin.fail()) {
            komunikat("Nieprawidlowy wybor");
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }


        switch(wybor) {
            case 0:
                koniec = 0;
                return;

            case 1:
                koniec = !zalogujSie();
                break;

            case 2:
                koniec = zarejestrujSie();
                break;

            default:
                komunikat("Niepoprawny numer");
                break;

        }

    }while(koniec);

    do {
        int wybor;

        stopka();
        cout << "1. Pokaz dane o obiekcie" << endl;
        cout << "2. Pokaz artykuly" << endl;
        cout << "0. Zakoncz" << endl;

        cin >> wybor;
        if(cin.fail()) {
            komunikat("Nieprawidlowy wybor");
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }


        switch(wybor) {

            case 0:
                koniec = 1;
                break;

            case 1:
                dane();
                break;

            case 2:
                pokazArtykuly();
                break;

            default:
                komunikat("Nie ma takiego numeru. Wybierz ponownie");
                break;

            }

    }while(!koniec);
}


void Internetowy::dane()
{
    cout << "Typ: " << typ() << endl;
    Sklep::dane();
    cout << "Adres www: " << m_www << endl;
    cout << "Login: " << m_login << " Haslo: " << m_haslo << endl;
}



ostream& Internetowy::print(ostream &ret)
{
    Sklep::print(ret);
    ret << m_login << endl;
    ret << m_haslo << endl;
    ret << m_www << endl;

    return ret;
}

ostream& operator<<(ostream &ret, Internetowy &si)
{
    return si.print(ret);
}


istream& Internetowy::load(istream &ret)
{
    Sklep::load(ret);
    ret >> m_login >> m_haslo >> m_www;

    return ret;
}

istream& operator>>(istream &ret, Internetowy &si)
{
    return si.load(ret);
}


