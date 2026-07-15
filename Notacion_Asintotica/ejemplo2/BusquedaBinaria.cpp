#include <iostream>
#include <vector>

// Analizando la complejidad de esta función:
// En cada iteración del bucle 'while', calculamos el punto medio y descartamos
// la mitad de los elementos que nos quedan por revisar.
// - Si empezamos con 8 elementos: pasamos a 4 -> 2 -> 1. Solo toma 3 pasos.
// - Matemáticamente, el número de pasos máximo para un tamaño 'n' es log₂(n).
//
// Complejidad Asintótica del Peor Caso: O(log n) - Logarítmica
int busquedaBinaria(const std::vector<int>& arr, int objetivo) {
    int izquierda = 0;
    int derecha = arr.size() - 1;

    while (izquierda <= derecha) { // Este bucle NO se ejecuta 'n' veces, se reduce a la mitad en cada ciclo
        int medio = izquierda + (derecha - izquierda) / 2; // O(1)

        // ¿Encontramos el objetivo en el centro?
        if (arr[medio] == objetivo) { 
            return medio; // Mejor caso: O(1) si estaba justo en medio
        }

        // Si el objetivo es mayor, descartamos la mitad izquierda
        if (arr[medio] < objetivo) {
            izquierda = medio + 1; 
        } 
        // Si el objetivo es menor, descartamos la mitad derecha
        else {
            derecha = medio - 1; 
        }
    }
    return -1; // Peor caso: El elemento no existe, pero solo nos tomó log₂(n) pasos darnos cuenta
}

int main() {
    // El arreglo DEBE estar ordenado para que la búsqueda binaria funcione
    std::vector<int> datosOrdenados = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; // n = 10
    int target = 23;

    int indice = busquedaBinaria(datosOrdenados, target);
    
    // Comparación de escala:
    // Para n = 1,000,000 (Un millón de elementos):
    // - Una búsqueda lineal O(n) haría 1,000,000 de operaciones en el peor de los casos.
    // - Esta búsqueda binaria O(log n) resolverá el problema en un MÁXIMO de 20 operaciones.
    
    if (indice != -1) {
        std::cout << "Elemento encontrado en el indice: " << indice << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }
    return 0;
}