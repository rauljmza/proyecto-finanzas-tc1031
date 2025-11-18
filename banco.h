/*
 * banco.h
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#ifndef BANCO_H_
#define BANCO_H_

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class TarjetaCredito {
public:
	TarjetaCredito();
	TarjetaCredito(string, float);

	string getNombre() const;
	float getLimite() const;
	string toString() const;

private:
	string nombre;
	float limite_credito;
};

TarjetaCredito::TarjetaCredito()
	: nombre(""), limite_credito(0.0) {
}

TarjetaCredito::TarjetaCredito(string n, float limite)
	: nombre(n), limite_credito(limite) {
}

string TarjetaCredito::getNombre() const {
	return nombre;
}

float TarjetaCredito::getLimite() const {
	return limite_credito;
}

string TarjetaCredito::toString() const {
	stringstream aux;
	aux << nombre << " (Credito) - Limite: $" << limite_credito;
	return aux.str();
}

class TarjetaDebito {
public:
	TarjetaDebito();
	TarjetaDebito(string, string);

	string getNombre() const;
	string toString() const;

private:
	string nombre;
	string banco;
};

TarjetaDebito::TarjetaDebito()
	: nombre(""), banco("") {
}

TarjetaDebito::TarjetaDebito(string n, string b)
	: nombre(n), banco(b) {
}

string TarjetaDebito::getNombre() const {
	return nombre;
}

string TarjetaDebito::toString() const {
	stringstream aux;
	aux << nombre << " (Debito) - Banco: " << banco;
	return aux.str();
}

class Banco {
public:
	Banco();
	Banco(string);

	string getNombre() const;
	string toString() const;

private:
	string nombre;
};

Banco::Banco()
	: nombre("") {
}

Banco::Banco(string n)
	: nombre(n) {
}

string Banco::getNombre() const {
	return nombre;
}

string Banco::toString() const {
	return nombre;
}

#endif /* BANCO_H_ */
