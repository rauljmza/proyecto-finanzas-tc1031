#ifndef RECURSION_H_
#define RECURSION_H_

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

// funcion O(n)
float sumaGastosRecursiva(int indice) {
    // caso base
    if (indice >= totalTransacciones) {
        return 0;
    }

    // suma el gasto actual si no es ingreso
    float gasto = 0;
    if (!esIngreso[indice]) {
        gasto = montos[indice];
    }

    // llamada recursiva
    return gasto + sumaGastosRecursiva(indice + 1);
}

// funcion O(n)
float sumaIngresosRecursiva(int indice) {
    if (indice >= totalTransacciones) {
        return 0;
    }

    float ingreso = 0;
    if (esIngreso[indice]) {
        ingreso = montos[indice];
    }

    return ingreso + sumaIngresosRecursiva(indice + 1);
}

// funcion O(n) - divide y venceras
float maxGastoRecursivo(int inicio, int fin) {
    if (inicio == fin) {
        if (!esIngreso[inicio]) {
            return montos[inicio];
        }
        return 0;
    }

    // dividir arreglo
    int medio = (inicio + fin) / 2;
    float maxIzq = maxGastoRecursivo(inicio, medio);
    float maxDer = maxGastoRecursivo(medio + 1, fin);

    // retorna el mayor
    if (maxIzq > maxDer) {
        return maxIzq;
    } else {
        return maxDer;
    }
}

// funcion recursiva para contar total de transacciones
int contarTransaccionesRec(int indice) {
    if (indice >= totalTransacciones) {
        return 0;
    }
    return 1 + contarTransaccionesRec(indice + 1);
}

#endif /* RECURSION_H_ */