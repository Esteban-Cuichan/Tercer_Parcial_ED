/*
Buscar el máximo y calcular la posición (Resta de punteros)

Hagamos la suma de complejidades para analizar este segundo programa:
Inicialización y asignaciones iniciales: O(1).
El bucle for: Se ejecuta N veces.
 Dentro hace una comparación (O(1)) y un incremento de dirección (O(1)).
  Es decir, O(N).
Resta de punteros (ptr_maximo - base): Es una operación matemática directa en
 el procesador que toma tiempo constante: O(1).Liberar memoria: O(1).
*/

#include <iostream>
#include <cstdlib>  
#include <cstddef>  

int main() {
    std::cout << "--- Ejercicio 2: Buscar maximo y calcular distancia ---\n";

    int tamanio = 5;
    int* base = static_cast<int*>(std::malloc(tamanio * sizeof(int)));

    *(base + 0) = 15;
    *(base + 1) = 89; 
    *(base + 2) = 42;
    *(base + 3) = 7;
    *(base + 4) = 63;

    int* ptr_lector = base;
    int* ptr_maximo = base; 

    for (int i = 0; i < tamanio; ++i) {
        if (*ptr_lector > *ptr_maximo) {
            ptr_maximo = ptr_lector; 
        }
        ptr_lector++; 
    }

    std::ptrdiff_t indice_maximo = ptr_maximo - base;

    std::cout << "El valor maximo encontrado es: " << *ptr_maximo << "\n";
    std::cout << "Se encuentra en el indice (posicion): " << indice_maximo << "\n";

    std::free(base);

    return 0;
}