#include <iostream>
using namespace std;


template <class keytype, class valuetype>
struct Element
{
    keytype key;
    valuetype value;
    int degree;
    Element<keytype,valuetype> *parent, *child, *next;
};

template <class keytype, class valuetype>
class BHeap {
private:
    Element<keytype,valuetype> *mroot;
    bool combined;
    keytype deletekey;

protected:
    void link(Element<keytype,valuetype> *child, Element<keytype,valuetype> *root);
    Element<keytype,valuetype>* combine(Element<keytype,valuetype>* h1, Element<keytype,valuetype>* h2);
    Element<keytype,valuetype>* merge(Element<keytype,valuetype>* h1, Element<keytype,valuetype>* h2);
    void minimum(Element<keytype,valuetype> *root, Element<keytype,valuetype> *&pre, Element<keytype,valuetype> *&y);
    Element<keytype,valuetype>* reverse(Element<keytype,valuetype> *root);
    void printElement(Element<keytype,valuetype> *src);
    void deleteElement(Element<keytype,valuetype> *src);
    Element<keytype,valuetype>* copyNode(Element<keytype,valuetype> *src,Element<keytype,valuetype> *dest,Element<keytype,valuetype> *parent);

public:
    BHeap();
    BHeap(keytype K[],valuetype V[],int s);
    ~BHeap();
    BHeap(const BHeap &src);
    BHeap& operator=(const BHeap &src);
    keytype peekKey();
    valuetype peekValue();
    keytype extractMin();
    void insert(keytype k, valuetype v);
    void merge(BHeap<keytype,valuetype> &H2);
    void printKey();

};

template <class keytype, class valuetype>
BHeap<keytype,valuetype> :: BHeap() {
    mroot = NULL;
    combined = false;
}   

template <class keytype, class valuetype>
BHeap<keytype, valuetype> :: BHeap(keytype K[],valuetype V[],int s) {
    mroot = NULL;
    combined = false;
    for(int i=0;i<s;i++) {
        //cout << i << endl;
        insert(K[i],V[i]);
    }
}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: deleteElement(Element<keytype,valuetype> *src) {
    if(src == NULL) {
        return;
    }
    deleteElement(src->child);
    deleteElement(src->next);
    delete src;
}

template <class keytype, class valuetype>
BHeap<keytype, valuetype> :: ~BHeap() {
    if(!combined) {
        deleteElement(mroot);
    }
}

template <class keytype, class valuetype>
Element<keytype,valuetype>* BHeap<keytype, valuetype> :: copyNode(Element<keytype,valuetype> *src,Element<keytype,valuetype> *dest, Element<keytype,valuetype> *parent) {
    if(src == NULL) {
        return NULL;
    }
    dest = new Element<keytype,valuetype>;
    dest->value = src->value;
    dest->degree = src->degree;
    dest->key = src->key;
    dest->parent = parent;
    dest->child = copyNode(src->child,dest->child,dest);
    dest->next = copyNode(src->next,dest->next,parent);
    return dest;
    
}

template <class keytype, class valuetype>
BHeap<keytype, valuetype> :: BHeap(const BHeap &src) {
    deletekey = src.deletekey;
    mroot = copyNode(src.mroot,mroot,NULL);
}

template <class keytype, class valuetype>
BHeap<keytype, valuetype> &BHeap<keytype,valuetype> :: operator=(const BHeap &src) {
    if(this != &src) {
        deletekey = src.deletekey; 
        mroot = copyNode(src.mroot,mroot,NULL);
    }
    return *this;
}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: link(Element<keytype,valuetype> *child, Element<keytype,valuetype> *root) {
    child->parent = root;
    child->next = root->child;
    root->child = child;
    root->degree++;
}

template <class keytype, class valuetype>
Element<keytype,valuetype>* BHeap<keytype, valuetype> :: merge(Element<keytype,valuetype>* h1, Element<keytype,valuetype>* h2) {
    Element<keytype,valuetype>* root;
    Element<keytype,valuetype>** position = &root;

    while(h1 && h2) {
        if(h1->degree < h2->degree) {
            *position = h1;
            h1 = h1->next;
        }
        else {
            *position = h2;
            h2 = h2->next;
        }
        position = & (*position)->next;
    }
    if(h1) {
        *position = h1;
    }
    else {
        *position = h2;
    }
    return root;
}

