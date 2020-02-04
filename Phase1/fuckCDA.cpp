#include <iostream>
using namespace std;
#include "CDA.cpp"
#include <ctime>
#include <stdlib.h>
#include <iomanip>

void counttime(time_t start, time_t end) {
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}



int main() {
    time_t start, end;
    srand(time(NULL));

    cout << "***********************Select***********************\n";
    start = clock();
    CDA<int> A;
    for(int i=0;i<100;i++){
        if(i%2 == 0){
            A.AddFront(i);
        }
        else {
            A.AddEnd(i);
        }
    }
    for (int i=0; i< 100;i++) cout << A[i] << " ";  cout << endl;
    cout << "Select 2 is: " << A.Select(2) << endl;
    A.QuickSort();
    for (int i=0; i< 100;i++) cout << A[i] << " ";  cout << endl;
    cout << "Select 3 is: " << A.Select(3) << endl;
    cout << "Select 0 is: " << A.Select(-1) << endl;
    end = clock();
    counttime(start,end);
    cout << "********************InsertionSort*******************\n";
    CDA<int> B;
    srand(time(NULL));
    start = clock();
    for(int i=0;i<1000;i++) {
        if(rand()%2 == 0){
            B.AddFront(rand());
        }
        else {
            B.AddEnd(rand());
        }
    }
    for (int i=0; i< 50;i++) cout << B[i] << " ";  cout << endl;
    cout << endl;
    B.InsertionSort();
    for (int i=0; i< 50;i++) cout << B[i] << " ";  cout << endl;
    end = clock();
    counttime(start,end);

    cout << "********************QuickSort***********************\n";
    CDA<int> C;
    srand(time(NULL));
    start = clock();
    for(int i=0;i<10000;i++) {
        if(rand()%2 == 0){
            C.AddFront(rand());
        }
        else {
            C.AddEnd(rand());
        }
    }
    for (int i=0; i< 50;i++) cout << C[i] << " ";  cout << endl;
    cout << endl;
    C.InsertionSort();
    for (int i=0; i< 50;i++) cout << C[i] << " ";  cout << endl;
    end = clock();
    counttime(start,end);

    cout << "***************QuickSort_Special********************\n";
    CDA<int> D;
    start = clock();
    for(int i=0;i<100;i++) {
        if(i == 0) {
            D.AddEnd(9);
        }
        else if(i>50 || i < 30){
            D.AddEnd(100);
        }
        else {
            D.AddEnd(i);
        }
    }
    for (int i=0; i< 100;i++) cout << D[i] << " ";  cout << endl << endl;
    D.InsertionSort();
    for (int i=0; i< 100;i++) cout << D[i] << " ";  cout << endl;
    end = clock();
    counttime(start,end);
    D.Clear();
    cout << endl;
    start = clock();
    for(int i=0;i<100;i++) {
        if(i == 0) {
            D.AddEnd(9);
        }
        else if(i>50 || i < 30){
            D.AddEnd(1);
        }
        else {
            D.AddEnd(i);
        }
    }
    for (int i=0; i< 100;i++) cout << D[i] << " ";  cout << endl << endl;
    D.InsertionSort();
    for (int i=0; i< 100;i++) cout << D[i] << " ";  cout << endl;
    end = clock();
    counttime(start,end);
    cout << "******************CountingSort**********************\n";
    CDA<int> E;
    start = clock();
    for(int i=0;i<100;i++) {
        if(i%2 == 0){
            E.AddFront(i%11);
        }
        else {
            E.AddEnd(i%11);
        }
    }
    for (int i=0; i< 100;i++) cout << E[i] << " ";  cout << endl << endl;
    E.CountingSort(10);
    for (int i=0; i< 100;i++) cout << E[i] << " ";  cout << endl;
    end = clock();
    counttime(start,end);
    cout << "*******************Search***************************\n";
    CDA<int> F;
    srand(time(NULL));
    start = clock();
    for(int i=0;i<10000;i++) {
        if(rand()%2 == 0){
            F.AddFront(rand());
        }
        else {
            F.AddEnd(rand());
        }
    }

    F.AddEnd(0);
    F.AddFront(1);
    cout <<"Search 0 is: " << F.Search(0) << endl;
    F.QuickSort();
    for (int i=0; i< 20;i++) cout << F[i] << " ";  cout << endl;
    cout <<"Search 1 is: " << F.Search(1) << endl;
    cout <<"Search 3 is: " << F.Search(3) << endl;



    cout << "****************************************************\n";
    A.Clear();
    B.Clear();
    C.Clear();
    D.Clear();
    E.Clear();
    F.Clear();

}