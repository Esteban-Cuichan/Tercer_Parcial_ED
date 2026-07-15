/*
Enunciado:
Desarrolle un programa que permita ingresar un conjunto de actividades,
seleccionando mediante un algoritmo voraz el mayor número posible de
actividades compatibles sin superposición de horarios.
*/
#include <iostream>
#include <cstring>

using namespace std;

void leerActividades(char**& nombres, int*& inicios, int*& finales, int& n) {
    cout<<"Ingrese el numero de actividades: ";
    cin>>n;
    
    while (n<=0) {
        cout<<"El numero de actividades debe ser mayor que 0: ";
        cin>>n;
    }
    
    nombres=new char*[n];
    inicios=new int[n];
    finales=new int[n];
    
    for (int i=0; i<n; ++i) {
        cin.ignore(); 
        nombres[i]=new char[50]; 
        
        cout<<"\nActividad "<<i+1<<":"<<endl;
        cout<<"Nombre: ";
        cin.getline(nombres[i], 50);
        
        cout<<"Hora de inicio: ";
        cin>>*(inicios+i);
        
        cout<<"Hora de finalizacion: ";
        cin>>*(finales+i);
        
        while (*(inicios+i)>=*(finales+i)) {
            cout<<"Error: La hora de inicio debe ser menor que la de finalizacion."<<endl;
            cout<<"Hora de inicio: ";
            cin>>*(inicios+i);
            cout<<"Hora de finalizacion: ";
            cin>>*(finales+i);
        }
    }
}

void intercambiar(char*& nombre1, char*& nombre2, int& inicio1, int& inicio2, int& final1, int& final2) {
    char* tempNombre=nombre1;
    nombre1=nombre2;
    nombre2=tempNombre;
    
    int tempInicio=inicio1;
    inicio1=inicio2;
    inicio2=tempInicio;
    
    int tempFinal=final1;
    final1=final2;
    final2=tempFinal;
}

void ordenarActividades(char** nombres, int* inicios, int* finales, int n) {
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n-i-1; ++j) {
            if (*(finales+j)>*(finales+j+1)) {
                intercambiar(*(nombres+j), *(nombres+j+1), 
                           *(inicios+j), *(inicios+j+1),
                           *(finales+j), *(finales+j+1));
            }
        }
    }
}

int seleccionarActividades(char** nombres, int* inicios, int* finales, int n, 
                          char**& seleccionados, int*& selecInicios, int*& selecFinales) {
    int contador=1;
    int ultimoSeleccionado=0;
    
    seleccionados=new char*[n];
    selecInicios=new int[n];
    selecFinales=new int[n];
    
    seleccionados[0]=new char[strlen(nombres[0])+1];
    strcpy(seleccionados[0], nombres[0]);
    selecInicios[0]=inicios[0];
    selecFinales[0]=finales[0];
    
    for (int i=1; i<n; ++i) {
        if (*(inicios+i)>=*(finales+ultimoSeleccionado)) {
            seleccionados[contador]=new char[strlen(nombres[i])+1];
            strcpy(seleccionados[contador], nombres[i]);
            selecInicios[contador]=inicios[i];
            selecFinales[contador]=finales[i];
            
            contador++;
            ultimoSeleccionado=i;
        }
    }
    
    return contador;
}

void mostrarResultados(char** nombres, int* inicios, int* finales, int n,
                       char** seleccionados, int* selecInicios, int* selecFinales, int totalSeleccionadas) {
    cout<<"\n=== ACTIVIDADES ORDENADAS POR HORA DE FINALIZACION ==="<<endl;
    for (int i=0; i<n; ++i) {
        cout<<i+1<<". "<<*(nombres+i) 
            <<" ("<<*(inicios+i)<<" - "<<*(finales+i)<<")"<<endl;
    }
    
    cout<<"\n=== ACTIVIDADES SELECCIONADAS ==="<<endl;
    for (int i=0; i<totalSeleccionadas; ++i) {
        cout<<i+1<<". "<<*(seleccionados+i) 
            <<" ("<<*(selecInicios+i)<<" - "<<*(selecFinales+i)<<")"<<endl;
    }
    
    cout<<"\nNumero total de actividades seleccionadas: "<<totalSeleccionadas<<endl;
}

void liberarMemoria(char** nombres, int* inicios, int* finales, int n,
                    char** seleccionados, int* selecInicios, int* selecFinales, int totalSeleccionadas) {
    for (int i=0; i<n; ++i) {
        delete[] nombres[i];
    }
    delete[] nombres;
    delete[] inicios;
    delete[] finales;
    
    for (int i=0; i<totalSeleccionadas; ++i) {
        delete[] seleccionados[i];
    }
    delete[] seleccionados;
    delete[] selecInicios;
    delete[] selecFinales;
}

int main() {
    char** nombres=nullptr;
    int* inicios=nullptr;
    int* finales=nullptr;
    int n=0;
    
    cout<<"=== SELECCION DE ACTIVIDADES (ALGORITMO VORAZ) ==="<<endl;
    leerActividades(nombres, inicios, finales, n);
    
    ordenarActividades(nombres, inicios, finales, n);
    
    char** seleccionados=nullptr;
    int* selecInicios=nullptr;
    int* selecFinales=nullptr;
    int totalSeleccionadas=seleccionarActividades(nombres, inicios, finales, n, 
                                                    seleccionados, selecInicios, selecFinales);
    
    mostrarResultados(nombres, inicios, finales, n, 
                     seleccionados, selecInicios, selecFinales, totalSeleccionadas);
    
    liberarMemoria(nombres, inicios, finales, n, 
                  seleccionados, selecInicios, selecFinales, totalSeleccionadas);
    
    return 0;
}