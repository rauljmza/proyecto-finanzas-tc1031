/*
 * main.cpp
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#include <iostream>
#include <string>
#include "finanzas.h"
#include "busquedas.h"
#include "sorts.h"

using namespace std;

void mostrarMenuPrincipal() {
	cout << "\nSISTEMA DE FINANZAS PERSONALES" << endl;
	cout << "1. Ver todas las transacciones" << endl;
	cout << "2. Agregar nueva transaccion" << endl;
	cout << "3. Buscar por ID" << endl;
	cout << "4. Ordenar transacciones" << endl;
	cout << "5. Ver resumen financiero" << endl;
	cout << "6. Buscar transacciones" << endl;
	cout << "7. Gestionar bancos y tarjetas" << endl;
	cout << "8. Deshacer ultima transaccion" << endl;
	cout << "9. Cargar desde archivo CSV" << endl;
	cout << "10. Guardar en archivo CSV" << endl;
	cout << "0. Salir" << endl;
	cout << "Opcion: ";
}

void menuOrdenar() {
	int opcion;
	cout << "\nORDENAR TRANSACCIONES" << endl;
	cout << "1. Por monto (Bubble Sort)" << endl;
	cout << "2. Por fecha (Selection Sort)" << endl;
	cout << "3. Por categoria (Insertion Sort)" << endl;
	cout << "4. Por tipo" << endl;
	cout << "5. Por metodo de pago" << endl;
	cout << "6. Por ID" << endl;
	cout << "Opcion: ";
	cin >> opcion;

	if (opcion == 1) {
		ordenarPorMonto();
	} else if (opcion == 2) {
		ordenarPorFecha();
	} else if (opcion == 3) {
		ordenarPorCategoria();
	} else if (opcion == 4) {
		ordenarPorTipo();
	} else if (opcion == 5) {
		ordenarPorMetodoPago();
	} else if (opcion == 6) {
		ordenarPorId();
	} else {
		cout << "Opcion invalida" << endl;
	}
}

void menuBancosTarjetas() {
	int opcion;
	cout << "\nGESTION DE BANCOS Y TARJETAS" << endl;
	cout << "1. Ver bancos" << endl;
	cout << "2. Agregar banco" << endl;
	cout << "3. Ver tarjetas de credito" << endl;
	cout << "4. Agregar tarjeta de credito" << endl;
	cout << "5. Ver tarjetas de debito" << endl;
	cout << "6. Ver metodos de pago disponibles (para CSV)" << endl;
	cout << "7. Consultar saldo de tarjeta de credito" << endl;
	cout << "8. Pagar tarjeta de credito" << endl;
	cout << "Opcion: ";
	cin >> opcion;
	cin.ignore();

	if (opcion == 1) {
		mostrarBancos();
	} else if (opcion == 2) {
		string nombre;
		cout << "Nombre del banco: ";
		getline(cin, nombre);
		agregarBanco(nombre);
	} else if (opcion == 3) {
		mostrarTarjetasCredito();
	} else if (opcion == 4) {
		string nombre;
		float limite;
		cout << "Nombre de la tarjeta: ";
		getline(cin, nombre);
		cout << "Limite de credito: $";
		cin >> limite;
		cin.ignore();
		agregarTarjetaCredito(nombre, limite);
	} else if (opcion == 5) {
		mostrarTarjetasDebito();
	} else if (opcion == 6) {
		mostrarMetodosPagoDisponibles();
	} else if (opcion == 7) {
		consultarSaldoTarjetaCredito();
	} else if (opcion == 8) {
		pagarTarjetaCredito();
	} else {
		cout << "Opcion invalida" << endl;
	}
}

int main() {
	int opcion;
	bool seguir = true;

	cout << "SISTEMA DE FINANZAS PERSONALES" << endl;
	cout << "Cargando datos de prueba..." << endl;
	cargarDatosPrueba();
	cout << "Datos cargados exitosamente." << endl;

	while (seguir) {
		mostrarMenuPrincipal();
		cin >> opcion;
		cin.ignore();

		if (opcion == 1) {
			mostrarTransacciones();

		} else if (opcion == 2) {
			string fecha, metodo;
			float monto;
			int tipo, categoria;
			bool necesario;

			cout << "\nAGREGAR TRANSACCION" << endl;
			cout << "Tipo (1=Gasto, 2=Ingreso, 3=Transferencia, 4=Pago a tarjeta): ";
			cin >> tipo;
			cin.ignore();

			cout << "Fecha (YYYY-MM-DD): ";
			getline(cin, fecha);

			cout << "Monto: $";
			cin >> monto;
			cin.ignore();

			if (tipo == 1 || tipo == 4) {
				cout << "Categoria (1=Comida, 2=Transporte, 3=Servicios, 4=Antojos, 5=Compras): ";
				cin >> categoria;
				cin.ignore();
			} else {
				categoria = 0;
			}

			metodo = seleccionarMetodoPago();

			if (tipo == 1) {
				cout << "Es necesario? (1=Si, 0=No): ";
				cin >> necesario;
				cin.ignore();
			} else {
				necesario = false;
			}

			agregarTransaccion(fecha, monto, categoria, tipo, metodo, necesario);

		} else if (opcion == 3) {
			int id;
			cout << "\nID a buscar: ";
			cin >> id;
			cin.ignore();

			cout << "Buscando..." << endl;
			int pos = busquedaLineal(id);

			if (pos != -1) {
				cout << "Encontrado en posicion: " << pos << endl;
				cout << transacciones.get(pos).toString() << endl;
			} else {
				cout << "No encontrado" << endl;
			}

		} else if (opcion == 4) {
			menuOrdenar();

		} else if (opcion == 5) {
			mostrarResumen();

		} else if (opcion == 6) {
			int tipo_busqueda;
			cout << "\nBUSCAR TRANSACCIONES" << endl;
			cout << "1. Por categoria" << endl;
			cout << "2. Gastos necesarios" << endl;
			cout << "3. Gastos no necesarios" << endl;
			cout << "Opcion: ";
			cin >> tipo_busqueda;
			cin.ignore();

			if (tipo_busqueda == 1) {
				int cat;
				cout << "\nCategoria (1=Comida, 2=Transporte, 3=Servicios, 4=Antojos, 5=Compras): ";
				cin >> cat;
				cin.ignore();
				buscarPorCategoria(cat);
				cout << "Total encontradas: " << contarPorCategoria(cat) << endl;
			} else if (tipo_busqueda == 2) {
				buscarPorNecesidad(true);
			} else if (tipo_busqueda == 3) {
				buscarPorNecesidad(false);
			} else {
				cout << "Opcion invalida" << endl;
			}

		} else if (opcion == 7) {
			menuBancosTarjetas();

		} else if (opcion == 8) {
			deshacerUltimaTransaccion();

		} else if (opcion == 9) {
			string archivo;
			cout << "\nNombre del archivo CSV: ";
			getline(cin, archivo);
			cargarDesdeCSV(archivo);

		} else if (opcion == 10) {
			string archivo;
			cout << "\nNombre del archivo CSV para guardar: ";
			getline(cin, archivo);
			guardarEnCSV(archivo);

		} else if (opcion == 0) {
			seguir = false;
			cout << "\nGracias por usar el sistema!" << endl;

		} else {
			cout << "\nOpcion no valida. Intente nuevamente." << endl;
		}
	}

	cout << "\nRESUMEN FINAL" << endl;
	cout << "Total de transacciones: " << transacciones.length() << endl;

	return 0;
}
