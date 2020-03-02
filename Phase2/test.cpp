#include <iostream>
using namespace std;
#include "RBTree.cpp"

int main(){
    RBTree<string,int> A;
    A.insert("A",10);
    A.insert("B",9);
    A.insert("C",8);
    A.inorder();
    A.preorder();
    return 0;
}