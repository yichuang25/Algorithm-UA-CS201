#include <iostream>
using namespace std;


template <class keytype, class valuetype>
struct Node
{
    keytype key;
    valuetype value;
};

template <class keytype, class valuetype>
class Heap {
private:
    Node<keytype,valuetype> *head;
    int length;
    int capacity;

public:
    Heap();
    Heap(keytype K[],valuetype V[],int s);
    ~Heap();
    Heap(const Heap &src);
    Heap& operator=(const Heap &src);
    keytype peekKey();
    valuetype peekValue();
    keytype extractMin();
    void insert(keytype k, valuetype v);
    void printKey();
};

template <class keytype, class valuetype>
Heap<keytype,valuetype> :: Heap() {
    capacity = 1;
    length = 0;
    head = new Node<keytype,valuetype>[capacity];
}

template <class keytype, class valuetype>
Heap<keytype, valuetype> :: Heap(keytype K[],valuetype V[],int s) {
    for(int i=0;i<s;i++) {
        insert(K[i],V[i]);
    }
}

template <class keytype, class valuetype>
Heap<keytype, valuetype> :: ~Heap() {
    delete[] head;
    capacity = 0;
    length = 0;
}

template <class keytype, class valuetype>
Heap<keytype, valuetype> :: Heap(const Heap &src) {
    capacity = src.capacity;
    length = src.length;
    head = new Node<keytype,valuetype>[capacity];
    for(int i=0;i<length;i++) {
        head[i] = src.head[i];
    }
}

template <class keytype, class valuetype>
Heap<keytype, valuetype> &Heap<keytype,valuetype> :: operator=(const Heap &src) {
    if(this != &src) {
        capacity = src.capacity;
        length = src.length;
        head = new Node<keytype,valuetype>[capacity];
        for(int i=0;i<length;i++) {
            head[i] = src.head[i];
        }
    }
}

template <class keytype, class valuetype>
keytype Heap<keytype, valuetype> :: peekKey() {
    if(length!=0) {
        return head->key;
    }
    else {
        return NULL;
    }
}

template <class keytype, class valuetype>
valuetype Heap<keytype, valuetype> ::peekValue() {
    if(length!=0) {
        return head->value;
    }
    else {
        return NULL;
    }
}

template <class keytype, class valuetype>
keytype Heap<keytype, valuetype> :: extractMin() {

}

template <class keytype, class valuetype>
void Heap<keytype, valuetype> :: insert(keytype k, valuetype v) {

}

template <class keytype, class valuetype>
void Heap<keytype, valuetype> :: printKey() {

}