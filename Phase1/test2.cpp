#include <iostream>
using namespace std;
#include "CDA.cpp"

void foo(CDA<int> x) {
	for (int i=0; i<x.Length()/2; i++)
		x[i] = x[x.Length()/2+i];
		cout << "SetOrdered in foo is " << x.SetOrdered() << endl;
		// x => "5 6 7 8 9 1 1 2 3 4 10" SetOrdered => -1	
}

int main(){
	CDA<float> C(10);
	for (int i=0; i< C.Length();i++) C[i] = i;
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8 9"
	C.DelFront();
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 9"
	C.DelEnd();
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8"
	C.AddEnd(100.0);
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 100"
	C.AddEnd(101.0);
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 100 101"
	C.DelEnd(); C.DelEnd();
	C.AddFront(-100.0); C.AddFront(-200.0);
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	// C => "-200 -100 1 2 3 4 5 6 7 8"


	CDA<int> A;
	for(int i=0; i<10;i++) A.AddEnd(i);
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" SetOrdered => 1
	cout << "Select is " << A.Select(3) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" Select => 2
	cout << "Search is " << A.Search(5) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" Search => 6
	A.AddFront(10); 
	// A => "10 0 1 2 3 4 5 6 7 8 9"
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" SetOrdered => -1
	cout << "Select is " << A.Select(3) << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" Select => 2
	cout << "Search is " << A.Search(5) << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" Search => 6
	A.InsertionSort();
	// A => "0 1 2 3 4 5 6 7 8 9 10"
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 10" SetOrdered => 1
	A.AddEnd(-1);
	// A => "0 1 2 3 4 5 6 7 8 9 10 -1"
	cout << "Ordered is " << A.Ordered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 10 -1" Ordered => False
	for (int i=0; i< A.Length();i++) cout << A[i] << " ";  cout << endl;

	A.QuickSort();
	for (int i=0; i< A.Length();i++) cout << A[i] << " ";  cout << endl;
	/*
	// A => "-1 0 1 2 3 4 5 6 7 8 9 10"
	cout << "Ordered is " << A.Ordered() << endl;
	// A => "-1 0 1 2 3 4 5 6 7 8 9 10" Ordered => True
	A.DelFront(); A.DelFront(); A.AddEnd(1);
	// A => "1 2 3 4 5 6 7 8 9 10 1"
	A.CountingSort(10);
	// A => "1 1 2 3 4 5 6 7 8 9 10"
	for (int i=0; i< A.Length();i++) cout << A[i] << " ";  cout << endl;

	foo(A);
	cout << "Ordered is " << A.Ordered() << endl;
	A.Printarray();
	// A => "1 1 2 3 4 5 6 7 8 9 10" Ordered => True
	*/
}