/*
 * recursion.h
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#ifndef RECURSION_H_
#define RECURSION_H_

#include "dlist.h"
#include "transaccion.h"

extern DList<Transaccion> transacciones;

int contarTransaccionesRec(int indice) {
	if (indice >= transacciones.length()) {
		return 0;
	}
	return 1 + contarTransaccionesRec(indice + 1);
}

#endif /* RECURSION_H_ */
