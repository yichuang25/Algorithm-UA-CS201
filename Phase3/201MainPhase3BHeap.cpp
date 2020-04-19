#include <iostream>
using namespace std;
#include "BHeap.cpp"

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
	
	BHeap<string,int> Z(A,B,13), Y;

	Z.printKey();
	//Should output 
	//B1
	//J K
	//
	//B3
	//A E H I F C D B

	cout << Z.extractMin() << endl;
	//Should output A
	
	Z.printKey();
	//Should output
	//B0
	//B
	//
	//B3
	//C E H I F J K D
	
	Y.insert("P", 100); 
	Y.insert("h", 101);
	Y.insert("a", 102);
	Y.insert("s", 103);
	Y.insert("e", 104);
	Y.insert("3", 105);
	
	Y.printKey();
	//Should output
	//B0
	//L
	//
	//B2
	//G M O N
	
	Y.merge(Z);
	cout << Y.peekKey() << endl;
	//Should output B
	
	Y.printKey();
	//Should output
	//B1
	//B L
	//
	//B2
	//G M O N
	//
	//B3
	//C E H I F J K D
	
	BHeap<int,int> X;
	for(int i = 0; i < 100000; i++){
		X.insert(i,100000-i);
	}
	int peekKey=0;
	int peekValue=0;
	int extractMin=0;
	for(int i = 0; i < 100000; i++){
		if(X.peekKey() != i) peekKey++;
		if(X.peekValue() != 100000-i) peekValue++;
		if(X.extractMin() != i) extractMin++;
	}
	printErrors("peekKey",peekKey);
	printErrors("peekValue",peekValue);
	printErrors("extractMin",extractMin);		
	
	BHeap<int,int> C,D;
	for(int i = 0; i < 100000; i++){
		C.insert(i,100000-i);
		D.insert(100000+i,200000-i);
	}
	C.merge(D);
	peekKey=0;
	peekValue=0;
	extractMin=0;
	for(int i = 0; i < 199999; i++){
		if(C.peekKey() != i) peekKey++;
		if(i < 100000 && C.peekValue() != 100000-i){
			peekValue++;
		}
		if(i > 99999 && C.peekValue() != 300000-i){
			peekValue++;
		}
		if(C.extractMin() != i) extractMin++;
	}
	printErrors("peekKey",peekKey);
	printErrors("peekValue",peekValue);
	printErrors("extractMin",extractMin);
	return 0;
}
