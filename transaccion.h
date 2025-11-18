/*
 * transaccion.h
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#ifndef TRANSACCION_H_
#define TRANSACCION_H_

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class Transaccion {
public:
	Transaccion();
	Transaccion(int, string, float, int, int, string, bool);

	int getId() const;
	string getFecha() const;
	float getMonto() const;
	int getCategoria() const;
	int getTipo() const;
	string getMetodoPago() const;
	bool getEsNecesario() const;
	string toString() const;
	string getCategoriaTexto() const;
	string getTipoTexto() const;

	void setCategoria(int);

private:
	int id;
	string fecha;
	float monto;
	int categoria;        // 1=Comida, 2=Transporte, 3=Servicios, 4=Antojos, 5=Compras
	int tipo;             // 1=Gasto, 2=Ingreso, 3=Transferencia, 4=Pago a tarjeta
	string metodo_pago;
	bool es_necesario;
};

Transaccion::Transaccion()
	: id(0), fecha(""), monto(0.0), categoria(0), tipo(0), metodo_pago(""), es_necesario(false) {
}

Transaccion::Transaccion(int i, string f, float m, int cat, int t, string mp, bool nec)
	: id(i), fecha(f), monto(m), categoria(cat), tipo(t), metodo_pago(mp), es_necesario(nec) {
}

int Transaccion::getId() const {
	return id;
}

string Transaccion::getFecha() const {
	return fecha;
}

float Transaccion::getMonto() const {
	return monto;
}

int Transaccion::getCategoria() const {
	return categoria;
}

int Transaccion::getTipo() const {
	return tipo;
}

string Transaccion::getMetodoPago() const {
	return metodo_pago;
}

bool Transaccion::getEsNecesario() const {
	return es_necesario;
}

string Transaccion::getCategoriaTexto() const {
	switch (categoria) {
		case 1: return "Comida y despensa";
		case 2: return "Transporte";
		case 3: return "Servicios";
		case 4: return "Antojos";
		case 5: return "Compras personales";
		default: return "Sin categoria";
	}
}

string Transaccion::getTipoTexto() const {
	switch (tipo) {
		case 1: return "Gasto";
		case 2: return "Ingreso";
		case 3: return "Transferencia";
		case 4: return "Pago a tarjeta";
		default: return "Desconocido";
	}
}

string Transaccion::toString() const {
	stringstream aux;
	aux << "ID: " << id << " - ";
	aux << "Fecha: " << fecha << " - ";
	aux << "Tipo: " << getTipoTexto() << " - ";
	aux << "Monto: $" << monto << " - ";
	aux << "Categoria: " << getCategoriaTexto() << " - ";
	aux << "Metodo: " << metodo_pago;
	if (tipo == 1) {
		aux << " - " << (es_necesario ? "Necesario" : "No necesario");
	}
	return aux.str();
}

void Transaccion::setCategoria(int c) {
	categoria = c;
}

#endif /* TRANSACCION_H_ */
