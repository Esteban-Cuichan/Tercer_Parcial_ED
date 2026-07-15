/*
Tiempo Constante O(1) vs. Tiempo Lineal O(N)

El Acceso O(1): No importa si la memoria tiene 10 elementos o 10 mil millones.
 La CPU sabe calcular la dirección de inmediato mediante una simple suma de punteros,
  por lo que el tiempo registrado será prácticamente cero milisegundos
   (0 ms o extremadamente cercano).La Búsqueda O(N):
    Para comprobar que el elemento no existe,
    el programa debe visitar obligatoriamente cada una de las direcciones de memoria.
    Notarás que este proceso toma una cantidad medible de tiempo en milisegundos 
    (por ejemplo, entre 3 ms y 15 ms dependiendo de tu procesador).
*/

#include <iostream>
#include <cstdlib>
#include <chrono> 

int main() {
    std::cout << "--- Ejercicio 1: Tiempo de Ejecucion O(1) vs O(N) ---\n\n";

    int tamanio = 10000000; 
    int* base = static_cast<int*>(std::malloc(tamanio * sizeof(int)));

    for (int i = 0; i < tamanio; ++i) {
        *(base + i) = i;
    }

    // =========================================================================
    // 1. MEDIR ACCESO CONSTANTE O(1)
    // =========================================================================
    auto inicio_o1 = std::chrono::high_resolution_clock::now();

    int valor_medio = *(base + (tamanio / 2)); 

    auto fin_o1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempo_o1 = fin_o1 - inicio_o1;

    std::cout << "[O(1)] Valor obtenido a mitad de memoria: " << valor_medio << "\n";
    std::cout << "[O(1)] Tiempo de ejecucion: " << tiempo_o1.count() << " ms\n\n";


    // =========================================================================
    // 2. MEDIR BÚSQUEDA LINEAL O(N)
    // =========================================================================
    
    int buscar = -1; 
    bool encontrado = false;
    int* ptr_lector = base;

    auto inicio_on = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < tamanio; ++i) {
        if (*ptr_lector == buscar) {
            encontrado = true;
            break;
        }
        ptr_lector++; 
    }

    auto fin_on = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempo_on = fin_on - inicio_on;

    std::cout << "[O(N)] Elemento encontrado?: " << (encontrado ? "Si" : "No") << "\n";
    std::cout << "[O(N)] Tiempo de ejecucion: " << tiempo_on.count() << " ms\n\n";

    std::free(base);
    return 0;
}