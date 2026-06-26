#include <iostream>
#include <string>

struct Material {
    std::string nombre;
    int cantidad;
    double precioUnitario;
};

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    const int MAX_MATERIALES = 100;
    Material listaMateriales[MAX_MATERIALES];
    
    int contadorMateriales = 0;
    double costoManoObra = 0.0;
    char continuar = 's';

    std::cout << "-------------------------------------------\n";
    std::cout << " GENERADOR DE PRESUPUESTOS DE MANTENIMIENTO\n";
    std::cout << "-------------------------------------------\n\n";

    while ((continuar == 's' || continuar == 'S') && contadorMateriales < MAX_MATERIALES) {
        
        std::cout << "Ingrese el nombre del material: ";
        std::cin.ignore();
        std::getline(std::cin, listaMateriales[contadorMateriales].nombre);

        std::cout << "Ingrese la cantidad requerida: ";
        std::cin >> listaMateriales[contadorMateriales].cantidad;

        std::cout << "Ingrese el precio unitario: $";
        std::cin >> listaMateriales[contadorMateriales].precioUnitario;

        contadorMateriales++;

        if (contadorMateriales < MAX_MATERIALES) {
            std::cout << "¿Desea agregar otro material? (s/n): ";
            std::cin >> continuar;
            std::cout << "\n";
        } else {
            std::cout << "Se ha alcanzado el límite máximo de materiales (100).\n\n";
        }
    }

    std::cout << "Ingrese el costo estimado de la mano de obra: $";
    std::cin >> costoManoObra;
    std::cout << "\n";

    std::cout << "-------------------------------------------\n";
    std::cout << "         RESUMEN DEL PRESUPUESTO           \n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Material\t\tCant.\tP. Unit\t\tTotal\n";
    std::cout << "-------------------------------------------\n";

    double subtotalMateriales = 0.0;

    for (int i = 0; i < contadorMateriales; i++) {
        double totalMaterial = listaMateriales[i].cantidad * listaMateriales[i].precioUnitario;
        subtotalMateriales += totalMaterial;

        std::cout << listaMateriales[i].nombre << "\t\t" 
                  << listaMateriales[i].cantidad << "\t$" 
                  << listaMateriales[i].precioUnitario << "\t\t$" 
                  << totalMaterial << "\n";
    }

    double costoTotalGeneral = subtotalMateriales + costoManoObra;

    std::cout << "-------------------------------------------\n";
    std::cout << "Subtotal Materiales:\t\t\t$" << subtotalMateriales << "\n";
    std::cout << "Mano de Obra:\t\t\t\t$" << costoManoObra << "\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "COSTO TOTAL ESTIMADO:\t\t\t$" << costoTotalGeneral << "\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Integrantes del Grupo 7:\n";
    std::cout << "- Jesus Perez C.I: 30.754.920.\n";
    std::cout << "- Eslaimer Peña C.I: 31.546.912.\n";
    return 0;
}
