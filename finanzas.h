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
	std::cout << "\n=== CONSULTAR SALDO DE TARJETA DE CREDITO ===" << std::endl;
	std::cout << "Funcion en desarrollo (disenando la logica detras de esta funcion)" << std::endl;
	std::cout << "\nLogica pendiente:" << std::endl;
	std::cout << "- Rastrear saldo utilizado por transacciones tipo=1 con metodo=tarjeta credito" << std::endl;
	std::cout << "- Restar pagos tipo=4 del saldo utilizado" << std::endl;
	std::cout << "- Calcular saldo disponible = limite - saldo_utilizado" << std::endl;
	std::cout << "- Mostrar porcentaje de uso" << std::endl;
}

void pagarTarjetaCredito() {
	std::cout << "\n=== PAGAR TARJETA DE CREDITO ===" << std::endl;
	std::cout << "Funcion en desarrollo (disenando la logica detras de esta funcion)" << std::endl;
	std::cout << "\nLogica pendiente:" << std::endl;
	std::cout << "- Seleccionar tarjeta de credito a pagar" << std::endl;
	std::cout << "- Ingresar monto del pago" << std::endl;
	std::cout << "- Seleccionar cuenta origen (debito)" << std::endl;
	std::cout << "- Crear transaccion tipo=4 automaticamente" << std::endl;
	std::cout << "- Actualizar saldo de la tarjeta" << std::endl;
	std::cout << "- Validar que no se pague mas del saldo utilizado" << std::endl;
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
