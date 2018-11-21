#ifndef LIST_H
#define	LIST_H

#include "ListNode.h"

class List {
public:
    int size;
    ListNode * head;

    List();
    ~List();

    int getSize();
    bool isEmpty();
    void print();
    
    void destruct() ;
    
    void addAtFront(int data);
    int removeFromFront();

    void addAtBack(int data);
    int removeFromBack() ;
};


#endif	/* LIST_H */

