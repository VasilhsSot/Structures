#include <iostream>
#include <cstdlib>

#include "ListTemplate_impl.h"

using namespace std;

template <typename T>
class Number {
public:
    T value;
    Number operator++ (int) {
        // -------------------------------------------------------- (1)
        // 1.
        Number pot = *this ;        // default cc-tor (pot.value = this->value)
        // 2.
        this->value++;
        // 3.
        return pot;        
        
        // -------------------------------------------------------- (2)
        // 1.
        Number pot;                 // default c-tor (pot.value = 0)
        // 2.
        pot.value = this->value++;
        // 3.
        return pot;
    }
};

int main(int argc, char** argv) {
    ListTemplate<int> l;
    
    for (int i=0;i<10;i++) {
        l.addAtBack(i);
        l.print();
    }
    for (int i=0;i<10;i++) {
        l.removeFromFront();
        l.print();
    }
   
    
    
    return 0;
}

