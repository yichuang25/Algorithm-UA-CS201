#ifndef _CDA_H_
#define _CDA_H_
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



#endif