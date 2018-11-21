
#ifndef LISTNODETEMPLATE_H
#define	LISTNODETEMPLATE_H

template <typename T>
class ListNodeTemplate {
private:
    T data;
    ListNodeTemplate<T> * next;
public:

    ListNodeTemplate(T data, ListNodeTemplate<T>* next);
    ListNodeTemplate(T data);
    ListNodeTemplate(const ListNodeTemplate& other) ;
    
    ~ListNodeTemplate();


    ListNodeTemplate& operator=(const ListNodeTemplate& right);
    bool operator==(const ListNodeTemplate& right) const;

    T getData() const;
    void setData(const T data);

    ListNodeTemplate* getNext() const;
    void setNext(ListNodeTemplate * const next);
};

#endif	/* LISTNODETEMPLATE_H */

