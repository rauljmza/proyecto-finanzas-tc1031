#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <string>

using namespace std;

// declaraciones externas de los arreglos globales
extern int ids[];
extern string fechas[];
extern float montos[];
extern string categorias[];
extern string descripciones[];
extern bool esIngreso[];
extern int totalTransacciones;

// funcion para intercambiar dos elementos en los arreglos
void intercambiar(int i, int j) {
    // intercambia todos los datos de la transaccion
    int tempId = ids[i];
    ids[i] = ids[j];
    ids[j] = tempId;

    string tempFecha = fechas[i];
    fechas[i] = fechas[j];
    fechas[j] = tempFecha;

    float tempMonto = montos[i];
    montos[i] = montos[j];
    montos[j] = tempMonto;

    string tempCat = categorias[i];
    categorias[i] = categorias[j];
    categorias[j] = tempCat;

    string tempDesc = descripciones[i];
    descripciones[i] = descripciones[j];
    descripciones[j] = tempDesc;

    bool tempIngreso = esIngreso[i];
    esIngreso[i] = esIngreso[j];
    esIngreso[j] = tempIngreso;
}

// funcion O(n^2)
void ordenarPorMonto() {
    // bubble sort simple
    for (int i = 0; i < totalTransacciones - 1; i++) {
        for (int j = 0; j < totalTransacciones - 1 - i; j++) {
            if (montos[j] > montos[j + 1]) {
                intercambiar(j, j + 1);
            }
        }
    }
    cout << "Transacciones ordenadas por monto!" << endl;
}

// funcion O(n^2)
void ordenarPorFecha() {
    // selection sort - busca el menor y lo pone al principio
    for (int i = 0; i < totalTransacciones - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < totalTransacciones; j++) {
            if (fechas[j] < fechas[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            intercambiar(i, menor);
        }
    }
    cout << "Transacciones ordenadas por fecha!" << endl;
}

// funcion O(n^2) - ordenamiento por insercion
void ordenarPorCategoria() {
    // implementacion de insertion sort
    for (int i = 1; i < totalTransacciones; i++) {
        int j = i;
        // comparacion de strings para ordenamiento alfabetico
        while (j > 0 && categorias[j] < categorias[j-1]) {
            intercambiar(j, j-1);
            j--;
        }
    }
    cout << "Transacciones ordenadas por categoria" << endl;
}

// implementacion alternativa de ordenamiento por monto
void ordenarSeleccion() {
    for (int i = 0; i < totalTransacciones; i++) {
        for (int j = i + 1; j < totalTransacciones; j++) {
            if (montos[i] > montos[j]) {
                intercambiar(i, j);
            }
        }
    }
}

#endif /* SORTS_H_ */