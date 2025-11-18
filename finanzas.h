/*
 * finanzas.h
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#ifndef FINANZAS_H_
#define FINANZAS_H_

#include <iostream>
#include <string>
#include <fstream>
#include "dlist.h"
#include "stack.h"
#include "transaccion.h"
#include "banco.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;

DList<Transaccion> transacciones;
DList<Banco> bancos;
DList<TarjetaCredito> tarjetas_credito;
DList<TarjetaDebito> tarjetas_debito;
StackList<Transaccion> historial_deshacer;

int siguiente_id = 1;

void agregarTransaccion(string fecha, float monto, int categoria, int tipo, string metodo_pago, bool es_necesario) {
	Transaccion nueva(siguiente_id++, fecha, monto, categoria, tipo, metodo_pago, es_necesario);
	transacciones.add(nueva);
	historial_deshacer.push(nueva);
	std::cout << "Transaccion agregada exitosamente!" << std::endl;
}

void mostrarTransacciones() {
	if (transacciones.empty()) {
		std::cout << "No hay transacciones registradas" << std::endl;
		return;
	}

	std::cout << "\nTODAS LAS TRANSACCIONES" << std::endl;
	for (int i = 0; i < transacciones.length(); i++) {
		std::cout << transacciones.get(i).toString() << std::endl;
	}
}

void mostrarResumen() {
	if (transacciones.empty()) {
		std::cout << "No hay transacciones para generar resumen" << std::endl;
		return;
	}

	float total_ingresos = 0.0;
	float total_gastos = 0.0;
	float total_necesarios = 0.0;
	float total_no_necesarios = 0.0;

	for (int i = 0; i < transacciones.length(); i++) {
		Transaccion t = transacciones.get(i);
		if (t.getTipo() == 2) {
			total_ingresos = total_ingresos + t.getMonto();
		} else if (t.getTipo() == 1) {
			total_gastos = total_gastos + t.getMonto();
			if (t.getEsNecesario()) {
				total_necesarios = total_necesarios + t.getMonto();
			} else {
				total_no_necesarios = total_no_necesarios + t.getMonto();
			}
		}
	}

	std::cout << "\nRESUMEN FINANCIERO" << std::endl;
	std::cout << "Total Ingresos: $" << total_ingresos << std::endl;
	std::cout << "Total Gastos: $" << total_gastos << std::endl;
	std::cout << "Gastos Necesarios: $" << total_necesarios << std::endl;
	std::cout << "Gastos No necesarios: $" << total_no_necesarios << std::endl;
}

void buscarPorCategoria(int cat) {
	bool encontrado = false;
	Transaccion temp;
	temp.setCategoria(cat);
	std::cout << "\nTRANSACCIONES EN CATEGORIA: " << temp.getCategoriaTexto() << std::endl;

	for (int i = 0; i < transacciones.length(); i++) {
		if (transacciones.get(i).getCategoria() == cat) {
			std::cout << transacciones.get(i).toString() << std::endl;
			encontrado = true;
		}
	}

	if (!encontrado) {
		std::cout << "No se encontraron transacciones en esta categoria" << std::endl;
	}
}

void buscarPorNecesidad(bool necesario) {
	bool encontrado = false;
	std::cout << "\nGASTOS " << (necesario ? "NECESARIOS" : "NO NECESARIOS") << std::endl;

	for (int i = 0; i < transacciones.length(); i++) {
		Transaccion t = transacciones.get(i);
		if (t.getTipo() == 1 && t.getEsNecesario() == necesario) {
			std::cout << t.toString() << std::endl;
			encontrado = true;
		}
	}

	if (!encontrado) {
		std::cout << "No se encontraron gastos " << (necesario ? "necesarios" : "no necesarios") << std::endl;
	}
}

void deshacerUltimaTransaccion() {
	if (historial_deshacer.empty()) {
		std::cout << "No hay transacciones para deshacer" << std::endl;
		return;
	}

	Transaccion ultima = historial_deshacer.top();
	historial_deshacer.pop();

	int id_a_eliminar = ultima.getId();
	for (int i = 0; i < transacciones.length(); i++) {
		if (transacciones.get(i).getId() == id_a_eliminar) {
			transacciones.remove(i);
			std::cout << "Se deshizo la ultima transaccion" << std::endl;
			return;
		}
	}
}

void agregarBanco(string nombre) {
	Banco nuevo(nombre);
	bancos.add(nuevo);
	std::cout << "Banco agregado: " << nombre << std::endl;
}

void mostrarBancos() {
	if (bancos.empty()) {
		std::cout << "No hay bancos registrados" << std::endl;
		return;
	}

	std::cout << "\nBANCOS REGISTRADOS" << std::endl;
	for (int i = 0; i < bancos.length(); i++) {
		std::cout << (i + 1) << ". " << bancos.get(i).toString() << std::endl;
	}
}

void agregarTarjetaCredito(string nombre, float limite) {
	TarjetaCredito nueva(nombre, limite);
	tarjetas_credito.add(nueva);
	std::cout << "Tarjeta de credito agregada: " << nombre << std::endl;
}

void agregarTarjetaDebito(string nombre, string banco) {
	TarjetaDebito nueva(nombre, banco);
	tarjetas_debito.add(nueva);
	std::cout << "Tarjeta de debito agregada: " << nombre << std::endl;
}

void mostrarTarjetasCredito() {
	if (tarjetas_credito.empty()) {
		std::cout << "No hay tarjetas de credito registradas" << std::endl;
		return;
	}

	std::cout << "\nTARJETAS DE CREDITO" << std::endl;
	for (int i = 0; i < tarjetas_credito.length(); i++) {
		std::cout << (i + 1) << ". " << tarjetas_credito.get(i).toString() << std::endl;
	}
}

void mostrarTarjetasDebito() {
	if (tarjetas_debito.empty()) {
		std::cout << "No hay tarjetas de debito registradas" << std::endl;
		return;
	}

	std::cout << "\nTARJETAS DE DEBITO" << std::endl;
	for (int i = 0; i < tarjetas_debito.length(); i++) {
		std::cout << (i + 1) << ". " << tarjetas_debito.get(i).toString() << std::endl;
	}
}

void consultarSaldoTarjetaCredito() {
	if (tarjetas_credito.empty()) {
		std::cout << "No hay tarjetas de credito registradas" << std::endl;
		return;
	}

	std::cout << "\n=== CONSULTAR SALDO DE TARJETA DE CREDITO ===" << std::endl;
	std::cout << "\nSeleccione tarjeta de credito:" << std::endl;

	for (int i = 0; i < tarjetas_credito.length(); i++) {
		std::cout << (i + 1) << ". " << tarjetas_credito.get(i).getNombre() << std::endl;
	}

	std::cout << "Opcion: ";
	int opcion;
	std::cin >> opcion;
	std::cin.ignore();

	if (opcion < 1 || opcion > tarjetas_credito.length()) {
		std::cout << "Opcion invalida" << std::endl;
		return;
	}

	TarjetaCredito tarjeta_seleccionada = tarjetas_credito.get(opcion - 1);
	string nombre_tarjeta = tarjeta_seleccionada.getNombre();
	float limite = tarjeta_seleccionada.getLimite();

	float total_gastos = 0.0;
	float total_pagos = 0.0;

	for (int i = 0; i < transacciones.length(); i++) {
		Transaccion t = transacciones.get(i);
		if (t.getMetodoPago() == nombre_tarjeta) {
			if (t.getTipo() == 1) {
				total_gastos = total_gastos + t.getMonto();
			} else if (t.getTipo() == 4) {
				total_pagos = total_pagos + t.getMonto();
			}
		}
	}

	float saldo_utilizado = total_gastos - total_pagos;
	if (saldo_utilizado < 0) {
		saldo_utilizado = 0;
	}

	float saldo_disponible = limite - saldo_utilizado;
	float porcentaje_uso = (saldo_utilizado / limite) * 100;

	std::cout << "\n=== RESUMEN DE TARJETA ===" << std::endl;
	std::cout << "Tarjeta: " << nombre_tarjeta << std::endl;
	std::cout << "Limite de credito: $" << limite << std::endl;
	std::cout << "Total de gastos: $" << total_gastos << std::endl;
	std::cout << "Total de pagos: $" << total_pagos << std::endl;
	std::cout << "Saldo utilizado: $" << saldo_utilizado << std::endl;
	std::cout << "Saldo disponible: $" << saldo_disponible << std::endl;
	std::cout << "Porcentaje de uso: " << porcentaje_uso << "%" << std::endl;
}

void pagarTarjetaCredito() {
	if (tarjetas_credito.empty()) {
		std::cout << "No hay tarjetas de credito registradas" << std::endl;
		return;
	}

	if (tarjetas_debito.empty()) {
		std::cout << "No hay tarjetas de debito para realizar el pago" << std::endl;
		return;
	}

	std::cout << "\n=== PAGAR TARJETA DE CREDITO ===" << std::endl;
	std::cout << "\nSeleccione tarjeta de credito a pagar:" << std::endl;

	for (int i = 0; i < tarjetas_credito.length(); i++) {
		std::cout << (i + 1) << ". " << tarjetas_credito.get(i).getNombre() << std::endl;
	}

	std::cout << "Opcion: ";
	int opcion_credito;
	std::cin >> opcion_credito;
	std::cin.ignore();

	if (opcion_credito < 1 || opcion_credito > tarjetas_credito.length()) {
		std::cout << "Opcion invalida" << std::endl;
		return;
	}

	TarjetaCredito tarjeta_a_pagar = tarjetas_credito.get(opcion_credito - 1);
	string nombre_tarjeta_credito = tarjeta_a_pagar.getNombre();
	float limite = tarjeta_a_pagar.getLimite();

	float total_gastos = 0.0;
	float total_pagos = 0.0;

	for (int i = 0; i < transacciones.length(); i++) {
		Transaccion t = transacciones.get(i);
		if (t.getMetodoPago() == nombre_tarjeta_credito) {
			if (t.getTipo() == 1) {
				total_gastos = total_gastos + t.getMonto();
			} else if (t.getTipo() == 4) {
				total_pagos = total_pagos + t.getMonto();
			}
		}
	}

	float saldo_utilizado = total_gastos - total_pagos;
	if (saldo_utilizado < 0) {
		saldo_utilizado = 0;
	}

	if (saldo_utilizado == 0) {
		std::cout << "La tarjeta no tiene saldo pendiente de pago" << std::endl;
		return;
	}

	std::cout << "\nSaldo actual a pagar: $" << saldo_utilizado << std::endl;
	std::cout << "Ingrese el monto a pagar: $";

	float monto_pago;
	std::cin >> monto_pago;
	std::cin.ignore();

	if (monto_pago <= 0) {
		std::cout << "El monto debe ser mayor a cero" << std::endl;
		return;
	}

	if (monto_pago > saldo_utilizado) {
		std::cout << "No puede pagar mas del saldo utilizado ($" << saldo_utilizado << ")" << std::endl;
		return;
	}

	std::cout << "\nSeleccione tarjeta de debito origen:" << std::endl;

	for (int i = 0; i < tarjetas_debito.length(); i++) {
		std::cout << (i + 1) << ". " << tarjetas_debito.get(i).getNombre() << std::endl;
	}

	std::cout << "Opcion: ";
	int opcion_debito;
	std::cin >> opcion_debito;
	std::cin.ignore();

	if (opcion_debito < 1 || opcion_debito > tarjetas_debito.length()) {
		std::cout << "Opcion invalida" << std::endl;
		return;
	}

	TarjetaDebito tarjeta_origen = tarjetas_debito.get(opcion_debito - 1);
	string nombre_tarjeta_debito = tarjeta_origen.getNombre();

	std::cout << "Ingrese la fecha del pago (YYYY-MM-DD): ";
	string fecha_pago;
	getline(std::cin, fecha_pago);

	agregarTransaccion(fecha_pago, monto_pago, 0, 4, nombre_tarjeta_credito, false);

	float nuevo_saldo = saldo_utilizado - monto_pago;
	float saldo_disponible = limite - nuevo_saldo;

	std::cout << "\n=== PAGO EXITOSO ===" << std::endl;
	std::cout << "Se pago: $" << monto_pago << std::endl;
	std::cout << "Desde: " << nombre_tarjeta_debito << std::endl;
	std::cout << "A: " << nombre_tarjeta_credito << std::endl;
	std::cout << "Nuevo saldo utilizado: $" << nuevo_saldo << std::endl;
	std::cout << "Saldo disponible: $" << saldo_disponible << std::endl;
}

void mostrarMetodosPagoDisponibles() {
	int total_metodos = tarjetas_debito.length() + tarjetas_credito.length();

	if (total_metodos == 0) {
		std::cout << "No hay metodos de pago registrados" << std::endl;
		return;
	}

	std::cout << "\nMETODOS DE PAGO DISPONIBLES" << std::endl;
	int contador = 1;

	for (int i = 0; i < tarjetas_debito.length(); i++) {
		std::cout << contador << ". " << tarjetas_debito.get(i).getNombre() << " (Debito)" << std::endl;
		contador++;
	}

	for (int i = 0; i < tarjetas_credito.length(); i++) {
		std::cout << contador << ". " << tarjetas_credito.get(i).getNombre() << " (Credito)" << std::endl;
		contador++;
	}

	std::cout << "\nUse estos numeros en el archivo CSV para la columna MetodoPago" << std::endl;
}

string obtenerMetodoPagoPorNumero(int numero) {
	int total_metodos = tarjetas_debito.length() + tarjetas_credito.length();

	if (numero < 1 || numero > total_metodos) {
		return "Efectivo";
	}

	if (numero <= tarjetas_debito.length()) {
		return tarjetas_debito.get(numero - 1).getNombre();
	} else {
		int indice_credito = numero - tarjetas_debito.length() - 1;
		return tarjetas_credito.get(indice_credito).getNombre();
	}
}

string seleccionarMetodoPago() {
	int total_metodos = tarjetas_debito.length() + tarjetas_credito.length();

	if (total_metodos == 0) {
		std::cout << "No hay metodos de pago registrados. Ingrese uno manualmente: ";
		string metodo;
		getline(std::cin, metodo);
		return metodo;
	}

	mostrarMetodosPagoDisponibles();

	std::cout << (total_metodos + 1) << ". Otro (escribir manualmente)" << std::endl;
	std::cout << "Seleccione metodo de pago: ";

	int opcion;
	std::cin >> opcion;
	std::cin.ignore();

	if (opcion < 1 || opcion > total_metodos + 1) {
		std::cout << "Opcion invalida. Usando 'Efectivo'" << std::endl;
		return "Efectivo";
	}

	if (opcion == total_metodos + 1) {
		std::cout << "Ingrese metodo de pago: ";
		string metodo;
		getline(std::cin, metodo);
		return metodo;
	}

	return obtenerMetodoPagoPorNumero(opcion);
}

void cargarDatosPrueba() {
	agregarBanco("Didi");
	agregarBanco("Mercado Pago");
	agregarBanco("Nu");

	agregarTarjetaDebito("Didi", "Didi");
	agregarTarjetaDebito("Mercado Pago Debito", "Mercado Pago");
	agregarTarjetaCredito("Mercado Pago Credito", 4030.0);
	agregarTarjetaDebito("Nu Debito", "Nu");
	agregarTarjetaCredito("Nu Credito", 2050.0);

	agregarTransaccion("2024-10-21", 111479.09, 0, 2, "Didi", false);
	agregarTransaccion("2024-10-21", 25000.0, 0, 2, "Mercado Pago Debito", false);
	agregarTransaccion("2024-10-21", 118607.41, 0, 2, "Nu Debito", false);
}

bool cargarDesdeCSV(string nombre_archivo) {
	ifstream archivo(nombre_archivo.c_str());
	if (!archivo.is_open()) {
		std::cout << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
		return false;
	}

	string linea;
	int contador = 0;

	getline(archivo, linea);

	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string fecha, metodo;
		float monto;
		int categoria, tipo, numero_metodo;
		bool necesario;
		char delim;

		getline(ss, fecha, ',');
		ss >> monto >> delim;
		ss >> categoria >> delim;
		ss >> tipo >> delim;
		ss >> numero_metodo >> delim;
		ss >> necesario;

		metodo = obtenerMetodoPagoPorNumero(numero_metodo);

		agregarTransaccion(fecha, monto, categoria, tipo, metodo, necesario);
		contador++;
	}

	archivo.close();
	std::cout << "Se cargaron " << contador << " transacciones desde " << nombre_archivo << std::endl;
	return true;
}

void guardarEnCSV(string nombre_archivo) {
	ofstream archivo(nombre_archivo.c_str());
	if (!archivo.is_open()) {
		std::cout << "Error: No se pudo crear el archivo " << nombre_archivo << std::endl;
		return;
	}

	archivo << "Fecha,Monto,Categoria,Tipo,MetodoPago,EsNecesario" << std::endl;

	for (int i = 0; i < transacciones.length(); i++) {
		Transaccion t = transacciones.get(i);
		archivo << t.getFecha() << ","
		        << t.getMonto() << ","
		        << t.getCategoria() << ","
		        << t.getTipo() << ","
		        << t.getMetodoPago() << ","
		        << t.getEsNecesario() << std::endl;
	}

	archivo.close();
	std::cout << "Transacciones guardadas en " << nombre_archivo << std::endl;
}

#endif /* FINANZAS_H_ */
