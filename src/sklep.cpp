#include "sklep.h"

int Sklep::m_liczba_obiektow_s = 0;

//---------------------------------------------------------------------------------------------------------

Sklep::Sklep()
{
    m_liczba_obiektow_s++;

#ifdef _DEBUG
    cout << "/ Sklep() /     liczba obiektow Sklep: " << m_liczba_obiektow_s << endl;
#endif
}


Sklep::Sklep(string nazwa)
{
    m_liczba_obiektow_s++;
    m_nazwa = nazwa;

#ifdef _DEBUG
    cout << "/ Sklep(string) /     liczba obiektow Sklep: " << m_liczba_obiektow_s << endl;
#endif
}


Sklep::~Sklep()
{
    m_liczba_obiektow_s--;

#ifdef _DEBUG
    cout << "/ ~Sklep() /     liczba obiektow Sklep: " << m_liczba_obiektow_s << endl;
#endif
}


Sklep::Sklep(const Sklep &s)
{
    m_liczba_obiektow_s++;

    m_nazwa = s.m_nazwa;
    m_sprzedawca = s.m_sprzedawca;

    if(!m_artykuly.size())
        m_artykuly = s.m_artykuly;

#ifdef _DEBUG
    cout << "/ Sklep(const Sklep &s) /     liczba obiektow Sklep: " << m_liczba_obiektow_s << endl;
#endif
}

//---------------------------------------------------------------------------------------------------------

string Sklep::typ() { return "Sklep"; }


void Sklep::dane()
{
    cout << "Typ: " << typ() << endl;
    Przedsiebiorstwo::dane();
    cout << "Sprzedawca i jego wynagrodzenie [PLN]: " << endl << m_sprzedawca;
}


void Sklep::edytuj()
{
    bool koniec = 0;

    do {
        int wybor;

        stopka();
        cout << "1. Zmien nazwe" << endl;
        cout << "2. Dodaj artykul" << endl;
        cout << "3. Usun artykul" << endl;
        cout << "4. Zmien dane sprzedawcy" << endl;
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

            default:
                komunikat("Nie ma takiego numeru. Wybierz ponownie");
                break;
        }

    }while(!koniec);
}


void Sklep::interfejs()
{
    bool koniec = 0;

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


void Sklep::setSprzedawca()
{
    string imie;
    double wynagrodzenie;

    stopka();
    cout << "Podaj imie: ";
    cin >> imie;
    cin.ignore(1000, '\n');

    cout << "Podaj wynagrodzenie: ";
    cin >> wynagrodzenie;

    if(cin.fail()) {
        komunikat("Blad we wczytywaniu");
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    m_sprzedawca.imie(imie);
    m_sprzedawca.setWynagrodzenie(wynagrodzenie);
}

//---------------------------------------------------------------------------------------------------------

bool Sklep::operator==(const Sklep &s)
{
    if(this == &s)
        return 1;

    if(m_nazwa != s.m_nazwa)
        return 0;

    if(m_sprzedawca != s.m_sprzedawca)
        return 0;

    for (int i=0; i<m_artykuly.size(); i++)
        if(m_artykuly[i] != s.m_artykuly[i])
            return 0;

    return 1;

}


Sklep& Sklep::operator=(const Sklep &s)
{
    if(this == &s)
        return *this;

    m_nazwa = s.m_nazwa;
    m_sprzedawca = s.m_sprzedawca;
    m_artykuly = s.m_artykuly;

    return *this;
}



/**
 * @param przyjmuje numer i-ty artykuly
 * @return zwraca artykul o i-tym indeksie lub pusty obiekt jesli nie istnieje i-ty artykul
 */
Artykul Sklep::operator[](int i)
{
    if(i < 0 || i > m_artykuly.size() - 1) {
        komunikat("Nie ma artykulu o takim indeksie");
        return Artykul();
    }

    return m_artykuly[i];
}


Sklep& Sklep::operator++()
{
    int prev = m_artykuly.size();
    for (int i = 0; i<prev; i++)
        m_artykuly.push_back(Artykul(m_artykuly[i].nazwa(), m_artykuly[i].cena()));

    return *this;
}


Sklep::operator string()
{
    string ret;
    ret = m_nazwa + "\n";

    {
        ostringstream s;
        s << fixed << setprecision(0) << m_sprzedawca.wynagrodzenie();
        string wynagrodzenie = s.str();
        ret += m_sprzedawca.imie() + "  " + wynagrodzenie + " PLN\n\n";
    }

    for (int i=0; i<m_artykuly.size(); i++) {
        ostringstream s;
        s << fixed << setprecision(2) << m_artykuly[i].cena();
        string cena = s.str();
        ret += m_artykuly[i].nazwa() + "    " + cena + " PLN\n";
    }

    return ret;
}


ostream& Sklep::print(ostream &ret)
{
    Przedsiebiorstwo::print(ret);
    ret << m_sprzedawca;

    return ret;
}

ostream& operator<<(ostream &ret, Sklep &s)
{
    return s.print(ret);
}


istream& Sklep::load(istream &ret)
{

    Przedsiebiorstwo::load(ret);
    ret >> m_sprzedawca;

    return ret;
}

istream& operator>>(istream &ret, Sklep &s)
{
    return s.load(ret);
}
