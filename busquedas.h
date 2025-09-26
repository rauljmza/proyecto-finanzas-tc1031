#ifndef BUSQUEDAS_H_
#define BUSQUEDAS_H_

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

// declaracion de funcion auxiliar de sorts.h
void intercambiar(int i, int j);

//funcion O(n)
int busquedaLineal(int idBuscar) {
    // ciclo for O(n) recorre todos los elementos
    for (int i = 0; i < totalTransacciones; i++) {
        if (ids[i] == idBuscar) {
            return i; // regresa la posicion donde lo encontro
        }
    }
    return -1; // no lo encontro
}

// funcion log(n) - busqueda binaria con ordenamiento previo
int busquedaBinaria(int idBuscar) {
    // ordenamiento previo del arreglo por id usando bubble sort
    for (int i = 0; i < totalTransacciones - 1; i++) {
        for (int j = 0; j < totalTransacciones - 1 - i; j++) {
            if (ids[j] > ids[j + 1]) {
                intercambiar(j, j + 1);
            }
        }
    }

    // implementacion de busqueda binaria
    int low = 0;
    int high = totalTransacciones - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (ids[mid] == idBuscar) {
            return mid;
        } else if (ids[mid] < idBuscar) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // no encontrado
}

// funcion para verificar existencia de transaccion
bool existeTransaccion(int id) {
    for (int i = 0; i < totalTransacciones; i++) {
        if (ids[i] == id) {
            return true;
        }
    }
    return false;
}

// funcion O(n) para contar transacciones por categoria
int contarPorCategoria(string cat) {
    int contador = 0;
    for (int i = 0; i < totalTransacciones; i++) {
        if (categorias[i] == cat) {
            contador++;
        }
    }
    return contador;
}

#endif /* BUSQUEDAS_H_ */