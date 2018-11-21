#include <stdexcept>
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T /*= int*/>
class Box {
private:
    int index;
    int total_items;
    int capacity;
    T * array;
public:
    // C-tor:    
    Box() : index(0), total_items(0), capacity(1) {
        array = new T[capacity];
        array[0] = 0;
    }
    // D-tor:
    ~Box() {
        delete [] array;
    }
    
    // add
    void add(T value) {
        array[index] = value;
        index++;
        total_items++;
        
        if (total_items == capacity) {  // box is full, double its size:
            T * temp = array;
            
            array = new T[capacity*2];
            for (int i=0;i<capacity;i++) {
                array[i] = temp[i];
            }
            for (int i=capacity;i<capacity*2;i++) {
                array[i] =0;
            }
            
            delete temp;
            capacity = capacity*2;
        }
    }
    
    // remove
    T remove() {
        if (total_items== 0) {
            throw std::invalid_argument("end of the world version 2 ! ");
        }
        index--;
        total_items--;
        T pot = array[index];
        array[index] = 0;
        
        if (total_items == capacity/2 && capacity/2 > 1) {
            T * temp = array;
            
            array = new T[capacity/2];
            for (int i=0;i<capacity/2;i++) {
                array[i] = temp[i];
            }
            
            delete temp;
            capacity = capacity/2;
        }
        
        return pot;
    }
    
    // isEmpty
    bool isEmpty() const {
        if (total_items == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    // isFull
    bool isFull() const {
        return total_items == capacity;
    }
    
    // CC-tor:
    Box(const Box& box) : index(box.index), total_items(box.total_items), capacity(box.capacity) {
        array = new T[capacity];
        for (int i=0;i<capacity;i++) {
            array[i] = box.array[i];
        }
    }
    
    // op=
    Box<T>& operator=(const Box<T> & box) {
        index = box.index;
        total_items = box.total_items;
        
        if (capacity == box.capacity) {
            for (int i=0;i<capacity;i++) {
                array[i] = box.array[i];
            }
        } else if (capacity > box.capacity) {
            for (int i=0;i<box.capacity;i++) {
                array[i] = box.array[i];
            }
            for (int i = box.capacity;i<capacity;i++) {
                array[i] = 0;
            }
        } else {
            delete [] array;
            capacity = box.capacity;
            array = new T[capacity];
            for (int i=0;i<capacity;i++) {
                array[i] = box.array[i];
            }
        }
        return *this;
    }
    
    // op==
    bool operator==(const Box<T> & box) const {
        if (total_items == box.total_items) {
            for (int i=0;i<total_items;i++) {
                if (array[i] != box.array[i]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // op!=
    bool operator!=(const Box<T> & box) const {
        return !(*this == box);
    }
    
    // op+=
    Box<T>& operator+=(const T value) {
        add(value);
        return *this;
    }
    
    Box<T>& operator+=(Box<T> & box) {
        while (!box.isEmpty()) {
//            int pot = box.remove();
//            this->add(pot);
            add(box.remove());
        }
        return *this;
    }

    // op <<
    Box<T>& operator<<(T value) {
        add(value);
        return *this;
    }
    
    // op >>
    Box<T>& operator>>(T & value) {
        value = remove();
        return *this;
    }
    
    void print() const {
        for (int i=0;i<total_items;i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
    
    // Accessors / mutators
    T* getArray() const {
        return array;
    }
    int getIndex() const {
        return index;
    }
    int getCapacity() const {
        return capacity;
    }
    int getSize() const {
        return total_items;
    }

    template <typename W>
    friend ostream& operator<<(ostream& out, Box<W> & box);
    
//    template <typename W>
//    friend istream& operator>>(ostream& out, Box & box);
};

template <typename W>
ostream& operator<<(ostream& out, Box<W> & box) {
    out << "Capacity      : " << box.capacity << endl;
    out << "Total items   : " << box.total_items  << endl;
    out << "List of items : ";
    
    out << "{ ";
    for (int i=0;i<box.total_items;i++) {
        if (i>0) {
            cout << ",";
        }
        cout << box.array[i];
    }
    cout << "}" << endl;
    return out;
}
//
//int main(int argc, char* argv[]) {
//    Box<int> b;
//    Box<int> c;
//    
//    Box<float> f;
//    
//    b += 1;
//    b += 2;
//    b += 3;
//    b += 4;
////    b.add(5);
////    cout << b;
//    
//    c += 10;
//    c += 20;
//    
//    b += c;
// 
////    cout << b;
//    
//    f << 1.0f;
//    f << 2.0f;
//    f << 3.0f;
//    
////    Box q;
//    
//    return 0;
//}