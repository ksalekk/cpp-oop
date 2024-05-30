#ifndef PRZEDSIEBIORSTWO_H
#define PRZEDSIEBIORSTWO_H

#include "artykul.h"
#include<vector>



class Przedsiebiorstwo
{

protected:
    string m_nazwa = "blank";
    vector<Artykul> m_artykuly;

    static int m_liczba_obiektow; ///< pokazuje liczbe istniejacych obiektow klas pochodnych

public:
    Przedsiebiorstwo();
    virtual ~Przedsiebiorstwo();

    void stopka();
    void komunikat(string);

    /// zwraca wartosc m_nazwa
    string nazwa();
    /// umozliwia zmiane wartosci m_nazwa poprzez strumien wejscia konsoli
    void setNazwa();

    /// pokazuje wszystkie artykuly obiektu
    void pokazArtykuly();
    /// dodaje artykul o okreslonej nazwie i cenie, wprowadzonej poprzez strumien wejscia konsoli
    void dodajArtykul();
    /// usuwa artykul o indeksie wprowadzonym poprzez strumien wejscia konsoli z wektora m_artykuly
    void usunArtykul();

    /// zwraca nazwe klasy pochodnej
    virtual string typ()=0;
    /// interfejs do edycji obiektu
    virtual void edytuj()=0;
    /// interfejs do wykonywania akcji na obiekcie
    virtual void interfejs()=0;
    /// metoda pokazujaca wszystkie dane obiektu
    virtual void dane();

    /// metoda umozliwiajaca polimorficzne wywolywanie operatora <<
    virtual ostream& print(ostream&);
    /// metoda umozliwiajaca polimorficzne wywolanie operatora >>
    virtual istream& load(istream&);

    /// operator wypisywania danych z obiektu do strumienia
    friend ostream& operator<<(ostream&, Przedsiebiorstwo&);
    /// operator wczytywania danych ze strumienia do obiektu
    friend istream& operator>>(istream&, Przedsiebiorstwo&);
};

#endif // PRZEDSIEBIORSTWO_H
