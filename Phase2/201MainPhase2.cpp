#include <iostream>
#include <ctime>
using namespace std;
#include "RBTree.cpp"
#include <stdlib.h>
#include <iomanip>

void counttime(time_t start, time_t end) {
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
}

int main(){
	time_t start, end;
	start = clock();
	string K[10] = {"A","B","C","D","E","F","G","H","I","K"};
	int V[10] = {10,9,8,7,6,5,4,3,2,1};
	
	RBTree<string,int> T1, T2(K,V,10);
	
	for(int i=0; i<10; i++) T1.insert(K[i],V[i]);
	
	// T1 and T2 should be identical trees
	
	cout << *(T2.search("C")) << endl;
	// Should output 8
	
	cout << T1.rank("C") << endl;
	//Should output 3
	
	cout << T1.select(3) << endl;
	//Should output C 
	
	T2.preorder();
	//Should output D B A C F E H G I K
	
	T2.inorder();

	//RBTree<string, int> T3;
	//T3 = T2;
	//T3.preorder();
	//T3.inorder();
	//Should output	A B C D E F G H I K
	
	cout << T2.remove("D") << endl;
	//Should output 1
	
	T2.preorder();
	//Should output E B A C H F G I K
	
	T2.inorder();
	//Should output	A B C E F G H I K
	
	cout << T2.remove("j") << endl;
	//Should output 0
	
	cout <<T2.rank("G") << endl;
	//Should output 6
	
	cout <<*(T1.successor("C"))<<endl;
	//Should output D
	
	cout <<*(T1.predecessor("C"))<<endl;
	//Should output B		

	
    RBTree<int,int> X;
	for (int i=1;i<100000;i++) {
		//cout << i << endl;
		X.insert(i,i);
	}
	//cout << X.size() << endl;
	for (int i=1;i<100000;i++) {
		//cout << i << endl;
		if(X.rank(i) != i) cout << "Rank error" << endl;
		if(X.select(i) != i) cout << "Select error" << endl;
		if(*(X.search(i)) != i) cout << "Search error" << endl;
	}
	end = clock();
	counttime(start,end);
	//Should be no output and should take seconds, not minutes
	return 0;
}
