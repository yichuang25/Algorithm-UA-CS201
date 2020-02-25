#include <iostream>
#include <fstream>
using namespace std;
#include "CDA.cpp"

void test1(ostream &fp);
void test2(ostream &fp);
void test3(ostream &fp);
void test4(ostream &fp);
void test5(ostream &fp);
void test6(ostream &fp);

void foo(CDA<int> x) {
	for (int i=0; i<x.Length()/2; i++){
		int temp = x[i];
		x[i] = x[x.Length()/2+i];
		x[x.Length()/2+i] = temp;
	}
	cout << "SetOrdered in foo is " << x.SetOrdered() << endl;
	// x => "5 6 7 8 9 1 1 2 3 4 10" SetOrdered => -1	
}

int printWrapper = 0;

int main(int argc, char **argv){
	int testToRun = atoi(argv[1]);
	switch (testToRun){
		case 1:
			test1(cout);
			break;
		case 2:
			test2(cout);
			break;
		case 3:
			test3(cout);
			break;
		case 4:
			test4(cout);
			break;
		case 5:
			test5(cout);
			break;
		case 6:
			test6(cout);
			break;
	}
}

void test1(ostream &fp){
	if(printWrapper) fp << "Running test 1" << endl;
	//fp.open("test1.out");
	CDA<int> C(20);
	for (int i=0; i< C.Length();i++) C[i] = i*10;
	for (int i=0; i< C.Length();i++) fp << C[i] << " "; fp << endl;
	C.DelFront();
	for (int i=0; i< C.Length();i++) fp << C[i] << " ";  fp << endl;
	C.DelEnd();
	for (int i=0; i< C.Length();i++) fp << C[i] << " ";  fp << endl;
	C.AddEnd(1000);
	for (int i=0; i< C.Length();i++) fp << C[i] << " ";  fp << endl;
	C.AddEnd(1001);
	for (int i=0; i< C.Length();i++) fp << C[i] << " ";  fp << endl;
	C.DelEnd(); C.DelEnd();
	C.AddFront(-100); C.AddFront(-200);
	for (int i=0; i< C.Length();i++) fp << C[i] << " ";  fp << endl;
	fp << "Capacity is " << C.Capacity() << endl;

	CDA<int> A;
	int temp = 0;
	for(int i=0; i<20;i++){
		A.AddEnd(i*10);
		if(A.Capacity() != temp){
			temp = A.Capacity();
			fp << "Capacity is " << temp << " ";
		}
	}
    fp << endl;
	fp << "Capacity is " << A.Capacity() << endl;
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(3) << endl;
	fp << "Select is " << A.Search(50) << endl;
	A.AddFront(11); 
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(3) << endl;
	fp << "Select is " << A.Search(50) << endl;
	A.InsertionSort();
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	A.AddEnd(-10);
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	A.QuickSort();
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	A.DelFront(); A.DelFront(); A.AddEnd(51);
	for (int i=0; i< A.Length();i++) fp << A[i] << " ";  fp << endl;
	A.CountingSort(200);
	for (int i=0; i< A.Length();i++) fp << A[i] << " ";  fp << endl;
	CDA<int> B;
	B = A;
	A[0] = -1000;
	fp << B[0] << endl;
	foo(A);
	for (int i=0; i< B.Length();i++) fp << B[i] << " ";  fp << endl;
	CDA<long int> testGeneric1(10);
	CDA<short int> testGeneric2(10);
	CDA<double> testGeneric3(10);
	fp << "Passed Generics Test" << endl;
	//fp.close();
	if(printWrapper)fp << "-----------------Finished Test----------------------" << endl;
}

void test2(ostream &fp){
	if(printWrapper) fp << "Running test 2" << endl;
	CDA<int> A;
	for(int i = 0; i < 100000; i++) A.AddFront(i);
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(300) << endl;
	A.QuickSort();
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(3000) << endl;
	fp << "Search is " << A.Search(300) << endl;
	if(printWrapper) fp << "-----------------Finished Test----------------------" << endl;
}

void test3(ostream &fp){
	if(printWrapper) fp << "Running test 3" << endl;
	CDA<int> A;
	for(int i = 0; i < 10000; i++) A.AddFront(i);
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(300) << endl;
	A.InsertionSort();
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(3000) << endl;
	fp << "Search is " << A.Search(300) << endl;
	if(printWrapper) fp << "-----------------Finished Test----------------------" << endl;
}

void test4(ostream &fp){
	if(printWrapper) fp << "Running test 4" << endl;
	CDA<int> A;
	for(int i = 0; i < 10000; i++) A.AddFront(i);
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(300) << endl;
	A.CountingSort(10000);
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(3000) << endl;
	fp << "Search is " << A.Search(300) << endl;
	if(printWrapper) fp << "-----------------Finished Test----------------------" << endl;
}


void test5(ostream &fp){
	if(printWrapper) fp << "Running test 5" << endl;
	CDA<int> A;
	for(int i = 0; i < 10000; i++) A.AddFront(i*2);
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	for(int i = 1; i <= 10; i++)
		fp << "Select is " << A.Select(1000+i*2) << " "; 
	fp << endl;
	A.CountingSort(20000);
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	for(int i = 1; i <= 10; i++){		
		fp << "Select is " << A.Select(i*2) << " ";
	} 
	fp << endl;
	for(int i = 1; i <= 10; i++){		
		fp << "Search is " << A.Search(i*2) << " ";
	} 
	fp << endl;
	if(printWrapper) fp << "-----------------Finished Test----------------------" << endl;
}


void test6(ostream &fp){
	if(printWrapper) fp << "Running test 6" << endl;
	CDA<int> A;
	for(int i = 0; i < 100000; i++) A.AddFront(i*2);
	A.QuickSort();
	fp << "SetOrdered is " << A.SetOrdered() << endl;
	fp << "Select is " << A.Select(3000) << endl;
	fp << "Search is " << A.Search(30) << endl;
	fp << "Search is " << A.Search(300) << endl;
	fp << "Search is " << A.Search(3000) << endl;
	fp << "Search is " << A.Search(30001) << endl;
	if(printWrapper) fp << "-----------------Finished Test----------------------" << endl;
}


