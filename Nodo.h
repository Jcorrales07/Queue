#ifndef NODO_H
#define NODO_H

#include "Object.h"

class Nodo
{
	public:

		Nodo();
        Nodo(Nodo *anterior, Object *pObject, Nodo *siguiente);
        ~Nodo();

		void            setAnterior(Nodo* anterior);
		Nodo*           getAnterior();
		void            setItem(Object* item);
		Object*         getItem();
		void            setSiguiente(Nodo* siguiente);
		Nodo*           getSiguiente();

	protected:
		Nodo*           siguiente;
		Object*         item;
		Nodo*           anterior;
};

#endif