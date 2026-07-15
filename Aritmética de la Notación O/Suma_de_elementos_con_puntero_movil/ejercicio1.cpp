/*
Suma de elementos con puntero móvil

Para medir el tiempo de ejecución de este programa de manera abstracta 
(N representa el tamaño del bloque de memoria, en este caso 5):
Reservar memoria y asignar valores iniciales: 
Se hacen asignaciones individuales que toman un tiempo constante. 
Esto es O(1).El bucle for: Se repite exactamente N veces. 
En cada iteración se hace una suma (O(1)) y un incremento de puntero (O(1)).
Liberar memoria (free): Se hace una sola vez. Esto es O(1).
*/

#include <iostream>
#include <cstdlib> 

int main() {
    std::cout << "--- Ejercicio 1: Suma con puntero movil ---\n";

    int tamanio = 5; 
    
    int* base = static_cast<int*>(std::malloc(tamanio * sizeof(int)));
    
    *(base + 0) = 10;
    *(base + 1) = 20;
    *(base + 2) = 30;
    *(base + 3) = 40;
    *(base + 4) = 50;

    int* ptr_movil = base;
    int suma = 0;

    for (int i = 0; i < tamanio; ++i) {
        suma += *ptr_movil; 
        ptr_movil++;        
    }

    std::cout << "La suma de los elementos es: " << suma << "\n";
    std::free(base);

    return 0;
}