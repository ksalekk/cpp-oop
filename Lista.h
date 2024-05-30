#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <fstream>
#include "Wezel.h"
using namespace std;

template<class T>
class Lista
{
private:
    Node<T> *m_begin;
    Node<T> *m_end;

public:
    Lista()
        {
            m_begin = nullptr;
            m_end = nullptr;
        }

    ~Lista()
        {
            while(m_begin) {
                Node<T> *tmp = m_begin;
                m_begin = m_begin->m_next;
                delete tmp;
            }
            m_end = nullptr;
        }

//------------------------------------------------------------------------------------------------------

    T& getElement(int numer) const
        {
            if(numer < 0)
                throw out_of_range(" [!]    Nie ma elementu o takim numerze ");

            Node<T> *tmp = m_begin;
            for (int i=0; i<numer; i++) {
                if(!tmp->m_next)
                    throw out_of_range(" [!]    Nie ma elementu o takim numerze ");

                tmp = tmp->m_next;
            }

            return tmp->m_obiekt;
        }




    void dodajNaPoczatek(T nowy)
        {
            if(!m_begin) {
                m_begin = new Node<T>;
                m_begin->m_obiekt = nowy;
                m_end = m_begin;
            }

            else {
                Node<T> *tmp = new Node<T>;
                tmp->m_obiekt = nowy;
                tmp->m_next = m_begin;
                m_begin->m_prev = tmp;
                m_begin = tmp;
            }
        }




    void dodajNaKoniec(T nowy)
        {
            if(!m_begin) {
                m_begin = new Node<T>;
                m_begin->m_obiekt = nowy;
                m_end = m_begin;
            }

            else {
                Node<T> *tmp = new Node<T>;
                tmp->m_obiekt = nowy;
                tmp->m_prev = m_end;
                m_end->m_next = tmp;
                m_end = tmp;
            }
        }


    // wstawia ZA element
    void wstawElement(int numer, T nowy)
        {
            if(numer < 0)
                throw out_of_range(" [!]    Nie ma elementu o takim numerze ");

            Node<T> *tmp = m_begin;
            for (int i=0; i<numer; i++) {
                if(!tmp->m_next)
                    throw out_of_range(" [!]    Nie ma elementu o takim numerze ");

                tmp = tmp->m_next;
            }

            if(!(tmp->m_next)) {
                dodajNaKoniec(nowy);
                return;
            }

            // aby nie zgubic tmp->m_next
            Node<T> *tmp2 = tmp->m_next;

            // miejsce na nowy obiekt
            tmp->m_next = new Node<T>;
            tmp->m_next->m_obiekt = nowy;

            // polaczenia
            tmp->m_next->m_prev = tmp;
            tmp->m_next->m_next = tmp2;
            tmp2->m_prev = tmp->m_next;
        }



    void usunElement(int numer)
        {
            if(numer < 0)
                throw out_of_range(" [!]    Nie ma elementu o takim numerze ");

            Node<T> *tmp = m_begin;
            for(int i=0; i<numer; i++) {
                if(!tmp->m_next)
                    throw out_of_range(" [!]    Nie ma elementu o takim numerze ");

                tmp = tmp->m_next;
            }


            if(tmp == m_begin)
                m_begin = tmp->m_next;

            if (tmp == m_end)
                m_end = tmp->m_prev;

            delete tmp;

        }

//------------------------------------------------------------------------------------------------------

    void pokaz() const
        {
            if(!m_begin) {
                cout << "Lista jest pusta" << endl << endl;
                return;
            }

            Node<T> *tmp = m_begin;
            int cnt = 0;
            cout << "DOSTEPNE OBIEKTY: " << endl;
            while(tmp) {
                cout << "Obiekt nr " << cnt++ << endl;
                cout << tmp->m_obiekt << endl << endl;
                tmp = tmp->m_next;
            }
        }



    void zmienKolejnosc(int nr_1, int nr_2)
        {
            if(nr_1 < 0 || nr_2 < 0)
                throw out_of_range(" [!]    Nie ma elementu/elementow o takim numerze ");

            if(nr_1 == nr_2)
                return;


            if (nr_1 > nr_2) {
                int temp = nr_2;
                nr_2 = nr_1;
                nr_1 = temp;
            }


            Node<T> *tmp1 = m_begin;
            Node<T> *tmp2 = m_begin;

            for (int i=0; i<nr_1; i++) {
                if(!tmp1->m_next)
                    throw out_of_range(" [!]    Nie ma elementu o takim numerze");

                tmp1 = tmp1->m_next;
            }

            for (int i=0; i<nr_2; i++) {
                if(!tmp2->m_next)
                    throw out_of_range(" [!]    Nie ma elementu o takim numerze");

                tmp2 = tmp2->m_next;
            }

//            wstawElement(nr_2, tmp1->m_obiekt);
//            wstawElement(nr_1, tmp2->m_obiekt);
//            usunElement(nr_2+1);
//            usunElement(nr_1);

            T temp = tmp1->m_obiekt;
            tmp1->m_obiekt = tmp2->m_obiekt;
            tmp2->m_obiekt = temp;
        }

//------------------------------------------------------------------------------------------------------

    void zapiszDoPliku(string nazwa) const
        {
            ofstream ofs(nazwa);
                if(!ofs.good()) {
                    ofs.close();
                    throw runtime_error(" [!]   Blad wczytywania pliku");
                }

            Node<T> *tmp = m_begin;
            while(tmp) {
                ofs << tmp->m_obiekt << endl;
                tmp = tmp->m_next;
            }

            ofs.close();
        }



    void wczytajZPliku(string nazwa)
        {
            ifstream ifs(nazwa);
                if(!ifs.good()) {
                    ifs.close();
                    throw runtime_error(" [!]   Blad wczytywania pliku. "
                                        "Upewnij sie ze plik istnieje");
                }

            T nowy;
            while(ifs >> nowy) {
                dodajNaKoniec(nowy);
                nowy = T(); // "czyszczenie" zmiennej --> ma to sens tylko dla moich klas
                //T nowy;
            }

            ifs.close();
        }

//------------------------------------------------------------------------------------------------------

    Lista& operator=(const Lista &l2)
        {
            if(this == &l2)
                return *this;

            if(m_begin)
                this->~Lista<T>();

            Node<T> *tmp = l2.m_begin;
            while(tmp) {
                dodajNaKoniec(tmp->m_obiekt);
                tmp = tmp->m_next;
            }

            return *this;
        }



    bool operator==(const Lista &l2) const
        {
            Node<T> *tmp1 = m_begin;
            Node<T> *tmp2 = l2.m_begin;

            while(tmp1 && tmp2) {
                if(tmp1->m_obiekt != tmp2->m_obiekt)
                    return 0;

                tmp1 = tmp1->m_next;
                tmp2 = tmp2->m_next;
            }

            if(!(tmp1 || tmp2))
                return 1;
            else
                return 0;
        }

//------------------------------------------------------------------------------------------------------

    Lista operator+(Lista &l2) const
    {
        Lista<T> ret;
        ret = *this;
        Node<T> *tmp = l2.m_begin;
        while(tmp) {
            ret.dodajNaKoniec(tmp->m_obiekt);
            tmp = tmp->m_next;
        }
        return ret;
    }



    void moveToFront(int numer)
        {
            if (numer < 0)
                throw out_of_range(" [!]    Nie ma elementu o takim numerze ");

            if(numer == 0)
                return;

            try {
                dodajNaPoczatek(getElement(numer));
                usunElement(numer+1);
            }
                catch (out_of_range err) {
                    throw err;
                }
        }
};



#endif // LISTA_H
