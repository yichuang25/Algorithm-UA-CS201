#include <iostream>
#include <cstdlib>
using namespace std;
#include "RBTree.cpp"
#include <stdlib.h>
#include <iomanip>
#include <ctime>

void counttime(time_t start, time_t end) {
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}

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

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void removeIndex(int removeIndex);

int main(int argc, char **argv){
	int testToRun = atoi(argv[1]);
	time_t start, end;
	start = clock();
	//int testToRun = 4;
	switch (testToRun){
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
			break;
		case 5:
			test5();
			break;
		case 6:
			test6();
			break;
	}
	end = clock();
	counttime(start,end);
	return 0;
}


void test1(){
	string K[10] = {"A","B","C","D","E","F","H","I","J","K"};
	int V[10] = {10,9,8,7,6,5,4,3,2,1};
	
	RBTree<string,int> T1, T2(K,V,10);
	T2.postorder();
	cout << endl;
	//A C B E H F J K I D
	
	for(int i=0; i<10; i++) T1.insert(K[i],V[i]);
	// T1 and T2 should be identical trees
	
	T1.insert("AA",11);
	T1.insert("AB",12);
	T1.insert("AC",13);
	cout << *(T1.search("AB")) << endl;
	// Should output 12
	
	cout << T1.rank("H") << endl;
	//Should output 10
	
	cout << T1.select(3) << endl;
	//Should output AB 
	
	T1.preorder();
	cout << endl;
	//Should output D B AA A AC AB C I F E H K J
	
	T1.inorder();
	cout << endl;
	//Should output	A AA AB AC B C D E F H I J K
	
	cout << T1.remove("HA") << endl;
	//Should output 0
	
	cout << T1.remove("AA") << endl;
	//Should output 1
	
	cout <<T1.rank("J") << endl;
	//Should output 11
	
	T1.inorder();
	cout << endl;
	//Should output	A AB AC B C D E F H I J K
	cout << "Finished without failing" << endl << endl;
}

void test2(){
	
	RBTree<int,int> X;
	for (int i=100;i>=0;i--) X.insert(i,100-i);
	X.preorder(); 
    cout << endl;
	X.postorder();
    cout << endl;
	X.inorder();
    cout << endl;
	RBTree<int,int> Y = X;
	for (int i=0; i < 98; i++){
		X.rank(i);
		X.remove(i);
	}
	Y.preorder();
    cout << endl;
	Y.postorder();
    cout << endl;
	Y.inorder();
    cout << endl;
	cout << "Finished without failing" << endl << endl;
}

void test3(){
	int rankError = 0;
	int selectError = 0;
	int searchError = 0;
    RBTree<int,int> X;
	for (int i=100000;i>=0;i--) X.insert(i,100000-i);
	for (int i=1;i<100000;i++) {
		// cout << i+1 << " is i+1" << endl;
		// cout << X.rank(i) << " is rank" << endl;
		if(X.rank(i) != i+1) rankError++; //cout << "Rank error before delete" << endl;
		if(X.select(i) != i-1) selectError++; //cout << "Select error before delete" << endl;
		if(*(X.search(i)) != 100000-i) searchError++;//cout << "Search error before delete" << endl;
	}
	printErrors("Rank",rankError);
	printErrors("Select",selectError);
	printErrors("Search",searchError);
	cout << "Finished without failing" << endl << endl;
}

void test4(){
	removeIndex(11);
}

void test5(){
	removeIndex(17);
}

void test6(){
	RBTree<int,int> X;
	int predErrors = 0;
	int succErrors = 0;
    int size = 10000;
	for (int i=size;i>=0;i--) X.insert(i,size-i);
	for (int i=0; i < X.size(); i++){
		if(i == 0){
            if(X.predecessor(i) != NULL) cout << "Doesn't return NULL for predecessor" << endl;
		}
        else if(*(X.predecessor(i)) != i-1){
            predErrors++;
            //printf("pred error %d\n",predErrors);
        }
	}
	printErrors("Pred errors",predErrors);
	for (int i=X.size()-1; i >= 0; i--){
		if(i == size){
            if(X.successor(i) != NULL) cout << "Doesn't return NULL for successor" << endl;
		}
        else if(*(X.successor(i)) != i+1){ 
            succErrors++;
            //printf("pred error %d\n",predErrors);
        }
	}	
	printErrors("Succ Errors",succErrors);
	cout << "Finished without failing" << endl << endl;
}


void removeIndex(int removeIndex){
	int rankError = 0;
	int selectError = 0;
	int searchError = 0;
    RBTree<int,int> X;
	int size = 100000;
    for (int i=size;i>=0;i--) X.insert(i,size-i);
	for (int i=0;i<size;i+=removeIndex) X.remove(i);
	for (int i=1;i<size-size/removeIndex;i++){ // Problem in here
        //cout << i << endl;
        int part1Answer = i / removeIndex;
		int answer = i+(i+(i+(i+(i+(i + i / removeIndex)/removeIndex)/removeIndex)/removeIndex)/removeIndex)/removeIndex;

		//printf("i is %d, Select %d, Rank %d, Search %d\n",i, answer, i-i/removeIndex, size-i);
        
        if(X.select(i) != answer){				
			selectError++;
			//cout << "i is " << i << " Select error after delete " << X.select(i)  << " should be " <<  answer << " or " << part1Answer << endl;
		}
		if (i%removeIndex) {
			//cout << i << " is i" << endl;
			if(X.rank(i) != i-i/removeIndex){
                rankError++; 
                //cout << "Rank error after delete " << X.rank(i) << " should be " << i << " - " << i-i/removeIndex << endl;
			}
            if(*(X.search(i)) != size-i) searchError++;// cout << "Search error after delete" << endl;
            X.remove(i);
			X.insert(i,size-i);
		}
	}
	printErrors("Rank after delete",rankError);
	printErrors("Select after delete",selectError);
	printErrors("Search after delete",searchError);
	cout << "Finished without failing" << endl << endl;
}

