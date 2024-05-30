#include "sprzedawca.h"


int Sprzedawca::m_liczba_obiektow = 0;

//---------------------------------------------------------------------------------------------------------

Sprzedawca::Sprzedawca()
{
    m_liczba_obiektow++;

#ifdef _DEBUG
    cout << "/ Sprzedawca() /      liczba obiektow Sprzedawca: " << m_liczba_obiektow << endl;
#endif
}


Sprzedawca::Sprzedawca(string imie, double wynagrodzenie)
{
    m_liczba_obiektow++;

#ifdef _DEBUG
    cout << "/ Sprzedawca(string, double) /      "
            "liczba obiektow Sprzedawca: " << m_liczba_obiektow << endl;
#endif

    m_imie = imie;
    m_wynagrodzenie = wynagrodzenie;
}


Sprzedawca::~Sprzedawca()
{
    m_liczba_obiektow--;

#ifdef _DEBUG
    cout << "/ ~Sprzedawca() /      liczba obiektow Sprzedawca: " << m_liczba_obiektow << endl;
#endif
}


Sprzedawca::Sprzedawca(const Sprzedawca &s)
{
    m_liczba_obiektow++;

#ifdef _DEBUG
    cout << "/ Sprzedawca(const Sprzedawca &s) /    "
            "liczba obiektow Sprzedawca: " << m_liczba_obiektow << endl;
#endif

    m_imie = s.m_imie;
    m_wynagrodzenie = s.m_wynagrodzenie;
}

//---------------------------------------------------------------------------------------------------------

string Sprzedawca::imie() { return m_imie; }
void Sprzedawca::imie(string imie) { m_imie = imie; }

double Sprzedawca::wynagrodzenie() { return m_wynagrodzenie; }
void Sprzedawca::setWynagrodzenie(double wynagrodzenie)
{
    if(wynagrodzenie > 0)
        m_wynagrodzenie = wynagrodzenie;
    else
        m_wynagrodzenie = 0;
}

//---------------------------------------------------------------------------------------------------------

Sprzedawca& Sprzedawca::operator=(const Sprzedawca &s)
{
    if(this == &s)
        return *this;

    m_imie = s.m_imie;
    m_wynagrodzenie = s.m_wynagrodzenie;

    return *this;
}


bool Sprzedawca::operator==(const Sprzedawca &s)
{
    return (m_imie == s.m_imie && m_wynagrodzenie == s.m_wynagrodzenie);
}

bool Sprzedawca::operator!=(const Sprzedawca &s)
{
    return !(*this == s);
}


ostream& operator<<(ostream &ret, Sprzedawca &s)
{
    ret << s.m_imie << endl;
    ret << s.m_wynagrodzenie << endl;
    return ret;
}


istream& operator>>(istream &ret, Sprzedawca &s)
{
    ret >> s.m_imie >> s.m_wynagrodzenie;
    return ret;
}
