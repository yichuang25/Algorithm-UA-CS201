#include <iostream>
#include "CDA.cpp"

using namespace std;

int main () {
    CDA<int> A;
	for(int i=0; i<100000;i++) A.AddEnd(i);
    A.AddEnd(0);
    //cout << A.Ordered() << endl;
    cout << A.Select(4) << endl;
    //cout << A.Ordered() << endl;



    return 0;
}