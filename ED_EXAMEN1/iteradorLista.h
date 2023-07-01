#ifndef ITERADORLISTA_H
#define	ITERADORLISTA_H

#include "std.h"
#include "nodo.h"

template <class T>
class iteradorLista {
public:
    iteradorLista(nodo<T>*);
    virtual ~iteradorLista();

    virtual bool masElementos() const;
    virtual T* proximoElemento();
    virtual T* obtenerElemento();
    virtual nodo<T>* obtenerNodo();

private:
    nodo<T>* cursor;
};

template <class T>
iteradorLista<T>::iteradorLista(nodo<T>* primerNodo) {
    cursor = primerNodo;
}
template <class T>
bool iteradorLista<T>::masElementos() const {
    return (cursor != NULL);
}

template <class T>
T* iteradorLista<T>::proximoElemento() {
    T* r = NULL;
    if (masElementos()) {
        cursor = cursor->obtenerSiguiente();

        if (cursor == nullptr)
        {
            return NULL;
        }

        r = cursor->obtenerInfo();
    }
    return r;
}

template <class T>
T* iteradorLista<T>::obtenerElemento() {
    T* r = NULL;
    if (masElementos()) {
        //cursor = cursor->obtenerSiguiente();
        r = cursor->obtenerInfo();
    }
    return r;
}

template <class T>
nodo<T>* iteradorLista<T>::obtenerNodo() {
    //T* r = NULL;
    if (masElementos()) {
        cursor -> obtenerInfo();
        //cursor = cursor->obtenerSiguiente();
    }
    return cursor;
}

template <class T>
iteradorLista<T>::~iteradorLista() {
}
#endif	/* ITERADORLISTA_H */