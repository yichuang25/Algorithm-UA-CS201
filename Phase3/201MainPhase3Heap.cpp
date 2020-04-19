#include <iostream>
using namespace std;
#include "Heap.cpp"

void printErrors(string errors, int numOfErrors){
	if(numOfErrors < 5){
		cout << errors << " passed " << endl;
	}else if(numOfErrors < 100){
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
	}else if (numOfErrors < 1000){
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
	}else if (numOfErrors < 10000){
		cout << errors << " caused " << numOfErrors << " of errors ADD+1" << endl;
	}else{
		cout << errors << " caused " << numOfErrors << " of errors" << endl;
	}
}

int main(){
	string A[13] = {"AD","AB","AA","A","B","C","D","E","F","H","I","J","K"};
	int B[13] = {13,12,11,10,9,8,7,6,5,4,3,2,1};
	
	Heap<int,string> T1, T2(B,A,13);
	
	T2.printKey();
	//Should output  1 2 4 3 6 5 8 10 7 9
	
	for(int i=0; i<10; i++) T1.insert(B[i],A[9-i]);
	
	T1.printKey();
	// Should output 1 2 5 4 3 9 6 10 7 8
	
	cout << T2.peakValue() << endl;
	cout << T2.peakKey() << endl;
	cout << T2.extractMin() << endl;
	//Should output K
	
	cout << T1.peakValue() << endl;
	cout << T1.peakKey() << endl;
	cout << T1.extractMin() << endl;
	cout << T1.extractMin() << endl;
	cout << T1.extractMin() << endl;
	cout << T1.extractMin() << endl;
	//Should output 1
	
	T1.printKey();
	//Should output 2 3 5 4 8 9 6 10 7

	Heap<int,int> X;
	for(int i = 0; i < 100000; i++){
		X.insert(i,100000-i);
	}
	X.printKey();
	int peakKey=0;
	int peakValue=0;
	int extractMin=0;
	for(int i = 0; i < 99999; i++){
		if(X.peakKey() != i) peakKey++;
		if(X.peakValue() != 100000-i) peakValue++;
		if(X.extractMin() != i) extractMin++;
	}
	printErrors("peakKey",peakKey);
	printErrors("peakValue",peakValue);
	printErrors("extractMin",extractMin);
	return 0;
}
