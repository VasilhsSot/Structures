#ifndef LISTTEMPLATE_H
#define	LISTTEMPLATE_H

#include "ListNodeTemplate.h"

template <typename T>
class ListTemplate {
public:
    int size;
    ListNodeTemplate<T> * head;

    ListTemplate();
    ~ListTemplate();

    int getSize();
    bool isEmpty();
    void print();
    
    void destruct() ;
    
    void addAtFront(T data);
    T removeFromFront();

    void addAtBack(T data);
    T removeFromBack() ;
};



#endif	/* LISTTEMPLATE_H */

