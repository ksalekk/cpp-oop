#include "przedsiebiorstwo.h"

int Przedsiebiorstwo::m_liczba_obiektow = 0;

//---------------------------------------------------------------------------------------------------------

Przedsiebiorstwo::Przedsiebiorstwo()
{
    m_liczba_obiektow++;

#ifdef _DEBUG
    cout << "/ Przedsiebiorstwo() /     liczba obiektow Przedsiebiorstwo: " << m_liczba_obiektow << endl;
#endif
}

Przedsiebiorstwo::~Przedsiebiorstwo()
{
    m_liczba_obiektow--;

#ifdef _DEBUG
    cout << "/ ~Przedsiebiorstwo() /     liczba obiektow Przedsiebiorstwo: " << m_liczba_obiektow << endl;
#endif
};

//---------------------------------------------------------------------------------------------------------

void Przedsiebiorstwo::stopka()
{
    cout << "----------------------------------------------" << endl;
}

void Przedsiebiorstwo::komunikat(string tekst)
{
    cout << "----------------------------------" << endl;
    cout << tekst << endl;
    cout << "----------------------------------" << endl;
}

//---------------------------------------------------------------------------------------------------------

string Przedsiebiorstwo::nazwa() { return m_nazwa; }
void Przedsiebiorstwo::setNazwa()
{
    string nazwa;

    stopka();
    cout << "Podaj nowa nazwe: ";
    cin >> nazwa;
    cin.ignore(1000, '\n');

    m_nazwa = nazwa;
}


void Przedsiebiorstwo::pokazArtykuly()
{
    if(!m_artykuly.size()) {
        komunikat("Nie ma zadnych artykulow");
        return;
    }

    cout << "#NAZWA# | #PLN#" << endl;
    for (int i=0; i<m_artykuly.size(); i++) {

        cout << m_artykuly[i];
    }
}


void Przedsiebiorstwo::dodajArtykul()
{
    string nazwa;
    double cena;

    stopka();
    cout << "Podaj nazwe: ";
    cin >> nazwa;
    cin.ignore(1000, '\n');

    cout << "Podaj cene: ";
    cin >> cena;

    if(cin.fail()) {
        komunikat("Nieprawidlowy wybor");
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    m_artykuly.push_back(Artykul(nazwa, cena));
}


void Przedsiebiorstwo::usunArtykul()
{
    if(!m_artykuly.size()) {
        komunikat("Nie ma zadnych artykulow");
        return;
    }

    int wybor;

    stopka();
    pokazArtykuly();

    stopka();
    cout << "Podaj numer artykulu, ktory chcesz usunac: ";
    cin >> wybor;

    if(cin.fail()) {
        komunikat("Nieprawidlowy wybor");
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    if(wybor < 0 || wybor > m_artykuly.size()) {
        komunikat("Nie istnieje artykul o takim indeksie");
        return;
    }

    m_artykuly.erase(m_artykuly.begin() + wybor);
}




//---------------------------------------------------------------------------------------------------------

void Przedsiebiorstwo::dane()
{
    cout << "Nazwa: " << m_nazwa << endl << endl;
    cout << "Artykuly: " << endl;
    pokazArtykuly();
    cout << endl;
}


/**
 * @param przyjmuje strumien wyjsciowy
 * @return zwraca zmodyfikowany strumien wyjsciowy
 */
ostream& Przedsiebiorstwo::print(ostream &ret)
{
    //ret << typ() << endl;  --> zakomentowane dla projektu3  i  odkomentowane dla projektu2
    ret << m_nazwa << endl;
    ret << m_artykuly.size() << endl;
    for (int i = 0; i < m_artykuly.size(); i++)
        ret << m_artykuly[i];

    return ret;
}

/**
 * @param przyjmuje strumien wyjsciowy i przekazuje go do metody print
 * @return zwraca strumien wyjsciowy zmodyfikowany w metodzie print
 */
ostream& operator<<(ostream &ret, Przedsiebiorstwo &p)
{
    return p.print(ret);
}


/**
 * @param przyjmuje strumien wejsciowy
 * @return zwraca ten sam strumien wejsciowy
 */
istream& Przedsiebiorstwo::load(istream &ret)
{
    int ile;

    ret >> m_nazwa;
    ret >> ile;

    for (int i = 0; i < ile; i++) {
        m_artykuly.push_back(Artykul());
        ret >> m_artykuly[i];
    }

    return ret;
}

/**
 * @param przyjmuje strumien wejsciowy i przekazuje go do metody load
 * @return zwraca ten sam strumien wejsciowy
 */
istream& operator>>(istream &ret, Przedsiebiorstwo &p)
{
    return p.load(ret);
}

