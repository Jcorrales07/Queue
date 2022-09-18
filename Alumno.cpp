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

    auto *alumno = dynamic_cast<Alumno*>(obj);
    if (alumno->getNombre() == this->nombre && alumno->getCuenta() == this->cuenta) {
        return true;
    }
    
    return false;
}

string Alumno::toString(){
    return " { nombre: " + getNombre() + ", cuenta: " + getCuenta() + " } ";
}

string Alumno::getNombre(){
    return nombre;
}

string Alumno::getCuenta(){
    return cuenta;
}