#include "artykul.h"

int Artykul::m_liczba_obiektow = 0;

//---------------------------------------------------------------------------------------------------------

Artykul::Artykul()
{
    m_liczba_obiektow++;

#ifdef _DEBUG
    cout << "/ Artykul() /     liczba obiektow Artykul: " << m_liczba_obiektow << endl;
#endif
}


Artykul::Artykul(string nazwa, double cena)
{
    m_liczba_obiektow++;

#ifdef _DEBUG
    cout << "/ Artykul(string, double) /    liczba obiektow Artykul: " << m_liczba_obiektow << endl;
#endif

    m_nazwa = nazwa;
    m_cena = cena;
}

Artykul::~Artykul()
{
    m_liczba_obiektow--;

#ifdef _DEBUG
    cout << "/ ~Artykul() /     liczba obiektow Artykul: " << m_liczba_obiektow << endl;
#endif
}


Artykul::Artykul(const Artykul &a)
{
    m_liczba_obiektow++;

#ifdef _DEBUG
    cout << "/ Artykul(const Artykul&) /     liczba obiektow Artykul: " << m_liczba_obiektow << endl;
#endif

    m_nazwa = a.m_nazwa;
    m_cena = a.m_cena;
}

//---------------------------------------------------------------------------------------------------------

string Artykul::nazwa() { return m_nazwa; }
void Artykul::nazwa(string nazwa) { m_nazwa = nazwa; }

double Artykul::cena() { return m_cena; }
void Artykul::cena(double cena)
{
    if(cena>0)
        m_cena = cena;
    else
        m_cena = 0;
}

//---------------------------------------------------------------------------------------------------------

Artykul& Artykul::operator=(const Artykul &a)
{
    if(this == &a)
        return *this;

    m_nazwa = a.m_nazwa;
    m_cena = a.m_cena;

    return *this;
}


bool Artykul::operator==(const Artykul &a)
{
    return (m_nazwa == a.m_nazwa && m_cena == a.m_cena);
}

bool Artykul::operator!=(const Artykul &a)
{
    return !(*this == a);
}


ostream& operator<<(ostream &ret, Artykul &a)
{
    ret << a.m_nazwa << " " << a.m_cena << endl;
    return ret;
}

istream& operator>>(istream &ret, Artykul &a)
{
    ret >> a.m_nazwa >> a.m_cena;
    return ret;
}
