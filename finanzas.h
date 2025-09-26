#ifndef FINANZAS_H_
#define FINANZAS_H_

#include <iostream>
#include <string>
#include "recursion.h"
#include "busquedas.h"
#include "sorts.h"

using namespace std;

// constante para definir el tamaño maximo del arreglo
const int MAX_TRANSACCIONES = 100;

// arreglos globales para almacenar la informacion de las transacciones
int ids[MAX_TRANSACCIONES];
string fechas[MAX_TRANSACCIONES];
float montos[MAX_TRANSACCIONES];
string categorias[MAX_TRANSACCIONES];
string descripciones[MAX_TRANSACCIONES];
bool esIngreso[MAX_TRANSACCIONES];
int totalTransacciones = 0;
int siguienteId = 1;

// funcion para agregar una transaccion nueva
void agregarTransaccion(string fecha, float monto, string categoria, string descripcion, bool ingreso) {
    if (totalTransacciones >= MAX_TRANSACCIONES) {
        cout << "Error: No se pueden agregar mas transacciones" << endl;
        return;
    }

    ids[totalTransacciones] = siguienteId++;
    fechas[totalTransacciones] = fecha;
    montos[totalTransacciones] = monto;
    categorias[totalTransacciones] = categoria;
    descripciones[totalTransacciones] = descripcion;
    esIngreso[totalTransacciones] = ingreso;
    totalTransacciones++;

    cout << "Transaccion agregada!" << endl;
}

// funcion para mostrar todas las transacciones
void mostrarTransacciones() {
    if (totalTransacciones == 0) {
        cout << "No hay transacciones" << endl;
        return;
    }

    cout << "\n=== TODAS LAS TRANSACCIONES ===" << endl;
    for (int i = 0; i < totalTransacciones; i++) {
        cout << "ID: " << ids[i] << " | ";
        cout << "Fecha: " << fechas[i] << " | ";
        cout << "Monto: $" << montos[i] << " | ";
        cout << "Categoria: " << categorias[i] << " | ";
        cout << "Descripcion: " << descripciones[i] << " | ";
        cout << "Tipo: " << (esIngreso[i] ? "Ingreso" : "Gasto") << endl;
    }
}

// funcion para mostrar el resumen
void mostrarResumen() {
    float totalIngresos = sumaIngresosRecursiva(0);
    float totalGastos = sumaGastosRecursiva(0);
    float balance = totalIngresos - totalGastos;

    cout << "\n=== RESUMEN FINANCIERO ===" << endl;
    cout << "Total Ingresos: $" << totalIngresos << endl;
    cout << "Total Gastos: $" << totalGastos << endl;
    cout << "Balance: $" << balance << endl;

    if (balance > 0) {
        cout << "Estado: POSITIVO" << endl;
    } else if (balance < 0) {
        cout << "Estado: NEGATIVO" << endl;
    } else {
        cout << "Estado: EQUILIBRADO" << endl;
    }
}

// funcion para buscar por categoria
void buscarPorCategoria(string cat) {
    bool encontrado = false;
    cout << "\n=== CATEGORIA: " << cat << " ===" << endl;

    for (int i = 0; i < totalTransacciones; i++) {
        if (categorias[i] == cat) {
            cout << "ID: " << ids[i] << " | ";
            cout << "Fecha: " << fechas[i] << " | ";
            cout << "Monto: $" << montos[i] << " | ";
            cout << "Descripcion: " << descripciones[i] << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron transacciones en esa categoria" << endl;
    }
}

// funcion para mostrar el gasto maximo
void mostrarGastoMaximo() {
    if (totalTransacciones == 0) {
        cout << "No hay transacciones" << endl;
        return;
    }

    float maximo = maxGastoRecursivo(0, totalTransacciones - 1);
    if (maximo == 0) {
        cout << "No hay gastos registrados" << endl;
    } else {
        cout << "El gasto maximo es: $" << maximo << endl;
    }
}

// funcion para cargar datos de prueba
void cargarDatosPrueba() {
    agregarTransaccion("2024-01-15", 5000, "Salario", "Pago quincenal", true);
    agregarTransaccion("2024-01-16", 250, "Supermercado", "Despensa semanal", false);
    agregarTransaccion("2024-01-17", 800, "Transporte", "Gasolina", false);
    agregarTransaccion("2024-01-18", 1500, "Renta", "Pago mensual", false);
    agregarTransaccion("2024-01-20", 150, "Entretenimiento", "Cine", false);
    agregarTransaccion("2024-01-22", 2000, "Freelance", "Proyecto web", true);
    agregarTransaccion("2024-01-23", 450, "Salud", "Consulta medica", false);
    agregarTransaccion("2024-01-25", 300, "Comida", "Restaurante", false);
}

#endif /* FINANZAS_H_ */