#include <iostream>
#include <vector>

// Analizando la complejidad de esta función:
// Si el vector tiene un tamaño 'n':
// - El bucle externo (i) se ejecuta 'n' veces.
// - Por cada iteración de 'i', el bucle interno (j) también se ejecuta aproximadamente 'n' veces.
// - Esto resulta en un total de n * n = n² comparaciones en el peor de los casos.
//
// Complejidad Asintótica del Peor Caso: O(n²) - Cuadrática
bool tieneDuplicadosLento(const std::vector<int>& numeros) {
    int n = numeros.size(); // 1 operación constante: O(1)

    for (int i = 0; i < n; i++) { // Se ejecuta 'n' veces
        for (int j = i + 1; j < n; j++) { // Se ejecuta promedio (n / 2) veces, escala con 'n'
            if (numeros[i] == numeros[j]) { // Operación básica de comparación: O(1)
                return true; // Duplicado encontrado
            }
        }
    }
    return false; // Peor caso: Recorrió todas las combinaciones y no encontró nada
}

int main() {
    std::vector<int> datos = {1, 5, 8, 12, 5, 20}; // n = 5
    // Para n = 5, hace aproximadamente 10 comparaciones. ¡Rápido!
    // Pero si n = 100,000, hará unas 5,000,000,000 (5 mil millones) de comparaciones. El programa se colgará.
    
    if (tieneDuplicadosLento(datos)) {
        std::cout << "¡Hay duplicados!" << std::endl;
    }
    return 0;
}