#include <iostream>

using namespace std;

enum Color {RED, BLACK};
template <class keytype, class valuetype>
struct Node
{
    keytype key;
    valuetype value;
    Color color;
    int numNode;
    Node<keytype,valuetype> *left,*right,*parent;
};
template <class keytype, class valuetype>
class RBTree {
private: 
    int length;
    Node<keytype, valuetype> *root;
    Node<keytype,valuetype> *DBNode;
    bool counted;


protected:
    void rotateleft(Node<keytype, valuetype> *&src);
    void rotateright(Node<keytype, valuetype> *& src);
    void preorderBST(Node<keytype, valuetype> *& src);
    void inorderBST(Node<keytype, valuetype> *& src);
    void postorderBST(Node<keytype, valuetype> *& src);
    void deleteNode(Node<keytype, valuetype> *src);
    void removeFixup(Node<keytype, valuetype> *node);
    int countNode(Node<keytype,valuetype> *src);
    void countTree(Node<keytype,valuetype> *src);
    void copyNode(Node<keytype,valuetype> *a,Node<keytype,valuetype> *b);
    Node<keytype,valuetype> *minimum(Node<keytype,valuetype> *src);
    Node<keytype,valuetype> *maximum(Node<keytype,valuetype> *src);
    Node<keytype,valuetype> *findNode(keytype key);
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


//issure
template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: rotateleft (Node<keytype, valuetype> *&src) {
    //cout << "Rotate Left\n";
    Node<keytype,valuetype> *ppNode = src->parent;
    Node<keytype,valuetype> *subR = src->right;
    Node<keytype,valuetype> *subL = src->left;
    Node<keytype,valuetype> *subRL = subR->left;
    src->right = subRL;
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
            ppNode->right = subR;
        }
    }
    src = subR;
    if(subRL) {
        subRL->parent = subR->left;
    }
    if(subL) {
        subL->parent = subR->left;
    }
    
}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: rotateright (Node<keytype, valuetype> *&src) {
    //cout << "Rotate Right\n";
    Node<keytype,valuetype> *ppNode = src->parent;
    Node<keytype,valuetype> *subL = src->left;
    Node<keytype,valuetype> *subR = src->right;
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
    if(subLR) {
        subLR->parent = subL->right;
    }
    if(subR) {
        subR->parent = subL->right;
    }
}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree() {
    root = NULL;
    length = 0;
    DBNode = new Node<keytype,valuetype>;
    DBNode->color = BLACK;
    DBNode->left = NULL;
    DBNode->right = NULL;
    counted = false;
} 

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree(keytype K[], valuetype V[], int s) {
    this->root = NULL;
    this->length = 0;
    DBNode = new Node<keytype,valuetype>;
    DBNode->color = BLACK;
    DBNode->left = NULL;
    DBNode->right = NULL;
    counted = false;
    for(int i=0;i<s;i++) {
        insert(K[i],V[i]);
    }

}

template<class keytype, class valuetype>
void RBTree<keytype, valuetype> :: deleteNode (Node<keytype, valuetype> *src) {
    if(src == NULL) {
        return;
    }
    else {
        deleteNode(src->left);
        deleteNode(src->right);
        delete src;
    }
    
}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: ~RBTree() {

    if(root != NULL) {
        deleteNode(root);
    }
    root = NULL;
    length = 0;
    delete DBNode;
} 

