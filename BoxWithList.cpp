#include <cstdlib>
#include <iostream>

#include "BoxWithList.h"
#include "List.h"

using namespace std;

BoxWithList::BoxWithList() {
    list = new List();
}

BoxWithList::~BoxWithList() {
    delete list;
}

BoxWithList::BoxWithList(const BoxWithList& box) : list(box.list) {
}

void BoxWithList::add(int data) {
    list->addAtBack(data);
}

int BoxWithList::remove() {
    int value = list->removeFromBack();
    return value;
}

bool BoxWithList::isEmpty(){
    return list->getSize() == 0;
}