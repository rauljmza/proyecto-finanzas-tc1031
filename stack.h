/*
 * stack.h
 *
 *  Created on: 21/10/2024
 *      Author: Raul Josue Mendoza Medina - A01712018
 */

#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <sstream>
#include <list>
#include "exception.h"

using std::string;
using std::stringstream;

template <class T>
class Stack {
public:
	virtual void push(T) = 0;
	virtual T top() const = 0;
	virtual void pop() = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
};

template <class T>
class StackList : public Stack<T> {
private:
	std::list<T> data;

public:
	void push(T);
	T top() const;
	void pop();
	bool empty() const;
	void clear();
};

template <class T>
void StackList<T>::push(T val) {
	data.push_front(val);
}

template <class T>
T StackList<T>::top() const {
	if (data.empty()) {
		throw NoSuchElement();
	}
	return data.front();
}

template <class T>
void StackList<T>::pop() {
	if (data.empty()) {
		throw NoSuchElement();
	}
	data.pop_front();
}

template <class T>
bool StackList<T>::empty() const {
	return data.empty();
}

template <class T>
void StackList<T>::clear() {
	data.clear();
}

#endif /* STACK_H_ */
