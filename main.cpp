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
        std::cout << "1. Trabajar con ArrayQueue" << std::endl;
        std::cout << "2. Trabajar con LinkedQueue" << std::endl;
        std::cout << "3. Regresar al Menu Principal" << std::endl;
        std::cout << "Opcion #";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                operacionesCola();
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
    std::cout << "1. Encolar (queue) " << std::endl;
    std::cout << "2. Desencolar (dequeue) " << std::endl;
    std::cout << "3. Ver Frente (peek) " << std::endl;
    std::cout << "4. Verificar si está vacía" << std::endl;
    std::cout << "5. Imprimir elementos" << std::endl;
    std::cout << "6. Regresar al Menu Principal" << std::endl;
}

void arrayCola() {
    int opcion = 0;
    std::cout << "Opcion #";
    std::cin >> opcion;

    switch (opcion) {
        case 1:
            std::cout << "[=== Funcion Encolar ===]" << std::endl;
            std::cout << "Ingrese el nombre del alumno: ";
            std::string nombre;
            std::cin >> nombre;
            std::cout << "Ingrese el codigo del alumno: ";
            std::string codigo;
            std::cin >> codigo;
            Object *nuevoAlumno = new Alumno(nombre, codigo);
            cola->encolar(nuevoAlumno);
            break;

//        case 2:
//            cola->imprime_cola();
//            break;
//        case 3:
//            break;
//        case 4:
//            break;
//        case 5:
            break;
//        case 6:
            //menuPrincipal();
//            break;
//        default:
//            std::cout << "Opcion no valida" << std::endl;
//            break;
    }
}
