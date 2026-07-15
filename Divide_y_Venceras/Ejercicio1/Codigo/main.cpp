#include <iostream>
#include <algorithm>
#include <cstdlib>

struct MinMax {
    int minimo;
    int maximo;
};

// Recibe un puntero base 'arr'
MinMax buscarMinMax(const int* arr, int izq, int der) {
    MinMax resultado, izq_sub, der_sub;

    // Caso base 1: Si el sub-arreglo tiene un solo elemento
    if (izq == der) {
        resultado.maximo = *(arr + izq);
        resultado.minimo = *(arr + izq);
        return resultado;
    }

    // Caso base 2: Si tiene dos elementos
    if (der == izq + 1) {
        if (*(arr + izq) > *(arr + der)) {
            resultado.maximo = *(arr + izq);
            resultado.minimo = *(arr + der);
        } else {
            resultado.maximo = *(arr + der);
            resultado.minimo = *(arr + izq);
        }
        return resultado;
    }

    // --- Fase 1: Dividir ---
    int medio = izq + (der - izq) / 2;

    // --- Fase 2: Conquistar ---
    izq_sub = buscarMinMax(arr, izq, medio);
    der_sub = buscarMinMax(arr, medio + 1, der);

    // --- Fase 3: Combinar ---
    resultado.minimo = std::min(izq_sub.minimo, der_sub.minimo);
    resultado.maximo = std::max(izq_sub.maximo, der_sub.maximo);

    return resultado;
}

int main() {
    int n = 0;
    std::cout << "--- EJERCICIO 1: MAX-MIN (Divide y Venceras) ---" << std::endl;
    std::cout << "Ingrese la cantidad de elementos: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Error: El tamano debe ser mayor a 0." << std::endl;
        return 1;
    }

    int* datos = (int*)malloc(n * sizeof(int));

    // Lectura de datos por teclado
    for (int i = 0; i < n; i = i + 1) {
        std::cout << "Ingrese el valor para la posicion " << i << ": ";
        std::cin >> *(datos + i); // Cero corchetes
    }

    MinMax resultado = buscarMinMax(datos, 0, n - 1);

    std::cout << "\n--- RESULTADOS ---" << std::endl;
    std::cout << "El elemento minimo es: " << resultado.minimo << std::endl;
    std::cout << "El elemento maximo es: " << resultado.maximo << std::endl;

    // Liberamos la memoria
    free(datos);

    return 0;
}