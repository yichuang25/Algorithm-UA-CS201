#include <iostream>
using namespace std;
#include "Heap.cpp"

int main() {
    Heap<int,int> A;
    for(int i=1;i<=10;i++) {
        A.insert(i,i);
    }
    A.printArray();
    cout << A.extractMin() << endl;
    A.printArray();
    cout << A.extractMin() << endl;
    A.printArray();
    cout << A.extractMin() << endl;
    A.printArray();
    //A.printKey();
    return 0;
}