/*#include "LinkedQueue.h"

*//*
 * Constructor
 * **//*
LinkedQueue::LinkedQueue(){
    head = nullptr;
}

*//*
 * Descructor ( no se si esta bueno )
 * **//*
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
}*/



