#ifndef RESTAURACJA_H
#define RESTAURACJA_H

#include "przedsiebiorstwo.h"

class Restauracja : public Przedsiebiorstwo
{

private:
    Artykul m_zestaw_dnia[2];   ///< tablica 2 artykulow bedacych zestawem dnia
    int m_gwiazdki_michelin;    ///< liczba gwiazdek Michelin

    static int m_liczba_obiektow_r;

public:
    Restauracja();
    Restauracja(string, int=3);
    ~Restauracja();
    Restauracja(const Restauracja&);

    void interfejs();
    void edytuj();
    void dane();
    string typ();
    ostream& print(ostream&);
    istream& load(istream&);

    /// zmienia wartosci obiektow w tablicy m_zestaw_dnia na te wprowadzone poprzez strumien wejscia konsoli
    void setZestawDnia();

    /// zmienia wartosc zmiennej m_gwiazdki_michelin na te wprowadzone poprzez strumien wejscia konsoli
    void setGwiazdkiMichelin();
    /// zwraca tekst obrazujacy gwiazdki Michelin
    string gwiazdkiMichelin();

    friend ostream& operator<<(ostream&, Restauracja&);
    friend istream& operator>>(istream&, Restauracja&);


};

#endif // RESTAURACJA_H
