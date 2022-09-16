#ifndef TDACOLA_H
#define TDACOLA_H

#include "Object.h"
#include "Alumno.h"

class TDACola
{
	public:
        // Metodos de la clase
        TDACola();
        virtual ~TDACola();

		virtual void                    anula() = 0; //anula la cola
		virtual void                    encolar(Object*) = 0; //agrega un elemento al final de la cola
		virtual void                    imprime_cola() = 0; //imprime la cola
		virtual Object*                 desencolar(int) = 0; //suprime el elemento en la posicion indicada (el primero siempre)
		virtual Object*                 primero() = 0; //devuelve el primer elemento de la cola
		virtual bool                    estaVacia() = 0; //devuelve true si la cola esta vacia
		
	protected:
        Object** array;
        int capacidad;
        int length;
};

#endif // TDACOLA_H