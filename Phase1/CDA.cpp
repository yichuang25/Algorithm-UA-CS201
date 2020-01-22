#include <iostream>
using namespace std;


template <class elmtype>
class CDA {

private:
    int front;
    int end;
    int capacity;
    int length;
    bool order;
    elmtype *array;

public:
    CDA();
    CDA(int s);
    ~CDA();
    elmtype& operator[](int i);
    void AddEnd(elmtype v);
    void AddFront(elmtype v);
    void DelEnd();
    void DelFront();
    int Length();
    int Capacity();
    int Clear();
    bool Ordered();
    int SetOrdered();
    elmtype Select(int k);
    void InsertionSort();
    void QuickSort();
    void CountingSort(int m);
    int Search(elmtype e);
};

template <class elmtype>
CDA<elmtype> :: CDA(){
    capacity = 1;
    length = 0;
    array = new elmtype[capacity];
    front = 0;
    end = 0;
    order = false;
}

template <class elmtype>
CDA<elmtype> :: CDA(int s) {
    capacity = s;
    length = 0;
    array = new elmtype[capacity];
    front = end = 0;
    order = false;
}

template <class elmtype>
CDA<elmtype> :: ~CDA() {
     delete array;
     capacity = NULL;
     front = NULL;
     end = NULL;
     length = NULL;
     order = NULL;
}

template <class elmtype>
elmtype& CDA<elmtype> :: operator[](int i) {
    
}

template <class elmtype>
void CDA<elmtype> :: AddEnd(elmtype v) {

}

template <class elmtype>
void CDA<elmtype> :: AddFront(elmtype v) {

}

template <class elmtype>
void CDA <elmtype> :: DelEnd(){

}

template <class elmtype>
void CDA <elmtype> :: DelFront() {

}

template <class elmtype>
int CDA <elmtype> :: Length() {

}

template <class elmtype>
int CDA <elmtype> :: Capacity() {

}

template <class elmtype>
int CDA <elmtype> :: Clear(){

}

template <class elmtype> 
bool CDA <elmtype> :: Ordered(){

}

template <class elmtype>
int CDA <elmtype> :: SetOrdered() {

}

template <class elmtype>
elmtype CDA <elmtype> :: Select(int k){

}

template <class elmtype>
void CDA <elmtype> :: InsertionSort() {

}

template  <class elmtype>
void CDA <elmtype> :: QuickSort() {

}

template <class elmtype>
void CDA <elmtype> :: CountingSort(int m){

}
template <class elmtype> 
int CDA <elmtype> :: Search (elmtype e){

}