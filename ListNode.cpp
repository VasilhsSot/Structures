#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode::ListNode(int data, ListNode* next) : data(data), next(next) {
    cout << "A new listnode has been created at " << this << "  with data " << data << endl;
}

ListNode::ListNode(int data) : data(data), next(NULL) {
    cout << "A new listnode has been created at " << this << " with data " << data << endl;
}

ListNode::~ListNode() {
    cout << "Listnode at " << this << " has been destroyed with data " << data << endl;
}

ListNode::ListNode(const ListNode& other) : data(other.data), next(other.next) {

}

ListNode& ListNode::operator=(const ListNode& right) {
    if (this == &right) {
        return *this; // Yes, so skip assignment, and just return *this.
    }
    return *this;
}

bool ListNode::operator==(const ListNode& right) const {
    bool result = false; // Compare right and *this here
    return result;
}

int ListNode::getData() const {
    return data;
}

void ListNode::setData(const int data) {
    this->data = data;
}

ListNode* ListNode::getNext() const {
    return next;
}

void ListNode::setNext(ListNode * const next) {
    this->next = next;
}