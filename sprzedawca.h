#ifndef SPRZEDAWCA_H
#define SPRZEDAWCA_H

#include <iostream>
using namespace std;


class Sprzedawca
{

private:
    string m_imie="blank";
    double m_wynagrodzenie = 0;

    static int m_liczba_obiektow;

public:
    Sprzedawca();
    Sprzedawca(string, double);
    ~Sprzedawca();
    Sprzedawca(const Sprzedawca&);

    /// zwraca wartosc zmiennej m_imie
    string imie();
    /// zmienia wartosc zmiennej m_imie na wartosc przekazana w parametrze
    void imie(string);

    /// zwraca wartosc zmiennej m_wynagrodzenie
    double wynagrodzenie();
    /// zmienia wartosc zmiennej m_wynagrodzenie na wartosc przekazana w parametrze
    void setWynagrodzenie(double);

    /// operator przypisania
    Sprzedawca& operator=(const Sprzedawca&);
    /// zwraca 1 wtedy i tylko wtedy, gdy obiekt ma te sama wartosc m_imie i m_wynagrodzenie
    bool operator==(const Sprzedawca&);
    /// zwraca negacje operatora ==
    bool operator!=(const Sprzedawca&);
    /// operator wypisywania danych z obiektu do strumienia
    friend ostream& operator<<(ostream&, Sprzedawca&);
    /// operator wypisywania danych ze strumienia do obiektu
    friend istream& operator>>(istream&, Sprzedawca&);

};

#endif // SPRZEDAWCA_H
