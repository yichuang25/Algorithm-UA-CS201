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
    CDA<int> A;
    for(int i=0;i<10000;i++) {
        if(rand()%2 == 0){
            A.AddFront(rand());
        }
        else {
            A.AddEnd(rand());
        }
    }
    for (int i=0; i< 100;i++) cout << A[i] << " ";  cout << endl;
    cout << endl;
    
    A.AddEnd(1);
    start = clock();
    cout << "The position is: " << A.Search(1) << endl;
    end = clock(); 
    counttime(start,end);
    
    start = clock();
    A.InsertionSort();
    end = clock(); 
    counttime(start,end);
   

    start = clock();
    cout << "The position is: " << A.Search(1) << endl;
    end = clock(); 
    counttime(start,end);
    
    
    for (int i=0; i< 100;i++) cout << A[i] << " ";  cout << endl;

    CDA<int> B;
    for(int i=0;i<100;i++) {
        if(i%2 == 1) {
            B.AddEnd(1);
        }
        else{
            B.AddEnd(0);
        }
    }

    start = clock();
    B.Printarray();

    B.CountingSort(1);
    B.Printarray();
    
    end = clock(); 
    counttime(start,end);
    cout << "The position is: " << B.Search(2) << endl;
    






}