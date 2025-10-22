/*
 * dlist.h
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

using std::string;
using std::stringstream;

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink *nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
public:
	DList();
	~DList();

	void add(T);
	int  length() const;
	T    get(int) const;
	bool empty() const;
	bool set(int, T);
	T    remove(int);

private:
	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;

	void clear();
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
int DList<T>::length() const {
	return size;
}

template <class T>
void DList<T>::add(T val) {
	DLink<T> *nuevo_nodo;

	nuevo_nodo = new DLink<T>(val);
	if (nuevo_nodo == 0) {
		throw OutOfMemory();
	}

	if (empty()) {
		head = nuevo_nodo;
		tail = nuevo_nodo;
	} else {
		tail->next = nuevo_nodo;
		nuevo_nodo->previous = tail;
		tail = nuevo_nodo;
	}
	size++;
}

template <class T>
T DList<T>::get(int index) const {
	int pos;
	DLink<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		return head->value;
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	return p->value;
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
bool DList<T>::set(int index, T val) {
	int pos;
	DLink<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	p->value = val;
	return true;
}

template <class T>
T DList<T>::remove(int index) {
	int pos;
	T val;
	DLink<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	p = head;

	if (index == 0) {
		val = p->value;
		if (head == tail) {
			head = 0;
			tail = 0;
		} else {
			head = p->next;
			head->previous = 0;
		}
		delete p;
		size--;
		return val;
	}

	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	val = p->value;
	p->previous->next = p->next;
	if (p->next != 0) {
		p->next->previous = p->previous;
	} else {
		tail = p->previous;
	}
	size--;

	delete p;

	return val;
}

#endif /* DLIST_H_ */
