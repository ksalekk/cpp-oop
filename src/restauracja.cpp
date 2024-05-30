#include "restauracja.h"

int Restauracja::m_liczba_obiektow_r = 0;

Restauracja::Restauracja()
{
    m_liczba_obiektow_r++;

#ifdef _DEBUG
    cout << "/ Restauracja() /     liczba obiektow Restauracja: " << m_liczba_obiektow_r << endl;
#endif
}


Restauracja::Restauracja(string nazwa, int gwiazdki_michelin)
{
    m_liczba_obiektow++;
    m_nazwa = nazwa;
    m_gwiazdki_michelin = gwiazdki_michelin;

#ifdef _DEBUG
    cout << "/ Restauracja(string, int) /     liczba obiektow Restauracja: " << m_liczba_obiektow_r << endl;
#endif
}


Restauracja::~Restauracja()
{
    m_liczba_obiektow_r--;

#ifdef _DEBUG
    cout << "/ ~Restauracja() /     liczba obiektow Restauracja: " << m_liczba_obiektow_r << endl;
#endif
}


Restauracja::Restauracja(const Restauracja &r)
{
    m_liczba_obiektow_r++;

    m_nazwa = r.m_nazwa;

    m_zestaw_dnia[0] = r.m_zestaw_dnia[0];
    m_zestaw_dnia[1] = r.m_zestaw_dnia[1];

    m_gwiazdki_michelin = r.m_gwiazdki_michelin;

    m_artykuly = r.m_artykuly;

#ifdef _DEBUG
    cout << "/ Restauracja(const Restauracja &r) /     liczba obiektow Restauracja: " << m_liczba_obiektow_r << endl;
#endif
}

//---------------------------------------------------------------------------------------------------------

void Restauracja::setGwiazdkiMichelin()
{
    int gwiazdki;

    stopka();
    cout << "Wpisz liczbe gwiazdek: ";
    cin >> gwiazdki;

    if(cin.fail()) {
        komunikat("Blad we wczytywaniu");
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    if(gwiazdki < 0 || gwiazdki > 3) {
        cout << "Nieprawidlowa ilosc" << endl;
        return;
    }

    m_gwiazdki_michelin = gwiazdki;
}


string Restauracja::gwiazdkiMichelin()
{
    string ret;
    for (int i=0; i<m_gwiazdki_michelin; i++)
        ret += '*';
    ret += '\n';

    return ret;
}

void Restauracja::setZestawDnia()
{
    string nazwa;
    double cena;

    stopka();
    for (int i=0; i<2; i++) {
        cout << "Podaj jednowyrazowa nazwe obiadu nr " << i << ": ";
        cin >> nazwa;
        cin.ignore(1000, '\n');

        cout << "Podaj cene obiadu nr " << i << ": ";
        cin >> cena;

        if(cin.fail()) {
            komunikat("Blad wczytywania");
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        m_zestaw_dnia[i].nazwa(nazwa);
        m_zestaw_dnia[i].cena(cena);
    }
}

//---------------------------------------------------------------------------------------------------------

string Restauracja::typ() { return "Restauracja"; }

void Restauracja::dane()
{
    cout << "Typ: " << typ() << endl;
    Przedsiebiorstwo::dane();
    cout << "Zestaw dnia: " << endl << m_zestaw_dnia[0] << m_zestaw_dnia[1] << endl;
    cout << "Gwiazdki Michelin: " << m_gwiazdki_michelin << endl;
}

void Restauracja::edytuj()
{
    bool koniec = 0;
    do {
        int wybor;

        stopka();
        cout << "1. Zmien nazwe" << endl;
        cout << "2. Dodaj artykul" << endl;
        cout << "3. Usun artykul" << endl;
        cout << "4. Ustaw zestaw dnia" << endl;
        cout << "5. Nadaj gwiazdki Michelin" << endl;
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
                setZestawDnia();
                break;

            case 5:
                setGwiazdkiMichelin();
                break;

            default:
                komunikat("Nie ma takiego numeru. Wybierz ponownie");
                break;
        }

    }while(!koniec);
}


void Restauracja::interfejs()
{
    bool koniec = 0;
    do {
        int wybor;

        stopka();
        cout << "1. Pokaz dane o obiekcie" << endl;
        cout << "2. Pokaz artykuly" << endl;
        cout << "3. Pokaz gwiazdki Michelin" << endl;
        cout << "4. Pokaz zestaw dnia" << endl;
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

            case 3:
                cout << gwiazdkiMichelin();
                break;

            case 4:
            {
                cout << "#NAZWA# | #PLN#" << endl;
                cout << m_zestaw_dnia[0];
                cout << m_zestaw_dnia[1];
                break;
            }

            default:
                komunikat("Nie ma takiego numeru. Wybierz ponownie");
                break;
        }

    }while(!koniec);
}


ostream& Restauracja::print(ostream &ret)
{
    Przedsiebiorstwo::print(ret);
    ret << m_zestaw_dnia[0] << m_zestaw_dnia[1];
    ret << m_gwiazdki_michelin << endl;

    return ret;
}

ostream& operator<<(ostream &ret, Restauracja &r)
{
    return r.print(ret);
}


istream& Restauracja::load(istream &ret)
{
    Przedsiebiorstwo::load(ret);

    ret >> m_zestaw_dnia[0] >> m_zestaw_dnia[1];
    ret >> m_gwiazdki_michelin;

    return ret;
}


istream& operator>>(istream &ret, Restauracja &r)
{
    return r.load(ret);
}
