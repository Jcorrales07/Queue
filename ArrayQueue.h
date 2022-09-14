#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "TDACola.h"
#include "Alumno.h"

class ArrayQueue : public TDACola {

    public:
        ArrayQueue();
        ~ArrayQueue() override;

        void                        anula();
        Object*                     primero();
        void                        encolar(Object*);
        Object*                     desencolar(int);
        bool                        estaVacia();
        void                        imprime_cola();

    protected:
        Alumno** array;
        int capacidad;
        int length;
};

#endif // ARRAYQUEUE_H
