#include <iostream>
using namespace std;
#include "RBTree.cpp"

int main(){
RBTree<int,int> T;
cout << T.size() << endl;
//should be 0

T.insert(16,8);
T.insert(8,4);
T.insert(12,6);
T.insert(14,7);
T.insert(18,9);
T.insert(2,1);
T.insert(4,2);
T.insert(10,5);
T.insert(6,3);
T.insert(20,10);

T.inorder();
//2 4 6 8 10 12 14 16 18 20
T.preorder();
//12 4 2 8 6 10 16 14 18 20
T.postorder();
//2 6 10 8 4 14 20 18 16 12

RBTree<int,int> X;
X = T;
T = T;

X.remove(6);
cout << T.size() << endl;
//10
cout << X.size() << endl;
//9

X.inorder();
//2 4 8 10 12 14 16 18 20
T.inorder();
//2 4 6 8 10 12 14 16 18 20

if(X.search(24) == nullptr){
	cout << "returned nullptr" << endl;
}
if(X.successor(20) == nullptr){
	cout << "returned nullptr" << endl;
}
if(X.predecessor(2) == nullptr){
	cout << "returned nullptr" << endl;
}
//all these should return the nullptr

cout << X.select(8) << endl;
//18
cout << X.rank(8) << endl;
//3


cout << X.rank(X.select(8)) << endl;
cout << X.select(X.rank(8)) << endl;
//these two are whatever you pass into them, 8

X.remove(16);
cout << X.rank(2) << " " << X.rank(4) << " " << X.rank(8) << " " << X.rank(10) << " " << X.rank(12) << " " << X.rank(14) << " " << X.rank(18) << " " << X.rank(20) << endl;
X.remove(4);
cout << X.rank(2) << " " << X.rank(8) << " " << X.rank(10) << " " << X.rank(12) << " " << X.rank(14) << " " << X.rank(18) << " " << X.rank(20) << endl;
X.remove(12);
cout << X.rank(2) << " " << X.rank(8) << " " << X.rank(10) << " " << X.rank(14) << " " << X.rank(18) << " " << X.rank(20) << endl;
X.remove(2);
cout << X.rank(8) << " " << X.rank(10) << " " << X.rank(14) << " " << X.rank(18) << " " << X.rank(20) << endl;
X.remove(14);
cout << X.rank(8) << " " << X.rank(10) << " " << X.rank(18) << " " << X.rank(20) << endl;
X.remove(10);
cout << X.rank(8) << " " << X.rank(18) << " " << X.rank(20) << endl;
X.remove(18);
cout << X.rank(8) << " " << X.rank(20) << endl;
X.remove(20);
cout << X.rank(8) << endl;
X.remove(8);
//should count down from 1-8 to just 1

cout << X.size() << endl;
//0

X.insert(2,2);
X.insert(4,4);
X.insert(6,6);
X.insert(8,8);
X.insert(10,10);
X.insert(12,12);
X.insert(14,14);
X.insert(16,16);
X.insert(18,18);
X.insert(20,20);
X.insert(22,22);
X.insert(24,24);
X.insert(26,26);
X.insert(28,28);
X.insert(30,30);

X.inorder();
//2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
X.preorder();
//8 4 2 6 16 12 10 14 20 18 24 22 28 26 30
X.postorder();
//2 6 4 10 14 12 18 22 26 30 28 24 20 16 8

T = X;

cout << T.size() << endl;
//15

T.remove(10);
cout << T.select(14) << endl;
T.remove(22);
cout << T.select(13) << endl;
T.remove(30);
cout << T.select(12) << endl;
T.remove(24);
cout << T.select(11) << endl;
T.remove(26);
cout << T.select(10) << endl;
T.remove(28);
cout << T.select(9) << endl;
T.remove(8);
cout << T.select(8) << endl;
T.remove(2);
cout << T.select(7) << endl;
T.remove(16);
cout << T.select(6) << endl;
T.remove(4);
cout << T.select(5) << endl;
T.remove(6);
cout << T.select(4) << endl;
T.remove(20);
cout << T.select(3) << endl;
T.remove(12);
cout << T.select(2) << endl;
T.remove(18);
cout << T.select(1) << endl;
/*
30
30
28
28
28
20
20
20
20
20
20
18
18
14*/

	return 0;
}