template <class keytype, class valuetype>
void RBTree<keytype,valuetype> :: copyNode(Node<keytype,valuetype> *a,Node<keytype,valuetype> *b) {

    
    if(a->left != NULL) {
        Node<keytype,valuetype> *left = new Node<keytype,valuetype>; 
        //cout << "1\n";
        left->value = a->left->value;
        left->key = a->left->key;
        left->color = a->left->color;
        //left->left = NULL;
        //left->right = NULL;
        b->left = left;
        //cout << b->value << " left is " << left->value << endl; 
        left->parent = b;
        copyNode(a->left,b->left);
    }
    else {
        b->left = NULL;
    }
    if(a->right != NULL) {
        Node<keytype,valuetype> *right = new Node<keytype,valuetype>;
        //cout << "1\n";
        right->value = a->right->value;
        right->key = a->right->key;
        right->color = a->right->color;
        //right->left = NULL;
        //right->right = NULL;
        b->right = right;
        //cout << b->value << " right is" << right->value << endl; 
        right->parent = b;
        copyNode(a->right,b->right);
    }
    else {
        b->right = NULL;
    }
    //inorderBST(root);
    //cout << endl;
    return;
    
}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> :: RBTree(const RBTree &src) {
    length = src.length;

    if(src.root == NULL) {
        this->root = NULL;
    }
    else {
        this->root = new Node<keytype,valuetype>();
        this->root->value = src.root->value;
        this->root->key = src.root->key;
        this->root->color = src.root->color;
        copyNode(src.root,root);
        countTree(root);
        counted=true;
    }
    
    
}

template <class keytype, class valuetype>
RBTree<keytype, valuetype> &RBTree<keytype, valuetype> :: operator=(const RBTree &src) {
    if(this != &src) {
        length = src.length;
        if(src.root == NULL) {
            this->root = NULL;
        }
        else {
            this->root = new Node<keytype,valuetype>();
            this->root->value = src.root->value;
            this->root->key = src.root->key;
            this->root->color = src.root->color;
            copyNode(src.root,root);
            countTree(root);
            counted = true;
        }
        
    }
    return *this;
}

template <class keytype, class valuetype>
valuetype* RBTree<keytype, valuetype> :: search(keytype k) {
    Node<keytype,valuetype> *ptr = root;
    while(ptr != NULL) {
        //cout << ptr->key << endl;
        if(k == ptr->key) {
            return &ptr->value;
        }
        else if(k > ptr->key) {
            if(ptr->right == NULL) {
                return NULL;
            }
            else {
                ptr = ptr->right;
            }
        }
        else {
            if(ptr->left == NULL) {
                return NULL;
            }
            else {
                ptr = ptr->left;
            }
        }
    }
    return NULL;
}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: countTree(Node<keytype,valuetype> *src) {
    if(src!=NULL) {
        src->numNode = countNode(src);
        countTree(src->left);
        countTree(src->right);
    }
}

