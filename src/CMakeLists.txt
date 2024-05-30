cmake_minimum_required(VERSION 3.5)

project(cpp-opp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp-opp
    main.cpp
    Lista.h
    Wezel.h

    przedsiebiorstwo.h przedsiebiorstwo.cpp
    artykul.h artykul.cpp

            sklep.h sklep.cpp
            sprzedawca.h sprzedawca.cpp

                    internetowy.h internetowy.cpp

            restauracja.h restauracja.cpp)
