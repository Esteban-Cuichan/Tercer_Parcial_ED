/*
Enunciado:
Desarrolle un programa que determine la menor cantidad de monedas o
billetes necesarios para formar un monto determinado aplicando un
algoritmo voraz con las denominaciones ingresadas por el usuario.
*/
#include <iostream>
#include <cstring>

using namespace std;

void leerDatos(int*& denominaciones, int& cantidad, int& monto) {
    cout<<"Ingrese la cantidad de denominaciones disponibles: ";
    cin>>cantidad;
    
    while (cantidad<=0) {
        cout<<"La cantidad debe ser mayor que 0: ";
        cin>>cantidad;
    }
    
    denominaciones=new int[cantidad];
    
    for (int i=0; i<cantidad; ++i) {
        cout<<"Denominacion "<<i+1<<": ";
        cin>>*(denominaciones+i);
        
        while (*(denominaciones+i)<=0) {
            cout<<"La denominacion debe ser mayor que 0: ";
            cin>>*(denominaciones+i);
        }
    }
    
    cout<<"Ingrese el monto a devolver: ";
    cin>>monto;
    
    while (monto<=0) {
        cout<<"El monto debe ser mayor que 0: ";
        cin>>monto;
    }
}

void intercambiar(int& a, int& b) {
    int temp=a;
    a=b;
    b=temp;
}

void ordenarDenominaciones(int* denominaciones, int cantidad) {
    for (int i=0; i<cantidad-1; ++i) {
        for (int j=0; j<cantidad-i-1; ++j) {
            if (*(denominaciones+j)<*(denominaciones+j+1)) {
                intercambiar(*(denominaciones+j), *(denominaciones+j+1));
            }
        }
    }
}

int calcularCambio(int* denominaciones, int cantidad, int monto, int*& resultado) {
    resultado=new int[cantidad];
    
    for (int i=0; i<cantidad; ++i) {
        *(resultado+i)=0;
    }
    
    int montoRestante=monto;
    int totalMonedas=0;
    
    for (int i=0; i<cantidad; ++i) {
        if (*(denominaciones+i)<=montoRestante) {
            *(resultado+i)=montoRestante / *(denominaciones+i);
            montoRestante=montoRestante % *(denominaciones+i);
            totalMonedas+=*(resultado+i);
        }
    }
    
    return totalMonedas;
}

void mostrarResultados(int* denominaciones, int cantidad, int monto, int* resultado, int totalMonedas) {
    cout<<"\n=== DENOMINACIONES ORDENADAS (MAYOR A MENOR) ==="<<endl;
    for (int i=0; i<cantidad; ++i) {
        cout<<i+1<<". "<<*(denominaciones+i)<<endl;
    }
    
    cout<<"\n=== DESGLOSE DEL CAMBIO PARA $"<<monto<<" ==="<<endl;
    bool hayMonedas=false;
    
    for (int i=0; i<cantidad; ++i) {
        if (*(resultado+i)>0) {
            cout<<"Monedas de $"<<*(denominaciones+i) 
                <<": "<<*(resultado+i)<<" moneda(s)"<<endl;
            hayMonedas=true;
        }
    }
    
    if (!hayMonedas) {
        cout<<"No se puede formar el monto con las denominaciones disponibles."<<endl;
    }
    
    cout<<"\nTotal de monedas empleadas: "<<totalMonedas<<endl;
    
    int montoCalculado=0;
    for (int i=0; i<cantidad; ++i) {
        montoCalculado+=*(resultado+i) * *(denominaciones+i);
    }
    
    if (montoCalculado==monto && totalMonedas>0) {
        cout<<"\nEXITO: El monto se ha formado exactamente."<<endl;
    } else if (totalMonedas==0) {
        cout<<"\nERROR: No es posible formar el monto con las denominaciones disponibles."<<endl;
    } else {
        cout<<"\nADVERTENCIA: El monto no se puede formar exactamente."<<endl;
        cout<<"Monto formado: $"<<montoCalculado<<" de $"<<monto<<endl;
    }
}

bool esCambioExacto(int* denominaciones, int* resultado, int cantidad, int monto) {
    int montoCalculado=0;
    for (int i=0; i<cantidad; ++i) {
        montoCalculado+=*(resultado+i) * *(denominaciones+i);
    }
    return montoCalculado==monto;
}

void mostrarResultadoDetallado(int* denominaciones, int cantidad, int monto, int* resultado, int totalMonedas) {
    cout<<"\n=== RESUMEN DEL CAMBIO ==="<<endl;
    
    bool cambioExacto=esCambioExacto(denominaciones, resultado, cantidad, monto);
    
    if (cambioExacto && totalMonedas>0) {
        cout<<"El cambio de $"<<monto<<" se ha realizado exitosamente!"<<endl;
        cout<<"Se utilizaron "<<totalMonedas<<" monedas en total."<<endl;
    } else if (totalMonedas==0) {
        cout<<"No fue posible realizar el cambio."<<endl;
        cout<<"El monto no puede formarse con las denominaciones disponibles."<<endl;
    } else {
        cout<<"Cambio parcial realizado."<<endl;
        cout<<"Monto solicitado: $"<<monto<<endl;
        int montoFormado=0;
        for (int i=0; i<cantidad; ++i) {
            montoFormado+=*(resultado+i) * *(denominaciones+i);
        }
        cout<<"Monto formado: $"<<montoFormado<<endl;
        cout<<"Faltante: $"<<(monto-montoFormado)<<endl;
    }
}

void liberarMemoria(int* denominaciones, int* resultado) {
    delete[] denominaciones;
    delete[] resultado;
}

int main() {
    int* denominaciones=nullptr;
    int* resultado=nullptr;
    int cantidad=0;
    int monto=0;
    
    cout<<"=== PROBLEMA DEL CAMBIO DE MONEDAS (ALGORITMO VORAZ) ==="<<endl;
    cout<<"========================================================="<<endl;
    
    leerDatos(denominaciones, cantidad, monto);
    
    ordenarDenominaciones(denominaciones, cantidad);
    
    int totalMonedas=calcularCambio(denominaciones, cantidad, monto, resultado);
    
    mostrarResultados(denominaciones, cantidad, monto, resultado, totalMonedas);
    
    mostrarResultadoDetallado(denominaciones, cantidad, monto, resultado, totalMonedas);
    
    liberarMemoria(denominaciones, resultado);
    
    cout<<"\nPresione Enter para finalizar..."<<endl;
    cin.get();
    cin.get();
    
    return 0;
}