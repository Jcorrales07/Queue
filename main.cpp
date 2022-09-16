#include <iostream>
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "Alumno.h"


void                menuCola();
void                operacionesCola();
void                arrayCola();
ArrayQueue          *cola = new ArrayQueue();


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
                operacionesCola();
                break;
            case 3:
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
            cola->encolar(nuevoAlumno);

        } else if (opcion == 2) {

            cola->desencolar(0);

        } else if (opcion == 3) {

            auto* primerAlumno = dynamic_cast<Alumno *>(cola->primero());

            string respuesta = (primerAlumno) ? "El primer alumno es " + primerAlumno->getNombre()
                                                : "La cola esta vacia";

            std::cout << respuesta << std::endl;

            //delete primerAlumno;
            primerAlumno = nullptr;

        } else if (opcion == 4) {

            string respuesta = (cola->estaVacia()) ? "La cola esta vacia"
                                                    : "La cola NO esta vacia";
            std::cout << respuesta << std::endl;

        } else if (opcion == 5) {
            try {
                cola->imprime_cola();
            } catch (std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        } else if (opcion == 6) {

            menuCola();

        } else {
            std::cout << "Opcion no valida" << std::endl;
        }
    } while (opcion != 6);
}