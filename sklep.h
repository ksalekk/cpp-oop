#ifndef SKLEP_H
#define SKLEP_H

#include <sstream>
#include <iomanip>

#include "sprzedawca.h"
#include "przedsiebiorstwo.h"

class Sklep : public Przedsiebiorstwo
{

protected:
    Sprzedawca m_sprzedawca;

    static int m_liczba_obiektow_s;

public:
    Sklep();
    Sklep(string);
    ~Sklep();
    Sklep(const Sklep&);

    /// zmienia wartosci zmiennych obiektu m_sprzedawca na te wprowadzone poprzez strumien wejscia konsoli
    void setSprzedawca();

    string typ();
    void interfejs();
    void edytuj();
    void dane();
    ostream& print(ostream&);
    istream& load(istream&);

    /// zwraca 1 wtedy i tylko wtedy, gdy skladowe obiekty maja te same wartosc,
    /// a skladowy wektor zawiera obiekty o tych samych wartosciach i tej samej kolejnosci
    bool operator==(const Sklep&);
    /// operator przypisania
    Sklep& operator=(const Sklep&);
    /// zwraca artykul o indeksie wprowadzonym w parametrze
    Artykul operator[](int);
    /// podwaja wszystkie artykuly obiektu
    Sklep& operator++();
    /// konwertuje obiekt na zmienna string bedaca slownym opisem danych obiektu
    operator string();

    friend ostream& operator<<(ostream&, Sklep&);
    friend istream& operator>>(istream&, Sklep&);

};

#endif // SKLEP_H
