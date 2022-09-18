#include "LinkedQueue.h"
#include "Alumno.h"
#include "iostream"

/*
 * Constructor
 * */
LinkedQueue::LinkedQueue(){
    head = nullptr;
}

/*
 * Destructor ( no se si esta bueno )
 * */
LinkedQueue::~LinkedQueue(){
    if(head) {
        Nodo* actual = head;

        while(actual->getSiguiente() != nullptr) {
            Nodo* temp = actual->getSiguiente();
            delete temp;
        }
        delete head;
        delete actual;
    }
}

/*
 * Anula la cola, limpia toda la cola y crea una nueva cola vacia
 * **/
void LinkedQueue::anula() {
    if(!estaVacia()) {
        Nodo* actual = head;

        while(actual->getSiguiente() != nullptr) {
            Nodo* temp = actual->getSiguiente();
            delete temp;
        }
        delete head;
        delete actual;
    }

    head = nullptr;
}

/*
 * Devuelve el primer elemento de la cola
 * **/
Object* LinkedQueue::primero() {
    if (estaVacia()) {
        return nullptr;
    }
    return head->getItem();
}

/*
 * Agrega un elemento (alumno) al final de la cola
 * **/
void LinkedQueue::encolar(Object* obj) {
    auto *alumno = dynamic_cast<Alumno*>(obj); // casteo el objeto a Alumno

    if (estaVacia()) {
        // asignamos el primer elemento de la cola
        head = new Nodo(nullptr, alumno, nullptr);
        return;
    }

    Nodo *actual = head;
    // vamos a recorrer la lista hasta llegar al ultimo nodo
    while(actual->getSiguiente() != nullptr) {
        std::cout << "tiene siguiente" << std::endl;
        actual = actual->getSiguiente();
    }

    // creamos un nuevo nodo con el alumno y lo enlazamos
    Nodo *nuevoNodo = new Nodo(nullptr, alumno, nullptr);
    nuevoNodo->setAnterior(actual);
    actual->setSiguiente(nuevoNodo);
}

/*
 * Quita el primer elemento de la cola
 * @param pos no se usa
 * **/
Object* LinkedQueue::desencolar(int pos) {

    if(estaVacia()) {
        return nullptr;
    }

    Nodo *primerNodo = head; // [cabeza actual]

    if (head->getSiguiente() == nullptr) {
        // si solo hay un elemento en la cola
        head = nullptr;
        return primerNodo->getItem();
    }

    head = head->getSiguiente(); // [cabeza actual] -> [cabeza siguiente]; [cabeza actual] = [cabeza siguiente]
    Nodo *actual = head;

    // REVISAR ESTE CODIGO, PUEDE QUE ESTE MAL
    // movemos toda la cola una posicion hacia adelante
    while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente(); // avanzamos al siguiente nodo
        actual->setAnterior(actual->getAnterior()); // asignamos el apuntador del nodo anterior al actual
        actual->setItem(actual->getItem()); //asignamos el item que tiene el nodo actual
        actual->setSiguiente(actual->getSiguiente()); // asignamos el apuntador del nodo siguiente al actual
    }

    return primerNodo->getItem();
}

/*
 * Revisa si la cola esta vacia
 * **/
bool LinkedQueue::estaVacia() {
    return head == nullptr;
}

/*
 * Imprime la cola
 * **/
void LinkedQueue::imprime_cola() {
    if (estaVacia()) {
        std::cout << "La cola esta vacia" << std::endl;
        return;
    }

    Nodo *actual = head;
    auto *alumno = dynamic_cast<Alumno*>(actual->getItem()); // casteo el objeto a Alumno
    std::cout << " [ " << alumno->toString() << " ] "<< std::endl;

    while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente(); // actualizamos el actual
        alumno = dynamic_cast<Alumno*>(actual->getItem()); // casteo el objeto a Alumno
        std::cout << " [ " << alumno->toString() << " ] "<< std::endl;
        alumno = nullptr;
    }
}


