
#include <iostream>

#include "ListTemplate.h"
#include "ListNodeTemplate.h"

using std::cout;
using std::endl;

template <typename T>
ListTemplate<T>::ListTemplate() : size(0), head(NULL) {
    cout << "A new list has been created at " << this << endl;
}

template <typename T>
ListTemplate<T>::~ListTemplate() {
    cout << "List at " << this << " has been destructed !" << endl;
}

template <typename T>
int ListTemplate<T>::getSize() {
    return size;
}

template <typename T>
bool ListTemplate<T>::isEmpty() {
    return head == NULL;
    //        return size == 0;
}

template <typename T>
void ListTemplate<T>::print() {
    ListNodeTemplate<T> * current = head;
    while (current != NULL) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

template <typename T>
void ListTemplate<T>::destruct() {
    ListNodeTemplate<T> * current = head;
    while (current != NULL) {
        ListNodeTemplate<T> * victim = current;
        current = current->getNext();
        delete victim;
    }
    size = 0;
}

template <typename T>
void ListTemplate<T>::addAtFront(T data) {
    ListNodeTemplate<T> * n = new ListNodeTemplate<T>(data);
    n->setNext(head); // n->next = head;     same n->next = this->head;
    head = n;
    size++;
    cout << "Data " << data << " inserted to list successfully !" << endl;
}

template <typename T>
T ListTemplate<T>::removeFromFront() {
    if (isEmpty()) {
        return 0; // better: throw exception
    } else {
        T pot = this->head->getData(); //  (*head).data;         
        ListNodeTemplate<T> * victim = head;
        head = head->getNext();
        delete victim;
        size--;
        return pot;
    }
}

template <typename T>
void ListTemplate<T>::addAtBack(T data) {
    ListNodeTemplate<T> * n = new ListNodeTemplate<T>(data);

    if (isEmpty()) {
        head = n;
    } else {
        ListNodeTemplate<T> * last = head;
        while (last->getNext() != NULL) {
            last = last->getNext();
        }
        last->setNext(n);
    }
    size++;
}

template <typename T>
T ListTemplate<T>::removeFromBack() {
    if (isEmpty()) {
        return 0;
    } else {
        ListNodeTemplate<T> * proteleftaio = head;
        while ((proteleftaio->getNext())->getNext() != NULL) {
            proteleftaio = proteleftaio->getNext();
        }
        ListNodeTemplate<T> * victim = proteleftaio->getNext();
        T pot = victim->getData();
        proteleftaio->setNext(NULL);
        size--;
        delete victim;
        return pot;
    }
}

