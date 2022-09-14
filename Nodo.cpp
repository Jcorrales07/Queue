#include "Nodo.h"

Nodo::Nodo(){
	siguiente = nullptr;
	item = nullptr;
	anterior = nullptr;
}

Nodo::~Nodo(){
	if(siguiente)
		delete siguiente;
	if(item)
		delete item;
}

void Nodo::setSiguiente(Nodo* siguiente){
	this->siguiente = siguiente;
}

void Nodo::setItem(Object* item){
	this->item = item;
}

Object* Nodo::getItem(){
	return this->item;
}

Nodo* Nodo::getSiguiente(){
	return siguiente;
}

void Nodo::setAnterior(Nodo* anterior){
	this->anterior = anterior;
}

Nodo* Nodo::getAnterior(){
	return anterior;
}