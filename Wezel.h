#ifndef WEZEL_H
#define WEZEL_H


template<class T>
class Node
{

public:
    Node *m_next;
    Node *m_prev;
    T m_obiekt;


    Node()
        {
            m_next = nullptr;
            m_prev = nullptr;
        }


    ~Node()
        {
            if(m_prev && m_next) {
                m_prev->m_next = m_next;
                m_next->m_prev = m_prev;
            }

            else if(m_prev)
                m_prev->m_next = nullptr;

            else if(m_next)
                m_next->m_prev = nullptr;

        }
};



#endif // WEZEL_H
