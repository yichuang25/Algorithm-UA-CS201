#include <iostream>
using namespace std;
#include "RBTree.cpp"

int main(){
    RBTree<int,int> A;
    for(int i=1;i<=10;i++) {
        A.insert(i,i);
    }
    A.inorder();
    A.preorder();

    RBTree<int,int> B;
    B = A;
    cout << endl;
    //cout << "2\n";
    B.inorder();
    //cout << "3\n";
    B.preorder();
    for(int i=1;i<=10;i++) {
        B.remove(i);
        B.inorder();
        B.preorder();
    }
    return 0;
}