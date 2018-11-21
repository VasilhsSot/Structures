#ifndef BOXWITHLIST_H
#define	BOXWITHLIST_H

#include "List.h"

class BoxWithList {
private:
    List * list;
public:
    BoxWithList();
    BoxWithList(const BoxWithList& box);
    ~BoxWithList();
    
    void add(int data);
    int remove();
    
    bool isEmpty();
};

#endif	/* BOXWITHLIST_H */

