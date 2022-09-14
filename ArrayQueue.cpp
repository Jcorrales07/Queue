#include "ArrayQueue.h"
#include "iostream"
/*
 * Constructor de una cola tipo Array
 * **/
ArrayQueue::ArrayQueue() {
    length = 0;
    capacidad = 10;
    array = new Alumno *[capacidad];
    for (int i = 0; i < capacidad; i++) {
        array[i] = nullptr;
    }
}

/*
 * Destructor de una cola tipo Array
 * **/
ArrayQueue::~ArrayQueue() {
    //libera el contenido de las casillas
    for (int i = 0; i < capacidad; i++) {
        if (array[i] != nullptr) {
            delete array[i];
        }
    }
    //libera el arreglo
    delete[] array;
}

/*
 * Limpia la cola
 * **/
void ArrayQueue::anula() {
    TDACola::anula();
}

/*
 * Devuelve el primer elemento de la cola
 * **/
Object* ArrayQueue::primero() {
    return TDACola::primero();
}

/*
 * Inserta un elemento al final de la cola
 * **/
void ArrayQueue::encolar(Object* alumno) {
    TDACola::encolar(alumno);
}

/*
 * Elimina el primer elemento de la cola
 * **/
Object* ArrayQueue::desencolar(int posicion) {
    return TDACola::desencolar(posicion);
}

/*
 * Devuelve true si la cola está vacía
 * **/
bool ArrayQueue::estaVacia() {
    return TDACola::estaVacia();
}

/*
 * Imprime la cola
 * **/
void ArrayQueue::imprime_cola() {
    TDACola::imprime_cola();
}

