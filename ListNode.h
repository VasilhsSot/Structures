
#ifndef LISTNODE_H
#define	LISTNODE_H

class ListNode {
private:
    int data;
    ListNode * next;
public:

    ListNode(int data, ListNode* next);
    ListNode(int data);
    ListNode(const ListNode& other) ;
    
    ~ListNode();


    ListNode& operator=(const ListNode& right);
    bool operator==(const ListNode& right) const;

    int getData() const;
    void setData(const int data);

    ListNode* getNext() const;
    void setNext(ListNode * const next);
};

#endif	/* LISTNODE_H */

