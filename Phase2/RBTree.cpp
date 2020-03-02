#include <iostream>

using namespace std;

enum Color {RED, BLACK};
template <class keytype, class valuetype>
struct Node
{
    keytype key;
    valuetype value;
    Color color;
    Node *left,*right,*parent;
};
template <class keytype, class valuetype>
class RBTree {
private: 
    int length;
    Node<keytype, valuetype> *root;

protected:
    void rotateleft(Node<keytype, valuetype> *& src);
    void rotateright(Node<keytype, valuetype> *& src);
    void preorderBST(Node<keytype, valuetype> *& src);
    void inorderBST(Node<keytype, valuetype> *& src);
    void postorderBST(Node<keytype, valuetype> *& src);
    void deleteNode(Node<keytype, valuetype> *&src);
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
void RBTree<keytype, valuetype> :: rotateleft (Node<keytype, valuetype> *&src) {
    Node<keytype,valuetype> *ppNode = src->parent;
    Node<keytype,valuetype> *subR = src->right;
    Node<keytype,valuetype> *subRL = subR->left;
    src->left = subRL;
    if(subRL) {
        subRL->parent = src;
    }
    subR->left = src;
    src->parent = subR;

    if(ppNode == NULL) {
        subR->parent = NULL;
        root = subR;
    }
    else {
        subR->parent = ppNode;
        if(ppNode->left == src) {
            ppNode->left = subR;
        }
        else if(ppNode->right == src) {
            ppNode->right = src;
        }
    }
    src = subR;

}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: rotateright (Node<keytype, valuetype> *&src) {
    Node<keytype,valuetype> *ppNode = src->parent;
    Node<keytype,valuetype> *subL = src->left;
    Node<keytype,valuetype> *subLR = subL->right;

    src->left = subLR;
    if(subLR) {
        subLR->parent = src;
    }
    subL->right = src;
    src->parent = subL;

    if(ppNode == NULL) {
        subL->parent = NULL;
        root = subL;
    }
    else {
        subL->parent = ppNode;
        if(ppNode->left == src) {
            ppNode->left = subL;
        }
        else if(ppNode->right == src) {
            ppNode->right = subL;
        }
    }
    src = subL;
}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree() {
    root = NULL;
    length = 0;
} 

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree(keytype K[], valuetype V[], int s) {
    for(int i=0;i<s;i++) {
        insert(K[i],V[i]);
    }
}

template<class keytype, class valuetype>
void RBTree<keytype, valuetype> :: deleteNode (Node<keytype, valuetype> *&src) {
    deleteNode(src->left);
    deleteNode(src->right);
    delete src;
}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: ~RBTree() {
    deleteNode(root);
    root = NULL;
    length = 0;
} 

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree(const RBTree &src) {
    length = src.length;
    root = src.root;
}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> &RBTree<keytype, valuetype> :: operator=(const RBTree &src) {
    if(this != &src) {
        length = src.length;
        root = src.root;
    }
    return *this;
}

template <class keytype, class valuetype>
valuetype* RBTree<keytype, valuetype> :: search(keytype k) {
    Node<keytype,valuetype> *ptr = root;
    while(ptr != NULL) {
        if(k == ptr->key) {
            return &ptr->value;
        }
        else if(k > ptr->key) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    return NULL;
}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: insert(keytype k, valuetype v) {
    if(root == NULL) {
        Node<keytype, valuetype> *ptr = new Node<keytype, valuetype>();
        ptr->key = k;
        ptr->value = v;
        root->color = BLACK;
        ptr->left = NULL;
        ptr->right = NULL;
        ptr->parent = NULL;
        root = ptr;
        length++;
        return;
    }

    Node<keytype,valuetype> *cur = root;
    Node<keytype,valuetype> *parent = NULL;
    while (cur) {
        if(cur->key > k) {
            parent = cur;
            cur = cur->left;
            length++;
        }
        else if (cur->key < k){
            parent = cur;
            cur = cur->right;
            length++;
        }
        else {
            return;
        }
    }
    Node<keytype, valuetype> *ptr = new Node<keytype, valuetype>();
    ptr->key = k;
    ptr->value = v;
    ptr->color = RED;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->parent = NULL;
    cur = ptr;
    cur->parent = parent;
    if(parent->key > k) {
        parent -> left = cur;
    }
    else if(parent->key < k) {
        parent->right = cur;
    }

    while (parent && parent->color == RED) {
        Node<keytype, valuetype> *grandfather = parent->parent;
        if(parent == grandfather->left) {
            Node<keytype, valuetype> *uncle = grandfather->right;
            if(uncle && uncle->color == RED) { // Scenario 1
                grandfather->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                cur = grandfather;
                parent = grandfather->parent;
            }
            else if((uncle && uncle->color == BLACK) || uncle == NULL) {
                if(cur == parent->left) { // Scenario 3
                    parent->color = BLACK;
                    grandfather->color = RED;
                    rotateright(grandfather);
                }
                else { // Scenario 2
                    rotateleft(parent);
                    parent->color = BLACK;
                    grandfather->color = RED;
                    rotateright(grandfather);
                }
                break;
            }
        }
        else if (parent == grandfather->right) {
            Node<keytype, valuetype> *uncle = grandfather->left;
            if(uncle && uncle->color == RED) { // Scenario 1
                grandfather->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;

                cur = grandfather;
                parent = cur->parent;
            }
            else if((uncle && uncle->color == BLACK) || uncle == NULL) {
                if(cur == parent->right) { // Scenario 3
                    parent->color = BLACK;
                    grandfather->color = RED;
                    rotateleft(grandfather);
                }
                else if(cur == parent->left) { // Scenario 2
                    rotateright(parent);
                    parent->color = BLACK;
                    grandfather->color = RED;
                    rotateleft(grandfather);
                }
                break;
            }
        }
    }
    root->color = BLACK;

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
keytype* RBTree<keytype, valuetype> :: successor(keytype k) {

}

template <class keytype, class valuetype>
keytype* RBTree<keytype, valuetype> :: predecessor(keytype k) {

}

template <class keytype, class valuetype>
int RBTree<keytype, valuetype> :: size() {
    return length;
}

template <class keytype, class valuetype>
void RBTree<keytype,valuetype> :: preorderBST (Node<keytype,valuetype> *&src) {
    if(src != NULL) {
        cout << src->key << " ";
        preorderBST(src->left);
        preorderBST(src->right);
    }
}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: preorder() {
    if(root == NULL) {
        cout << "The tree is empty.\n";
    }
    else {
        preorderBST(root);
        cout << endl;
    }
}

template <class keytype, class valuetype>
void RBTree<keytype,valuetype> :: inorderBST (Node<keytype,valuetype> *&src) {
    if(src != NULL) {
        inorderBST(src->left);
        cout << src->key << " ";
        inorderBST(src->right);
    }
}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: inorder() {
    if(root == NULL) {
        cout << "The tree is empty.\n";
    }
    else {
        inorderBST(root);
        cout << endl;
    }
}

template <class keytype, class valuetype>
void RBTree<keytype,valuetype> :: postorderBST (Node<keytype,valuetype> *&src) {
    if(src != NULL) {
        postorderBST(src->left);
        postorderBST(src->right);
        cout << src->key << " ";
    }
}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: postorder() {
    if(root == NULL) {
        cout << "The tree is empty.\n";
    }
    else {
        postorderBST(root);
        cout << endl;
    }
}