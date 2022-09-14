cmake_minimum_required(VERSION 3.23)
project(Cola)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cola main.cpp
                    Object.cpp
                    Object.h
                    TDACola.cpp
                    TDACola.h
                    ArrayQueue.cpp
                    ArrayQueue.h
                    LinkedQueue.cpp
                    LinkedQueue.h
                    Nodo.cpp
                    Nodo.h
                    Alumno.cpp
                    Alumno.h)