template <class keytype, class valuetype>
Element<keytype,valuetype>* BHeap<keytype, valuetype> :: combine(Element<keytype,valuetype>* h1, Element<keytype,valuetype>* h2) {
    Element<keytype,valuetype> *root;
    Element<keytype,valuetype> *x, *pre, *post;
    root = merge(h1,h2);
    if(root == NULL) {
        return NULL;
    }

    pre = NULL;
    x = root;
    post = x->next;

    while(post != NULL) {
        if((x->degree!=post->degree) || ((post->next != NULL) && (post->degree == post->next->degree))) {
            pre = x;
            x = post;
        }
        else if(x->key <= post->key) {
            x->next = post->next;
            link(post,x);
        }
        else {
            if(pre == NULL) {
                root = post;
            }
            else {
                pre->next = post;
            }
            link(x,post);
            x = post;
        }
        post = x->next;
    }
    return root;
}

template <class keytype, class valuetype>
Element<keytype,valuetype>* BHeap<keytype, valuetype> :: reverse(Element<keytype,valuetype> *root) {
    Element<keytype,valuetype> *next;
    Element<keytype,valuetype> *tail = NULL;

    if(!root) {
        return root;
    }

    root->parent = NULL;
    while(root->next) {
        next = root->next;
        root->next = tail;
        tail = root;
        root = next;
        root->parent = NULL;
    }
    root->next = tail;
    return root;
}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: minimum (Element<keytype,valuetype> *root, Element<keytype,valuetype> *&pre, Element<keytype,valuetype> *&y) {
    Element<keytype,valuetype> *x,*ptr;
    if(root == NULL) {
        return;
    }
    ptr = root->next;
    x = root;
    pre = NULL;
    y = root;
    while(ptr != NULL) {
        if(ptr->key < y->key) {
            y = ptr;
            pre = x;
        }
        ptr = ptr->next;
        x = x->next;
    }
}

template <class keytype, class valuetype>
keytype BHeap<keytype, valuetype> :: peekKey() {
    Element<keytype,valuetype> *ptr,*pre;
    minimum(mroot,pre,ptr);
    return ptr->key;
}

template <class keytype, class valuetype>
valuetype BHeap<keytype, valuetype> ::peekValue() {
    Element<keytype,valuetype> *ptr,*pre;
    minimum(mroot,pre,ptr);
    return ptr->value;
}

template <class keytype, class valuetype>
keytype BHeap<keytype, valuetype> :: extractMin() {
    Element<keytype,valuetype> *y,*pre;
    if(mroot == NULL) {
        exit(0);
    }

    minimum(mroot,pre,y);
    deletekey = y->key;
    if(pre == NULL) {
        mroot = mroot->next;
    }
    else {
        pre->next = y->next;
    }
    Element<keytype,valuetype> *child = reverse(y->child);
    mroot = combine(mroot,child);
    delete y;
    return deletekey;
}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: insert(keytype k, valuetype v) {
    if(mroot == NULL) {
        mroot = new Element<keytype,valuetype>;
        mroot->key = k;
        mroot->value = v;
        mroot->parent = NULL;
        mroot->child = NULL;
        mroot->next = NULL;
        return;
    }

    Element<keytype,valuetype> *node;
    node = new Element<keytype,valuetype>;
    node->key = k;
    node->value = v;
    node->degree = 0;
    node->child = NULL;
    node->parent = NULL;
    node->next = NULL;
    
    if(node == NULL) {
        return;
    }
    mroot = combine(mroot,node);
    
}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: merge(BHeap<keytype,valuetype> &H2) {
    H2.combined = true;
    mroot = combine(mroot,H2.mroot);
}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: printElement(Element<keytype,valuetype> *src) {
    if(src == NULL) {
        return;
    }
    cout << src->key << " ";
    printElement(src->child);
    printElement(src->next);

}

template <class keytype, class valuetype>
void BHeap<keytype, valuetype> :: printKey() {
    Element<keytype,valuetype> *ptr = mroot;
    while(ptr!=NULL) {
        cout << "B" << ptr->degree << endl;
        cout << ptr->key << " ";
        printElement(ptr->child);
        cout << endl << endl;
        ptr = ptr->next;
    }

}