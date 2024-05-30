#ifndef ARTYKUL_H
#define ARTYKUL_H

#include<iostream>
using namespace std;

class Artykul
{

private:
    string m_nazwa="blank";
    double m_cena=0;

    static int m_liczba_obiektow;

public:
    Artykul();
    Artykul(string, double);
    ~Artykul();
    Artykul(const Artykul&);

    /// zwraca wartosc m_nazwa
    string nazwa();
    /// zmienia wartosc m_nazwa na wartosc przekazana w parametrze
    void nazwa(string);

    /// zwraca wartosc m_cena
    double cena();
    /// zmienia wartosc m_cena na wartosc przekazana w parametrze
    void cena(double);

    /// zwraca 1 wtedy i tylko wtedy, gdy artykuly maja te sama nazwe i cene
    bool operator==(const Artykul& );
    /// zwraca negacje operatora ==
    bool operator!=(const Artykul&);
    /// operator przypisania
    Artykul& operator=(const Artykul&);
    /// operator wypisywania danych z obiektu do strumienia
    friend ostream& operator<<(ostream&, Artykul&);
    /// operator wczytywania danych ze strumienia do obiektu
    friend istream& operator>>(istream&, Artykul&);


};

#endif // ARTYKUL_H
