
#include <iostream>

#include "List.h"
#include "ListNode.h"

using std::cout;
using std::endl;

List::List() : size(0), head(NULL) {
    cout << "A new list has been created at " << this << endl;
}

List::~List() {
    cout << "List at " << this << " has been destructed !" << endl;
}

int List::getSize() {
    return size;
}

bool List::isEmpty() {
    return head == NULL;
    //        return size == 0;
}

void List::print() {
    ListNode * current = head;
    while (current != NULL) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

void List::destruct() {
    ListNode * current = head;
    while (current != NULL) {
        ListNode * victim = current;
        current = current->getNext();
        delete victim;
    }
    size = 0;
}

void List::addAtFront(int data) {
    ListNode * n = new ListNode(data);
    n->setNext(head); // n->next = head;     same n->next = this->head;
    head = n;
    size++;
    cout << "Data " << data << " inserted to list successfully !" << endl;
}

int List::removeFromFront() {
    if (isEmpty()) {
        return 0; // better: throw exception
    } else {
        int pot = this->head->getData(); //  (*head).data;         
        ListNode * victim = head;
        head = head->getNext();
        delete victim;
        size--;
        return pot;
    }
}

void List::addAtBack(int data) {
    ListNode * n = new ListNode(data);

    if (isEmpty()) {
        head = n;
    } else {
        ListNode * last = head;
        while (last->getNext() != NULL) {
            last = last->getNext();
        }
        last->setNext(n);
    }
    size++;
}

int List::removeFromBack() {
    if (isEmpty()) {
        return 0;
    } else {
        ListNode * proteleftaio = head;
        while ((proteleftaio->getNext())->getNext() != NULL) {
            proteleftaio = proteleftaio->getNext();
        }
        ListNode * victim = proteleftaio->getNext();
        int pot = victim->getData();
        proteleftaio->setNext(NULL);
        size--;
        delete victim;
        return pot;
    }
}
