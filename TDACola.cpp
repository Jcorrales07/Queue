#include "iostream"
#include "TDACola.h"

/*
 * Constructor de la clase
 * **/
TDACola::TDACola() {
    length = 0;
    capacidad = 10;
    array = new Alumno *[capacidad];
}

/*
 * Destructor de la clase
 * **/
TDACola::~TDACola() {
    for (int i = 0; i < capacidad; i++) {
        if (array[i]) {
            delete array[i];
        }
    }
    delete[] array;
}

/*
 * Anula la cola, limpia toda la cola y crea una nueva cola vacia
 * **/
void TDACola::anula() {
    if (!estaVacia()) {
        for (int i = 0; i < capacidad; i++) {
            if (array[i]) {
                delete array[i];
            }
        }
        delete[] array;
        length = 0;
        capacidad = 10;
        array = new Alumno *[capacidad];
    }
}

/*
 * Agrega un elemento (alumno) al final de la cola
 * **/
void TDACola::encolar(Object* alumno) {
    // Si la cola está llena, se duplica el tamaño del arreglo
    if (length == capacidad) {
        Alumno** temp = new Alumno *[capacidad * 2]; // creamos un arreglo temporal con el tamaño duplicado
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
 * Imprime la cola
 * **/
void TDACola::imprime_cola() {
    if (!estaVacia()) {
        for (int i = 0; i < length; i++) {
            std::cout << " [ " << array[i]->getNombre() << ", " << array[i]->getCuenta() << " ] ";
        }
    } else {
        std::cout << "La cola esta vacia" << std::endl;
    }
    std::cout << std::endl;
}


/*
 * Esta funcion quita el elemento en la posicion indicada
 * y mueve los elementos en los huecos correspondientes
 * **/
Object* TDACola::desencolar(int posicion) {
    if (!estaVacia()) {
        Object* temp = array[posicion];
        for (int i = posicion; i < length; i++) {
            array[i] = array[i + 1];
        }
        length--;
        return temp;
    }
    return nullptr;
}

/*
 * Esta funcion verifica que la cola no este vacia y
 * devuelve el primer elemento de la cola de lo contrario
 * devuelve nullptr
 * **/
Object* TDACola::primero() {
    if (!estaVacia()) {
        return array[0];
    }

    return nullptr;
}

/*
 * Esta funcion verifica que la cola no este vacia y
 * devuelve true si la cola esta vacia
 * **/
bool TDACola::estaVacia() {
    return (array[0] == nullptr);
}