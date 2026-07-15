/*
Tiempo Lineal O(N) vs. Tiempo Cuadrático O(N^2)

En este ejercicio reduciremos el tamaño de la memoria a un número menor 
(10,000 elementos) pero compararemos un solo bucle (lineal) contra un
algoritmo de fuerza bruta con bucles anidados que procesa combinaciones (cuadrático).

El algoritmo lineal O(N): El procesador realiza solo 10,000 operaciones de suma
e incrementos de puntero. Esto se ejecuta casi de inmediato 
(0.01 ms a 0.1 ms).El algoritmo cuadrático O(N^2):
Aunque solo tenemos 10,000 elementos, al anidar los bucles 
realizamos 10,000 \times 10,000 = 100,000,000 (cien millones) de comparaciones y
sumas en memoria. Aquí notarás un retraso visible 
(por lo general entre 80 ms y 300 ms).
*/

#include <iostream>
#include <cstdlib>
#include <chrono>

int main() {
    std::cout << "--- Ejercicio 2: Tiempo de Ejecucion O(N) vs O(N^2) ---\n\n";

    int tamanio = 10000; 
    int* base = static_cast<int*>(std::malloc(tamanio * sizeof(int)));


    for (int i = 0; i < tamanio; ++i) {
        *(base + i) = i;
    }

    // =========================================================================
    // 1. OPERACIÓN LINEAL O(N) - Sumar todos los elementos
    // =========================================================================
    long long suma = 0;
    int* ptr_on = base;

    auto inicio_on = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < tamanio; ++i) {
        suma += *ptr_on;
        ptr_on++;
    }

    auto fin_on = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempo_on = fin_on - inicio_on;

    std::cout << "[O(N)] Suma total: " << suma << "\n";
    std::cout << "[O(N)] Tiempo de ejecucion: " << tiempo_on.count() << " ms\n\n";


    // =========================================================================
    // 2. OPERACIÓN CUADRÁTICA O(N^2) - Comparación cruzada de parejas de elementos
    // =========================================================================
    long long parejas_pares = 0;

    auto inicio_on2 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < tamanio; ++i) {
        int* ptr_interno = base; 
        
        for (int j = 0; j < tamanio; ++j) {
            if ((*(base + i) + *ptr_interno) % 2 == 0) {
                parejas_pares++;
            }
            ptr_interno++; 
        }
    }

    auto fin_on2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempo_on2 = fin_on2 - inicio_on2;

    std::cout << "[O(N^2)] Parejas cuya suma es par: " << parejas_pares << "\n";
    std::cout << "[O(N^2)] Tiempo de ejecucion: " << tiempo_on2.count() << " ms\n\n";

    std::free(base);
    return 0;
}