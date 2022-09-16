#include "Alumno.h"

Alumno::Alumno(){
    this->nombre = "";
    this->cuenta = "";
}

Alumno::Alumno(string nombre, string cuenta){
    this->nombre = nombre;
    this->cuenta = cuenta;
}

bool Alumno::equals(Object* obj){
    return true;
}

string Alumno::toString(){
    return "Nombre: " + nombre + ", Cuenta: " + cuenta;
}

string Alumno::getNombre(){
    return nombre;
}

string Alumno::getCuenta(){
    return cuenta;
}