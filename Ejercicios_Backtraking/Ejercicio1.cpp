#include <iostream>
#include <cstring>

using namespace std;

void intercambiar(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generarPermutaciones(char* str, int inicio, int fin, int* total) {
    if (inicio == fin) {
        cout << " -> " << str << endl;
        (*total)++; 
        return;
    }

    for (int i = inicio; i <= fin; i++) {
        intercambiar(str + inicio, str + i);
        generarPermutaciones(str, inicio + 1, fin, total);
        intercambiar(str + inicio, str + i);
    }
}

int main() {
    const int MAX_LIMITE = 100;
    char texto[MAX_LIMITE];
    int contadorCombinaciones = 0;

    cout << "Introduce una palabra: ";
    cin >> texto;

    int longitud = strlen(texto);

    cout << "\n--- Combinaciones Generadas ---" << endl;
    generarPermutaciones(texto, 0, longitud - 1, &contadorCombinaciones);

    cout << "\n=====================================" << endl;
    cout << "Total de combinaciones posibles: " << contadorCombinaciones << endl;
    cout << "=====================================" << endl;

    return 0;
}