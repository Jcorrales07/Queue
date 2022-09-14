#ifndef ALUMNO_H
#define ALUMNO_H

#include "Object.h"

class Alumno: public Object {

    public:

        Alumno();
        Alumno(string nombre, string cuenta);

        bool                                   equals(Object*);
        string                                 toString();

        string                                 getNombre();
        string                                 getCuenta();

    private:
        string nombre, cuenta;
};

#endif