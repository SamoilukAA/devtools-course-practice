// Copyright 2022 Samoiluk Anastasiya

#ifndef MODULES_SAMOILUK_A_STACK_INCLUDE_SAMOILUK_A_STACK_H_
#define MODULES_SAMOILUK_A_STACK_INCLUDE_SAMOILUK_A_STACK_H_

#include <string>

template <class T>
class Stack {
    T* mem;
    int size;
    int i;
public:
    Stack(int _size = 100);
    Stack(const Stack& s);
    ~Stack();

    void push(T value);
    T pop();

    T getLast();
    T getSize();

    bool isEmpty();
    bool isFull();

    Stack& operator=(const Stack& s);
};

template <class T>
Stack<T>::Stack(int _size = 100) : size(_size) {
    if (size < 0) throw "Negative stack size";
    i = -1;
    mem = new T[size];
}

template <class T>
Stack<T>::Stack(const Stack& s) {
    size = s.size;
    i = s.i;
    mem = new T[size];
    for (int j = 0; j < i; j++)
        mem[j] = s.mem[j];
}

template <class T>
Stack<T>::~Stack() {
    if (mem != NULL)
        delete[] mem;
}

template <class T>
void Stack<T>::push(T value) {
    if (isFull()) throw "isFull";
    i++;
    mem[i] = value;
}

template <class T>
T Stack<T>::pop() {
    if (isEmpty()) throw "isEmpty";
    T value = mem[i];
    i--;
    return value;
}

template <class T>
T Stack<T>::getLast() { return mem[i]; }

template <class T>
T Stack<T>::getSize() { return size; }

template <class T>
bool Stack<T>::isEmpty() { return i < 0; }

template <class T>
bool Stack<T>::isFull() { return i >= size - 1; }

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
    if (&s == this) return *this;
    size = s.size;
    i = s.i;
    delete mem;
    mem = new T[size];
    for (int j = 0; j < i; j++)
        mem[j] = s.mem[j];
    return *this;
}

#endif  // MODULES_SAMOILUK_A_STACK_INCLUDE_SAMOILUK_A_STACK_H_
