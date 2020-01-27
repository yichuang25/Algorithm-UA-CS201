#include <iostream>
#include "CDA.cpp"

using namespace std;

int main () {
    /*cout << "Test add end\n";
    CDA<int> a;
    a.Printarray();

    a.AddEnd(0);
    a.Printarray();

    a.AddEnd(1);
    a.Printarray();

    a.AddEnd(2);
    a.Printarray();

    a.AddEnd(3);
    a.Printarray();

    a.AddEnd(4);
    a.Printarray();

    a.AddEnd(5);
    a.Printarray();*/
    cout << "Test add Front\n";
    CDA<int> b;
    b.Printarray();

    b.AddFront(0);
    b.Printarray();

    b.AddFront(1);
    b.Printarray();

    b.AddFront(2);
    b.Printarray();

    b.AddFront(3);
    b.Printarray();

    b.AddFront(4);
    b.Printarray();

    b.AddFront(5);
    b.Printarray();

    b.AddEnd(6);
    b.Printarray();

    b.AddEnd(7);
    b.Printarray();

    b.AddFront(8);
    b.Printarray();

    b.AddEnd(4);
    b.Printarray();

    b.SetOrdered();
    cout << b.Ordered() << endl;

    b.InsertionSort();
    b.Printarray();
    b.SetOrdered();
    cout << b.Ordered() << endl;


    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    b.DelFront();
    b.Printarray();

    return 0;
}