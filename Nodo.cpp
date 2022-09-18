#include "Nodo.h"

/*
 * Constructor por default
 * **/
Nodo::Nodo() {
    anterior = nullptr;
    item = nullptr;
    siguiente = nullptr;
}

/*
 * Constructor con parametros
 * **/
Nodo::Nodo(Nodo* anterior, Object *pObject, Nodo* siguiente) {
    this->anterior = anterior;
    this->item = pObject;
    this->siguiente = siguiente;
}

/*
 * Destructor
 * **/
Nodo::~Nodo(){
	if(siguiente)
		delete siguiente;
	if(item)
		delete item;
}

/*
 * Setea el objeto para el nodo
 * **/
void Nodo::setItem(Object* item){
	this->item = item;
}

/*
 * Devuelve el objeto del nodo
 * **/
Object* Nodo::getItem(){
	return this->item;
}

/*
 * Setea el nodo siguiente
 * **/
void Nodo::setSiguiente(Nodo* siguiente){
    this->siguiente = siguiente;
}

/*
 * Devuelve el nodo siguiente
 * **/
Nodo* Nodo::getSiguiente(){
	return siguiente;
}

/*
 * Setea el nodo anterior
 * **/
void Nodo::setAnterior(Nodo* anterior){
	this->anterior = anterior;
}

/*
 * Devuelve el nodo anterior
 * **/
Nodo* Nodo::getAnterior(){
	return anterior;
}

// Metodos de object

bool Nodo::equals(Object *) {
    return false;
}

string Nodo::toString() {
    return std::string("Nodo {  item: " + item->toString() + "}");
}
