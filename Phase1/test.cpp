#include <iostream>
#include "CDA.cpp"

using namespace std;

int main () {
    CDA<int> a(1);
    cout << a.Capacity() << endl;
    a.AddEnd(1);
    a.Printarray();
    a.AddEnd(2);
    a.Printarray();
    a.AddEnd(3);
    a.AddEnd(4);
    a.AddEnd(5);
    a.Printarray();

    return 0;
}