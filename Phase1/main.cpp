#include <iostream>
using namespace std;
#include "CDA.cpp"

int main(){
	CDA<int> A;
	A.AddFront(1);
	A.AddEnd(2);
	A.AddFront(3);
	A.AddEnd(4);
	A.AddFront(5);

	for (int i=0; i< A.Length();i++) cout << A[i] << " ";  cout << endl;
	//5 3 1 2 4

	cout << "Ordered 1: "<< A.Ordered() << endl;
	//0
	cout << "SetOrdered 1: " << A.SetOrdered() << endl;
	//-1

	A.CountingSort(5);
	cout << "Ordered 2: "<< A.Ordered() << endl;
	//1

	A.AddFront(6);
	A.AddEnd(7);
	A.AddFront(8);
	A.AddEnd(9);
	A.AddFront(10);
	for (int i=0; i< A.Length();i++) cout << A[i] << " ";  cout << endl;
	//10 8 6 1 2 3 4 5 7 9

	cout << "Ordered 3: "<< A.Ordered() << endl;
	//0

	cout << "Index is: "<< A.Search(1) << endl;
	//should use linear search, 3
	cout << A[A.Search(1)] << endl;
	//should be whatever you search for, 1
	CDA<int> B;
	B=A;
	//A.Printarray();
	//B.Printarray();
	B[3] = 14;
	B=B;

	cout << "A = ";
	for (int i=0; i< A.Length();i++) cout << A[i] << " ";  cout << endl;
	//A = 10 8 6 1 2 3 4 5 7 9
	cout << "B = ";
	for (int i=0; i< B.Length();i++) cout << B[i] << " ";  cout << endl;
	//B = 10 8 6 14 2 3 4 5 7 9

	cout << "Select 1: " << B.Select(4) << endl;
	cout << "Select 2: " << B.Select(5) << endl;
	//Should use quick select, 5, 6

	A.Clear();
	A.AddFront(1);
	A.AddEnd(2);
	A.AddFront(3);
	A.AddEnd(4);
	A.AddFront(5);
	cout << "A = ";
	for (int i=0; i< A.Length();i++) cout << A[i] << " ";  cout << endl;
	//5 3 1 2 4
	cout << "Search 1: "<<A.Search(8) << endl;
	//Should use linear search, -1

	B.InsertionSort();
	cout << "B = ";
	for (int i=0; i< B.Length();i++) cout << B[i] << " ";  cout << endl;
	//B = 2 3 4 5 6 7 8 9 10 14
	cout << "Ordered 4: "<< B.Ordered() << endl;
	//1
	cout << "Select 3: " << B.Select(6) << endl;
	//7
	//B.Printarray();
	cout << "Search 2: "<< B.Search(14) << endl;
	//Should use linear search, 9

	CDA<float> C(100000);
	for (int i=0; i< C.Length();i++) C[i] = i;
	while(C.Length() > 0){
		C.DelEnd(); //C.DelFront();
	}
	cout << "C = ";
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	//Either way should get C =

	cout << "Capacity: " << C.Capacity() << endl;
	//Capacity: 1

	C.AddEnd(10.9);
	C.AddEnd(10.8);
	C.AddEnd(10.7);
	C.AddEnd(10.6);
	C.AddEnd(10.5);
	cout << "C = ";
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	//C = 10.9 10.8 10.7 10.6 10.5

	C.InsertionSort();
	cout << "C = ";
	for (int i=0; i< C.Length();i++) cout << C[i] << " ";  cout << endl;
	//C = 10.5 10.6 10.7 10.8 10.9

	CDA<string> D;
	D.AddFront("Hello");
	D.AddEnd("Apple");
	D.AddFront("Zebra");
	D.AddEnd("Lamp");
	D.AddFront("Billy Club");
	D.AddEnd("Computer Science");
	cout << "D = ";
	for (int i=0; i< D.Length();i++) cout << D[i] << " ";  cout << endl;
	//D = Billy Club Zebra Hello Apple Lamp Computer Science

	cout << "Search 3: " << D.Search("Computer Science") << endl;
	////Should use linear search, 5
	cout << "Select 4: " << D.Select(3) << endl;
	////Should use quick select, Computer Science


	D.InsertionSort();
	cout << "D = ";
	for (int i=0; i< D.Length();i++) cout << D[i] << " ";  cout << endl;
	//D = Apple Billy Club Computer Science Hello Lamp Zebra

	cout << "Search 4: " << D.Search("Computer Science") << endl;
	//Should use linear search, 2
	cout << "Select 5: " << D.Select(3) << endl;
	//Should use quick select, Computer Science

	return 0;
}
