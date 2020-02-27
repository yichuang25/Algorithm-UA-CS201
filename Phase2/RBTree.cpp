#include <iostream>

using namespace std;

template <class keytype, class valuetype>
struct Node
{
    keytype key;
    valuetype value;
    int color;
    Node *left,*right,*parent;
};
template <class keytype, class valuetype>
class RBTree {
private: 
    int length;
    Node<keytype, valuetype> *root;

protected:
    void rotateleft(Node<keytype, valuetype> *src);
    void rotateright(Node<keytype, valuetype> *src);
    void fixinsert(Node<keytype, valuetype> *src);
    void fixdelete(Node<keytype, valuetype> *src);
    void inorder(Node<keytype, valuetype> *src);
    void preorder(Node<keytype, valuetype> *src);
    int getcolor(Node<keytype, valuetype> *src);
    void setcolor(Node<keytype, valuetype> *src);
    void deletetree(Node<keytype, valuetype> *src);

public: 
    RBTree();
    RBTree(keytype k[], valuetype V[], int s);
    ~RBTree();
    RBTree(const RBTree &src);
    RBTree& operator=(const RBTree &src);
    valuetype *search(keytype k);
    void insert(keytype k, valuetype v);
    int remove(keytype k);
    int rank(keytype k);
    keytype select(int pos);
    keytype *successor(keytype k);
    keytype *predecessor(keytype k);
    int size();
    void preorder();
    void inorder();
    void postorder();
};

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree() {
    root = nullptr;
    length = 0;
} 

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree(keytype k[], valuetype V[], int s) {

}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: ~RBTree() {

    
} 

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree(const RBTree &src) {

}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> &RBTree<keytype, valuetype> :: operator=(const RBTree &src) {

}

template <class keytype, class valuetype>
keytype RBTree<keytype, valuetype> :: *search(keytype k) {

}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: insert(keytype k, valuetype v) {

}

template <class keytype, class valuetype>
int RBTree<keytype, valuetype> :: remove(keytype k) {

}

template <class keytype, class valuetype>
int RBTree<keytype, valuetype> :: rank(keytype k) {

}

template <class keytype, class valuetype>
keytype RBTree<keytype, valuetype> :: select(int pos) {

}

template <class keytype, class valuetype>
keytype RBTree<keytype, valuetype> :: *successor(keytype k) {

}

template <class keytype, class valuetype>
keytype RBTree<keytype, valuetype> :: *predecessor(keytype k) {

}

template <class keytype, class valuetype>
int RBTree<keytype, valuetype> :: size() {

}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: preorder() {

}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: inorder() {

}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: postorder() {

}