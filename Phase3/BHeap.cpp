#include <iostream>
using namespace std;


template <class keytype, class valuetype>
struct Element
{
    keytype key;
    valuetype value;
    int degree;
    Element<keytype,valuetype> *parent, *child, *sibling;
};

template <class keytype, class valuetype>
class BHeap {
private:
    Element<keytype,valuetype> *head;

public:
    BHeap();
    BHeap(keytype K[],valuetype V[],int s);
    ~BHeap();
    BHeap(const BHeap &src);
    BHeap& operator=(const BHeap &src);
    keytype peekKey();
    valuetype peekValue();
    keytype extractMin();
    void insert(keytype k, valuetype v);
    void merge(BHeap<keytype,valuetype> &H2);
    void printKey();

};

template <class keytype, class valuetype>
BHeap<keytype,valuetype> :: BHeap() {
    
}

template <class keytype, class valuetype>
BHeap<keytype, valuetype> :: BHeap(keytype K[],valuetype V[],int s) {
    for(int i=0;i<s;i++) {
        
    }
}

template <class keytype, class valuetype>
BHeap<keytype, valuetype> :: ~BHeap() {

}

template <class keytype, class valuetype>
BHeap<keytype, valuetype> :: BHeap(const BHeap &src) {

}

template <class keytype, class valuetype>
BHeap<keytype, valuetype> &BHeap<keytype,valuetype> :: operator=(const BHeap &src) {

}

template <class keytype, class valuetype>
keytype BHeap<keytype, valuetype> :: peekKey() {

}

template <class keytype, class valuetype>
valuetype BHeap<keytype, valuetype> ::peekValue() {

}

template <class keytype, class valuetype>
keytype BHeap<keytype, valuetype> :: extractMin() {

}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: insert(keytype k, valuetype v) {

}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: merge(BHeap<keytype,valuetype> &H2) {
    
}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: printKey() {

}