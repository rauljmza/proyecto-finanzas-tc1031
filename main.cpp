#include <iostream>
#include <string>
#include "finanzas.h"

using namespace std;

int main() {
    int opcion;
    bool seguir = true;

    cout << "=== SISTEMA DE FINANZAS PERSONALES ===" << endl;
    cout << "Cargando datos de prueba..." << endl;
    cargarDatosPrueba();
    cout << "Datos cargados exitosamente." << endl;

    // menu principal del sistema
    while (seguir) {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Ver todas las transacciones" << endl;
        cout << "2. Agregar nueva transaccion" << endl;
        cout << "3. Buscar por ID (lineal)" << endl;
        cout << "4. Buscar por ID (binaria)" << endl;
        cout << "5. Ordenar por monto" << endl;
        cout << "6. Ordenar por fecha" << endl;
        cout << "7. Ordenar por categoria" << endl;
        cout << "8. Ver resumen financiero" << endl;
        cout << "9. Buscar por categoria" << endl;
        cout << "10. Ver gasto maximo" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            mostrarTransacciones();

        } else if (opcion == 2) {
            string fecha, categoria, descripcion;
            float monto;
            int tipo;

            cout << "\n=== AGREGAR TRANSACCION ===" << endl;
            cout << "Fecha (YYYY-MM-DD): ";
            cin >> fecha;
            cout << "Monto: $";
            cin >> monto;
            cout << "Categoria: ";
            cin >> categoria;
            cout << "Descripcion: ";
            cin >> descripcion;
            cout << "Es ingreso? (1=Si, 0=No): ";
            cin >> tipo;

            agregarTransaccion(fecha, monto, categoria, descripcion, tipo == 1);

        } else if (opcion == 3) {
            int id;
            cout << "\nID a buscar: ";
            cin >> id;

            cout << "Ejecutando busqueda lineal..." << endl;
            int pos = busquedaLineal(id);

            if (pos != -1) {
                cout << "Encontrado en posicion: " << pos << endl;
                cout << "ID: " << ids[pos] << " | Monto: $" << montos[pos] << endl;
            } else {
                cout << "No encontrado" << endl;
            }

        } else if (opcion == 4) {
            int id;
            cout << "\nID a buscar: ";
            cin >> id;

            cout << "Ejecutando busqueda binaria..." << endl;
            int pos = busquedaBinaria(id);

            if (pos != -1) {
                cout << "Encontrado en posicion: " << pos << endl;
                cout << "ID: " << ids[pos] << " | Monto: $" << montos[pos] << endl;
            } else {
                cout << "No encontrado" << endl;
            }

        } else if (opcion == 5) {
            cout << "\nOrdenando por monto..." << endl;
            ordenarPorMonto();

        } else if (opcion == 6) {
            cout << "\nOrdenando por fecha..." << endl;
            ordenarPorFecha();

        } else if (opcion == 7) {
            cout << "\nOrdenando por categoria..." << endl;
            ordenarPorCategoria();

        } else if (opcion == 8) {
            mostrarResumen();

        } else if (opcion == 9) {
            string cat;
            cout << "\nCategoria a buscar: ";
            cin >> cat;
            buscarPorCategoria(cat);

            int cuenta = contarPorCategoria(cat);
            cout << "Total encontradas: " << cuenta << endl;

        } else if (opcion == 10) {
            cout << "\nCalculando gasto maximo usando recursion..." << endl;
            mostrarGastoMaximo();

        } else if (opcion == 0) {
            seguir = false;
            cout << "\nGracias por usar el sistema!" << endl;

        } else {
            cout << "\nOpcion no valida. Intente nuevamente." << endl;
        }
    }

    // mostrar estadisticas finales
    cout << "\n=== RESUMEN DEL SISTEMA ===" << endl;
    cout << "Total de transacciones: " << totalTransacciones << endl;
    cout << "Total usando recursion: " << contarTransaccionesRec(0) << endl;

    return 0;
}