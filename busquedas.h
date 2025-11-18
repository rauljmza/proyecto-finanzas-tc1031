/*
 * busquedas.h
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#ifndef BUSQUEDAS_H_
#define BUSQUEDAS_H_

#include "dlist.h"
#include "transaccion.h"

extern DList<Transaccion> transacciones;

int busquedaLineal(int id_buscar) {
	for (int i = 0; i < transacciones.length(); i++) {
		if (transacciones.get(i).getId() == id_buscar) {
			return i;
		}
	}
	return -1;
}

int contarPorCategoria(int categoria) {
	int contador = 0;
	for (int i = 0; i < transacciones.length(); i++) {
		if (transacciones.get(i).getCategoria() == categoria) {
			contador++;
		}
	}
	return contador;
}

#endif /* BUSQUEDAS_H_ */
