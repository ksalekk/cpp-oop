#ifndef INTERNETOWY_H
#define INTERNETOWY_H

#include "sklep.h"

class Internetowy : public Sklep
{
private:
    string m_www = "blank";
    string m_login = "blank";
    string m_haslo = "blank";

    static int m_liczba_obiektow_i;


public:
    Internetowy();
    Internetowy(string);
    ~Internetowy();
    Internetowy(const Internetowy&);

    void interfejs();
    void edytuj();
    void dane();
    string typ();
    ostream& print(ostream&);
    istream& load(istream&);

    /// zmienia wartosc m_www na te wprowadzona poprzez strumien wejscia konsoli
    void setWww();
    /// zwraca 1 gdy login i haslo wprowadzone poprzez strumien wejscia konsoli sa takie same jak m_login i m_haslo
    bool zalogujSie();
    /// zmienia wartosci m_login i m_haslo na te wprowadzone poprzez strumien wejscia konsoli i zwraca zawsze 1
    bool zarejestrujSie();

    friend ostream& operator<<(ostream&, Internetowy&);
    friend istream& operator>>(istream&, Internetowy&);
};

#endif // INTERNETOWY_H
