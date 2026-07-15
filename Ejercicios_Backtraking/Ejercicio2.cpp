#include <iostream>

using namespace std;

bool buscarSubconjunto(int* valores, int n, int indice, int objetivo, int sumaActual, int* seleccionados) {
    if (sumaActual == objetivo) {
        return true;
    }
    if (sumaActual > objetivo || indice == n) {
        return false;
    }
    *(seleccionados + indice) = 1;
    if (buscarSubconjunto(valores, n, indice + 1, objetivo, sumaActual + *(valores + indice), seleccionados)) {
        return true; 
    }
    *(seleccionados + indice) = 0; 
    if (buscarSubconjunto(valores, n, indice + 1, objetivo, sumaActual, seleccionados)) {
        return true;
    }

    return false; 
}

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos (facturas): ";
    cin >> n;
    int* valores = new int[n];
    int* seleccionados = new int[n];
    for (int i = 0; i < n; i++) {
        *(seleccionados + i) = 0;
    }
    cout << "\nIngrese los " << n << " valores de uno en uno:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i + 1 << "]: ";
        cin >> *(valores + i); 
    }

    int objetivo;
    cout << "\nIngrese el valor objetivo a sumar: ";
    cin >> objetivo;

    cout << "\n--- Buscando combinacion óptima ---" << endl;
    if (buscarSubconjunto(valores, n, 0, objetivo, 0, seleccionados)) {
        cout << "\n¡Exito! Subconjunto encontrado." << endl;
        cout << "Elementos seleccionados: { ";
        
        for (int i = 0; i < n; i++) {
            if (*(seleccionados + i) == 1) {
                cout << *(valores + i) << " ";
            }
        }
        cout << "}" << endl;
    } else {
        cout << "\nNo existe ningun subconjunto que sume exactamente " << objetivo << endl;
    }
    delete[] valores;
    delete[] seleccionados;
    valores = nullptr;
    seleccionados = nullptr;

    return 0;
}