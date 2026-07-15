#include <iostream>
#include <cstdlib> // Para malloc y free

int encontrarPico(const int* arr, int izq, int der, int n) {
    int medio = izq + (der - izq) / 2;

    // Evaluamos vecinos 
    bool mayorQueIzquierdo = (medio == 0 || *(arr + medio) >= *(arr + (medio - 1)));
    bool mayorQueDerecho = (medio == n - 1 || *(arr + medio) >= *(arr + (medio + 1)));

    // Caso base: Si es mayor o igual a sus vecinos, es un pico
    if (mayorQueIzquierdo && mayorQueDerecho) {
        return medio; // Retorna el indice
    }

    // Si el vecino izquierdo es mayor, nos movemos a la mitad izquierda
    if (medio > 0 && *(arr + (medio - 1)) > *(arr + medio)) {
        return encontrarPico(arr, izq, medio - 1, n);
    }

    // De lo contrario, buscamos en la mitad derecha
    return encontrarPico(arr, medio + 1, der, n);
}

int main() {
    int n = 0;
    std::cout << "--- EJERCICIO 2: ELEMENTO PICO (Divide y Venceras) ---" << std::endl;
    std::cout << "Ingrese la cantidad de elementos: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Error: El tamano debe ser mayor a 0." << std::endl;
        return 1;
    }

    // Asignacion de memoria dinamica sin corchetes
    int* datos = (int*)malloc(n * sizeof(int));

    // Lectura de datos por teclado usando aritmetica de punteros
    for (int i = 0; i < n; i = i + 1) {
        std::cout << "Ingrese el valor para la posicion " << i << ": ";
        std::cin >> *(datos + i); // Cero corchetes
    }

    int indicePico = encontrarPico(datos, 0, n - 1, n);

    std::cout << "\n--- RESULTADOS ---" << std::endl;
    std::cout << "Se encontro un elemento pico en el indice: " << indicePico << std::endl;
    std::cout << "El valor del elemento pico es: " << *(datos + indicePico) << std::endl;

    // Liberamos la memoria
    free(datos);

    return 0;
}