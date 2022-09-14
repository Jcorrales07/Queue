#ifndef NODO_H
#define NODO_H

#include "Object.h"

class Nodo
{
	public:

		Nodo();
		~Nodo();
		void            setItem(Object* item);
		Object*         getItem();
		void            setSiguiente(Nodo* siguiente);
		Nodo*           getSiguiente();
		void            setAnterior(Nodo* anterior);
		Nodo*           getAnterior();

	protected:

		Nodo*           siguiente;
		Object*         item;
		Nodo*           anterior;
};

#endif