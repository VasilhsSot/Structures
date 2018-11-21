
#ifndef LISTNODETEMPLATE_IMPL_H
#define	LISTNODETEMPLATE_IMPL_H

#include <iostream>
#include "ListNodeTemplate.h"

using namespace std;

template <typename T>
ListNodeTemplate<T>::ListNodeTemplate(T data, ListNodeTemplate<T>* next) : data(data), next(next) {
    cout << "A new ListNodeTemplate has been created at " << this << "  with data " << data << endl;
}

template <typename T>
ListNodeTemplate<T>::ListNodeTemplate(T data) : data(data), next(NULL) {
    cout << "A new listnode has been created at " << this << " with data " << data << endl;
}

template <typename T>
ListNodeTemplate<T>::~ListNodeTemplate() {
    cout << "Listnode at " << this << " has been destroyed with data " << data << endl;
}

template <typename T>
ListNodeTemplate<T>::ListNodeTemplate(const ListNodeTemplate<T>& other) : data(other.data), next(other.next) {

}

template <typename T>
ListNodeTemplate<T>& ListNodeTemplate<T>::operator=(const ListNodeTemplate<T>& right) {
    if (this == &right) {
        return *this; // Yes, so skip assignment, and just return *this.
    }
    return *this;
}

template <typename T>
bool ListNodeTemplate<T>::operator==(const ListNodeTemplate<T>& right) const {
    bool result = false; // Compare right and *this here
    return result;
}

template <typename T>
T ListNodeTemplate<T>::getData() const {
    return data;
}

template <typename T>
void ListNodeTemplate<T>::setData(const T data) {
    this->data = data;
}

template <typename T>
ListNodeTemplate<T>* ListNodeTemplate<T>::getNext() const {
    return next;
}

template <typename T>
void ListNodeTemplate<T>::setNext(ListNodeTemplate<T> * const next) {
    this->next = next;
}

#endif	/* LISTNODETEMPLATE_IMPL_H */