template <class keytype, class valuetype>
void RBTree<keytype, valuetype> :: insert(keytype k, valuetype v) {
    counted = false;
    if(root == NULL) {
        root = new Node<keytype, valuetype>();
        root->key = k;
        root->value = v;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        root->numNode = 1;
        root->color = BLACK;
        length++;
        return;
    }

    Node<keytype,valuetype> *cur = root;
    Node<keytype,valuetype> *parent = NULL;
    while (cur) {
        if(cur->key > k) {
            parent = cur;
            cur = cur->left;
        }
        else if (cur->key < k){
            parent = cur;
            cur = cur->right;
        }
        else {
            return;
        }
    }
    length++;
    Node<keytype, valuetype> *ptr = new Node<keytype, valuetype>();
    ptr->key = k;
    ptr->value = v;
    ptr->color = RED;
    //ptr->numNode = 0;
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
                else { // Scenario 2
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

template <class keytype,class valuetype>
void RBTree<keytype, valuetype> :: removeFixup (Node<keytype,valuetype> *node) {
    Node<keytype,valuetype> *brother;
    while((node!=root) && (node->color == BLACK)) {
        if(node == node->parent->left) {
            brother = node->parent->right;
            //case3
            if(brother->color == RED) {
                node->parent->color = RED;
                brother->color = BLACK;
                rotateleft(node->parent);
                break;
            }
            else {
                if(brother->left==NULL && brother->right==NULL) {
                    brother->color = RED;
                    node = node->parent;
                }
                else {
                    if(brother->right!=NULL && brother->right->color==RED) {
                        brother->color = node->parent->color;
                        node->parent->color = BLACK;
                        if(brother->right) {
                            brother->right->color = BLACK;
                        }
                        rotateleft(node->parent);
                        break;
                    }
                    else if(brother->left!=NULL && brother->left->color==RED){
                        brother->left->color = BLACK;
                        brother->color = RED;
                        rotateright(brother);
                    }
                    else {
                       brother->color = RED;
                       node->parent->color = BLACK; 
                    }
                }
            }
         }
        else {
            brother = node->parent->left;
            if(brother->color == RED) {
                node->parent->color = RED;
                brother->color = BLACK;
                if(brother->right) {
                    brother->right->color = RED;
                }
                rotateright(node->parent);
                break;
            }
            else {
                if(brother->left==NULL && brother->right==NULL) {
                    brother->color = RED;
                    node = node->parent;
                }
                else {
                    if(brother->left!=NULL && brother->left->color == RED) {
                        brother->color = node->parent->color;
                        node->parent->color = BLACK;
                        brother->left->color = BLACK;
                        rotateright(node->parent);
                        break;
                    }
                    else if(brother->right!=NULL && brother->right->color == RED){
                        brother->right->color = BLACK;
                        brother->color = RED;
                        rotateleft(brother);
                    }
                    else {
                        brother->color = RED;
                        node = node->parent;
                    }
                }
            }
            
        }
    }
    node->color = BLACK;
}

template <class keytype, class valuetype>
int RBTree<keytype, valuetype> :: remove(keytype k) {
    Node<keytype, valuetype> *ptr = root;
    while(ptr!= NULL) {
        if(ptr->key == k) {
            break;
        }
        else if(ptr->key < k) {
            ptr = ptr->right;
        }
        else {
            ptr = ptr->left;
        }
    }
    if(ptr == NULL) {
        return 0;
    }
    counted = false;
    if(ptr->left != NULL && ptr->right != NULL) { //has two child
        Node<keytype,valuetype> *replace = ptr;
        replace = minimum(replace->right);
        keytype tmkey = ptr->key;
        valuetype tmvalue = ptr->value;
        ptr->key = replace->key;
        ptr->value = replace->value;
        replace->key = tmkey;
        replace->value = tmvalue;
        ptr = replace;
    }
    Node<keytype,valuetype> *ptr_child;
    if(ptr->color == RED) {
        if(ptr == ptr->parent->left) {
            ptr->parent->left = NULL;
        }
        else {
            ptr->parent->right = NULL;
        }
    }
    else if(ptr->right != NULL) {
        if(ptr == root) {
            root = ptr->right;
            ptr->right->parent = NULL;
            ptr->right->color = BLACK;
            delete ptr;
        }
        else {
            if(ptr == ptr->parent->left) {
                ptr->parent->left = ptr->right;
                ptr->right->parent = ptr->parent;
            }
            else {
                ptr->parent->right = ptr->right;
                ptr->right->parent = ptr->parent;
            }
            ptr->right->color = BLACK;
            delete ptr;
        }
    }
    else if(ptr->left != NULL) {
        if(ptr == root) {
            root = ptr->left;
            ptr->left->parent = NULL;
            ptr->left->color = BLACK;
            delete ptr;
        }
        else {
            if(ptr == ptr->parent->left) {
                ptr->parent->left = ptr->left;
                ptr->left->parent = ptr->parent;
            }
            else {
                ptr->parent->right = ptr->left;
                ptr->left->parent = ptr->parent;
            }
            ptr->left->color = BLACK;
            delete ptr;
        }
    }
    else { // leaf
        if(ptr->parent == NULL) {
            root = NULL;
            delete ptr;
        }
        else {
            Node<keytype,valuetype> *temp = ptr->parent;
            if(ptr == ptr->parent->left) {
                delete ptr;
                temp->left = DBNode;
                DBNode->parent = temp;
                removeFixup(DBNode);
                temp->left = NULL;
            }
            else {
                delete ptr;
                temp->right = DBNode;
                DBNode->parent = temp;
                removeFixup(DBNode);
                temp->right = NULL;
            }
        }
    }
    length--;
    return 1;

}

template <class keytype,class valuetype>
int RBTree<keytype,valuetype> :: countNode(Node<keytype, valuetype> *src) {
    if(src == NULL) {
        return 0;
    }
    return countNode(src->left) + countNode(src->right) + 1;
}

template <class keytype, class valuetype>
int RBTree<keytype, valuetype> :: rank(keytype k) {
    if(counted == false) {
        countTree(root);
        counted = true;
    }
    int rank = 0;
    Node<keytype, valuetype> *ptr = root;
    while(ptr) {
        //cout << ptr->key << endl;
        if(k < ptr->key) {
            ptr = ptr->left;
        }
        else if (k > ptr->key) {
            if(ptr->left != NULL) {
                rank = rank + 1 + ptr->left->numNode;
                ptr = ptr->right;
            }
            else {
                rank = rank + 1;
                ptr = ptr->right;
            }
        }
        else {
            if(ptr->left != NULL) {
                return rank + 1 + ptr->left->numNode;
            }
            else {
                return rank + 1;
            }
        }
    }
    return 0;
}

template <class keytype, class valuetype>
keytype RBTree<keytype, valuetype> :: select(int pos) {
    if(counted == false) {
        countTree(root);
        counted = true;
    }
    Node<keytype, valuetype> *ptr = root;
    int count;
    if(ptr->left != NULL) {
        count = ptr->left->numNode;
    }
    else {
        count = 0;
    }
    
    if(count + 1 == pos) {
        return ptr->key;
    }
    while(count + 1 != pos) {
        if(pos <= count) {
            ptr = ptr->left;
            if(ptr->left != NULL) {
                count = ptr->left->numNode;
            }
            else {
                count = 0;
            }
        }
        else {
            pos = pos - 1 - count;
            ptr = ptr->right;
            if(ptr->left != NULL) {
                count = ptr->left->numNode;
            }
            else {
                count = 0;
            }
        }
    }
    return ptr->key;


}

template <class keytype, class valuetype>
Node<keytype,valuetype>* RBTree<keytype,valuetype> ::minimum(Node<keytype,valuetype> *src) {
    if(src == NULL) {
        return src;
    }
    while(src->left != NULL) {
        src = src->left;
    }
    return src;
}

template <class keytype, class valuetype>
Node<keytype,valuetype>* RBTree<keytype,valuetype> ::maximum(Node<keytype,valuetype> *src) {
    if(src == NULL) {
        return src;
    }
    while(src->right != NULL) {
        src = src->right;
    }
    return src;
}

template <class keytype, class valuetype>
Node<keytype,valuetype>* RBTree<keytype,valuetype> ::findNode(keytype key) {
    Node<keytype,valuetype> *ptr = root;
    while(ptr != NULL) {
        if(ptr->key == key) {
            return ptr;
        }
        else if(key > ptr->key) {
            ptr = ptr->right;
        }
        else {
            ptr = ptr->left;
        }
    }
    return NULL;
}

template <class keytype, class valuetype>
keytype* RBTree<keytype, valuetype> :: successor(keytype k) {
    //find node
    Node<keytype,valuetype> *ptr = findNode(k);
    if(ptr == NULL) {
        return NULL;
    }
    
    if(ptr->right != NULL) {
        return &minimum(ptr->right)->key;
    }

    Node<keytype,valuetype> *parent = ptr->parent;
    while((parent!=NULL) && (ptr == parent->right)) {
        ptr = parent;
        parent = parent->parent;
    }
    return &parent->key;
    
}

template <class keytype, class valuetype>
keytype* RBTree<keytype, valuetype> :: predecessor(keytype k) {
    //find node
    Node<keytype,valuetype> *ptr = findNode(k);
    if(ptr == NULL) {
        return NULL;
    }

    if(ptr->left != NULL) {
        return &maximum(ptr->left)->key;
    }

    Node<keytype,valuetype> *parent = ptr->parent;
    while((parent!=NULL) && (ptr == parent->left)) {
        ptr = parent;
        parent = parent->parent;
    }
    return &parent->key;
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
