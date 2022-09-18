#include <iostream>
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "Alumno.h"


void                menuCola();
void                operacionesCola();
void                arrayCola();
void                linkedCola();

ArrayQueue          *arrayQueue = nullptr;
LinkedQueue         *linkedQueue = nullptr;

int main() {
    menuCola();
    return 0;
}

void menuCola() {

    int opcion = 0;

    do {
        std::cout << std::endl;
        std::cout << "[=== Menu Principal ===]" << std::endl;
        std::cout << "1. Trabajar con ArrayQueue" << std::endl;
        std::cout << "2. Trabajar con LinkedQueue" << std::endl;
        std::cout << "3. Regresar al Menu Principal" << std::endl;
        std::cout << "Opcion #";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                arrayCola();
                break;
            case 2:
                linkedCola();
                break;
            case 3:
                std::cout << "Regresando al Menu Principal..." << std::endl;
                //menuPrincipal();
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
                break;
        }

    } while (opcion != 4);
}

void operacionesCola() {
    std::cout << std::endl;
    std::cout << "1. Encolar (queue) " << std::endl;
    std::cout << "2. Desencolar (dequeue) " << std::endl;
    std::cout << "3. Ver Frente (peek) " << std::endl;
    std::cout << "4. Verificar si esta vacia" << std::endl;
    std::cout << "5. Imprimir elementos" << std::endl;
    std::cout << "6. Regresar al Menu Principal" << std::endl;
}

void arrayCola() {

    arrayQueue = new ArrayQueue();
    int opcion = 0;

    do {
        operacionesCola();
        std::cout << "Opcion #";
        std::cin >> opcion;

        std::cout << std::endl;

        if (opcion == 1) {

            std::cout << "[=== Funcion Encolar ===]" << std::endl;
            std::cout << "Ingrese el nombre del alumno :";
            std::string nombre;
            std::cin >> nombre;
            std::cout << "Ingrese el codigo del alumno :";
            std::string codigo;
            std::cin >> codigo;

            Object *nuevoAlumno = new Alumno(nombre, codigo);
            arrayQueue->encolar(nuevoAlumno);

        } else if (opcion == 2) {

            auto *alumnoDesencolado = dynamic_cast<Alumno *>(arrayQueue->desencolar(0));
            auto resultado= (alumnoDesencolado) ? "Alumno desencolado: " + alumnoDesencolado->toString() : "No hay elementos en cola";
            std::cout << resultado << std::endl;

        } else if (opcion == 3) {

            auto* primerAlumno = dynamic_cast<Alumno *>(arrayQueue->primero());

            string respuesta = (primerAlumno) ? "El primer alumno en cola es: " + primerAlumno->toString()
                                                : "La cola esta vacia";

            std::cout << respuesta << std::endl;

            //delete primerAlumno;
            primerAlumno = nullptr;

        } else if (opcion == 4) {

            string respuesta = (arrayQueue->estaVacia()) ? "La cola esta vacia"
                                                    : "La cola NO esta vacia";
            std::cout << respuesta << std::endl;

        } else if (opcion == 5) {

                arrayQueue->imprime_cola();

        } else if (opcion == 6) {

//            menuPrincipal();

        } else {
            std::cout << "Opcion no valida" << std::endl;
        }
    } while (opcion != 6);
}

void linkedCola() {

    linkedQueue = new LinkedQueue();
    int opcion = 0;

    do {
        operacionesCola();
        std::cout << "Opcion #";
        std::cin >> opcion;
        std::cout << std::endl;

        if (opcion == 1) {

            std::cout << "[=== Funcion Encolar ===]" << std::endl;
            std::cout << "Ingrese el nombre del alumno :";
            std::string nombre;
            std::cin >> nombre;
            std::cout << "Ingrese el codigo del alumno :";
            std::string codigo;
            std::cin >> codigo;

            Object *nuevoAlumno = new Alumno(nombre, codigo);
            linkedQueue->encolar(nuevoAlumno);

        } else if (opcion == 2) {

//            arrayQueue->desencolar(0);

        } else if (opcion == 3) {

            auto* primerAlumno = dynamic_cast<Alumno *>(linkedQueue->primero());

            string respuesta = (primerAlumno) ? "El primer alumno es " + primerAlumno->toString()
                                              : "La cola esta vacia";

            std::cout << respuesta << std::endl;

            primerAlumno = nullptr;

        } else if (opcion == 4) {
//
//            string respuesta = (arrayQueue->estaVacia()) ? "La cola esta vacia"
//                                                         : "La cola NO esta vacia";
//            std::cout << respuesta << std::endl;

        } else if (opcion == 5) {

                linkedQueue->imprime_cola();

        } else if (opcion == 6) {

//            menuPrincipal();

        } else {
            std::cout << "Opcion no valida" << std::endl;
        }

    } while (opcion != 6);
}