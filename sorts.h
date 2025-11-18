/*
 * sorts.h
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include "dlist.h"
#include "transaccion.h"

extern DList<Transaccion> transacciones;

void mostrarTransaccionesOrdenadas() {
	if (transacciones.empty()) {
		std::cout << "No hay transacciones" << std::endl;
		return;
	}

	std::cout << "\nTRANSACCIONES ORDENADAS" << std::endl;
	for (int i = 0; i < transacciones.length(); i++) {
		std::cout << transacciones.get(i).toString() << std::endl;
	}
}

void intercambiar(int i, int j) {
	Transaccion temp = transacciones.get(i);
	transacciones.set(i, transacciones.get(j));
	transacciones.set(j, temp);
}

void ordenarPorMonto() {
	int n = transacciones.length();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (transacciones.get(j).getMonto() > transacciones.get(j + 1).getMonto()) {
				intercambiar(j, j + 1);
			}
		}
	}
	std::cout << "\nTransacciones ordenadas por monto (menor a mayor)!" << std::endl;
	mostrarTransaccionesOrdenadas();
}

void ordenarPorFecha() {
	int n = transacciones.length();
	for (int i = 0; i < n - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < n; j++) {
			if (transacciones.get(j).getFecha() < transacciones.get(menor).getFecha()) {
				menor = j;
			}
		}
		if (menor != i) {
			intercambiar(i, menor);
		}
	}
	std::cout << "\nTransacciones ordenadas por fecha (cronologicamente)!" << std::endl;
	mostrarTransaccionesOrdenadas();
}

void ordenarPorCategoria() {
	int n = transacciones.length();
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && transacciones.get(j).getCategoria() < transacciones.get(j - 1).getCategoria()) {
			intercambiar(j, j - 1);
			j--;
		}
	}
	std::cout << "\nTransacciones ordenadas por categoria!" << std::endl;
	mostrarTransaccionesOrdenadas();
}

void ordenarPorTipo() {
	int n = transacciones.length();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (transacciones.get(j).getTipo() > transacciones.get(j + 1).getTipo()) {
				intercambiar(j, j + 1);
			}
		}
	}
	std::cout << "\nTransacciones ordenadas por tipo!" << std::endl;
	mostrarTransaccionesOrdenadas();
}

void ordenarPorMetodoPago() {
	int n = transacciones.length();
	for (int i = 0; i < n - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < n; j++) {
			if (transacciones.get(j).getMetodoPago() < transacciones.get(menor).getMetodoPago()) {
				menor = j;
			}
		}
		if (menor != i) {
			intercambiar(i, menor);
		}
	}
	std::cout << "\nTransacciones ordenadas por metodo de pago (alfabeticamente)!" << std::endl;
	mostrarTransaccionesOrdenadas();
}

void ordenarPorId() {
	int n = transacciones.length();
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && transacciones.get(j).getId() < transacciones.get(j - 1).getId()) {
			intercambiar(j, j - 1);
			j--;
		}
	}
	std::cout << "\nTransacciones ordenadas por ID!" << std::endl;
	mostrarTransaccionesOrdenadas();
}

#endif /* SORTS_H_ */
