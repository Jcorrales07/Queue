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
    if (!estaVacia()) {
        return array[0];
    }

    return nullptr;
//    return  TDACola::primero();
}

/*
 * Inserta un elemento al final de la cola
 * **/
void ArrayQueue::encolar(Object* alumno) {

    if (length == capacidad) {

        auto** temp = new Alumno *[capacidad * 2]; // creamos un arreglo temporal con el tamaño duplicado

        // copiamos los elementos del arreglo original al arreglo temporal
        for (int i = 0; i < capacidad; i++) {
            temp[i] = array[i];
            delete array[i]; // liberamos la memoria del arreglo original
        }

        delete[] array; // eliminamos el arreglo original
        array = temp; // lo sutituimos por el arreglo temporal
        capacidad *= 2; // duplicamos la capacidad
    }

    // Agregamos el elemento al final de la cola
    array[length] = dynamic_cast<Alumno *>(alumno);
    length++;

}

/*
 * Elimina el primer elemento de la cola
 * **/
Object* ArrayQueue::desencolar(int posicion) {
    if (!estaVacia()) {
        Alumno* temp = array[posicion];
        for (int i = posicion; i < length; i++) {
            array[i] = array[i + 1];
        }
        length--;
        return temp;
    }
    return nullptr;
}

/*
 * Devuelve true si la cola está vacía
 * **/
bool ArrayQueue::estaVacia() {
//    return TDACola::estaVacia();
    return this->array[0] == nullptr;
}

/*
 * Imprime la cola
 * **/
void ArrayQueue::imprime_cola() {
    if (!estaVacia()) {

        try {
            for (int i = 0; i < length; i++) {
                std::cout << " [ " + array[i]->toString() + " ] ";
            }
        }
        catch (std::exception& e) {
            std::cout << "No se por que trono" << e.what() << std::endl;
        }
    } else {
        std::cout << "La cola esta vacia" << std::endl;
    }
    std::cout << std::endl;
}

