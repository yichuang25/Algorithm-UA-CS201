#include <iostream>
using namespace std;


template <class keytype, class valuetype>
struct Node
{
    keytype key;
    valuetype value;
};

template <class keytype, class valuetype>
class Heap {
private:
    Node<keytype,valuetype> *head;
    int length;
    int capacity;

protected:
    void printNode(int num);
    void Heapify(int position);

public:
    Heap();
    Heap(keytype K[],valuetype V[],int s);
    ~Heap();
    Heap(const Heap &src);
    Heap& operator=(const Heap &src);
    keytype peekKey();
    valuetype peekValue();
    keytype extractMin();
    void insert(keytype k, valuetype v);
    void printKey();
    void printArray();
};

template <class keytype, class valuetype>
Heap<keytype,valuetype> :: Heap() {
    capacity = 2;
    length = 0;
    head = new Node<keytype,valuetype>[capacity];
}

template <class keytype, class valuetype>
void Heap<keytype, valuetype> :: Heapify (int position) {
    if(position*2 > length && position*2+1 > length) { //leaf;
        return;
    }
    if(position*2+1 > length) { // single child
        if(head[position].key > head[position*2].key) {
            Node<keytype,valuetype> temp;
            temp.value = head[position*2].value;
            temp.key = head[position*2].key;

            head[position*2].value = head[position].value;
            head[position*2].key = head[position].key;

            head[position].value = temp.value;
            head[position].key = temp.key;

            return;
        }
    }
    else { // two child
        if(head[position].key > head[position*2].key || head[position].key > head[position*2+1].key) {
            if(head[position*2].key < head[position*2+1].key) {
                Node<keytype,valuetype> temp;
                temp.value = head[position*2].value;
                temp.key = head[position*2].key;

                head[position*2].value = head[position].value;
                head[position*2].key = head[position].key;

                head[position].value = temp.value;
                head[position].key = temp.key;

                Heapify(position*2);
            }
            else {
                Node<keytype,valuetype> temp;
                temp.value = head[position*2+1].value;
                temp.key = head[position*2+1].key;

                head[position*2+1].value = head[position].value;
                head[position*2+1].key = head[position].key;

                head[position].value = temp.value;
                head[position].key = temp.key;

                Heapify(position*2+1);
            }
        }
        else {
            return;
        }

    }
}

template <class keytype, class valuetype>
Heap<keytype, valuetype> :: Heap(keytype K[],valuetype V[],int s) {
    capacity = s+2;
    length = s;
    head = new Node<keytype,valuetype>[capacity];
    for(int i=1;i<=s;i++) {
        head[i].value = V[i-1];
        head[i].key = K[i-1];
    }

    for(int i=s;i>0;i--) {
        Heapify(i);
    }
}

template <class keytype, class valuetype>
Heap<keytype, valuetype> :: ~Heap() {
    delete[] head;
    capacity = 2;
    length = 0;
}

template <class keytype, class valuetype>
Heap<keytype, valuetype> :: Heap(const Heap &src) {
    capacity = src.capacity;
    length = src.length;
    head = new Node<keytype,valuetype>[capacity];
    for(int i=1;i<=length;i++) {
        head[i].key = src.head[i].key;
        head[i].value = src.head[i].value;
    }
}

template <class keytype, class valuetype>
Heap<keytype, valuetype>& Heap<keytype,valuetype> :: operator=(const Heap &src) {
    if(this != &src) {
        capacity = src.capacity;
        length = src.length;
        head = new Node<keytype,valuetype>[capacity];
        for(int i=1;i<=length;i++) {
            head[i].key = src.head[i].key;
            head[i].value = src.head[i].value;
        }
    }
    return *this;
}

template <class keytype, class valuetype>
keytype Heap<keytype, valuetype> :: peekKey() {
    return head[1].key;
    
}

template <class keytype, class valuetype>
valuetype Heap<keytype, valuetype> ::peekValue() {
return head[1].value;
    
}


template <class keytype, class valuetype>
keytype Heap<keytype, valuetype> :: extractMin() {
    keytype key = head[1].key;
    head[1].key = head[length].key;
    head[1].value =  head[length].value;
    length--;
    int num = 1;
    while((2*num<=length && head[num*2].key < head[num].key) || (2*num+1<=length && head[num*2+1].key < head[num].key)) {
        if(2*num<=length && head[num*2].key < head[num].key) { // left
            if(num*2+1 <= length && head[num*2+1].key < head[num*2].key) {
                Node<keytype,valuetype> temp;
                temp.value = head[num*2+1].value;
                temp.key = head[num*2+1].key;

                head[num*2+1].value = head[num].value;
                head[num*2+1].key = head[num].key;

                head[num].value = temp.value;
                head[num].key = temp.key;
                num = num*2+1;
            }
            else {
                Node<keytype,valuetype> temp;
                temp.value = head[num*2].value;
                temp.key = head[num*2].key;

                head[num*2].value = head[num].value;
                head[num*2].key = head[num].key;

                head[num].value = temp.value;
                head[num].key = temp.key;
                num = num*2;
            }
            
        }
        else if(2*num+1<=length && head[num*2+1].key < head[num].key){ //right
            Node<keytype,valuetype> temp;
            temp.value = head[num*2+1].value;
            temp.key = head[num*2+1].key;

            head[num*2+1].value = head[num].value;
            head[num*2+1].key = head[num].key;

            head[num].value = temp.value;
            head[num].key = temp.key;
            num = num*2+1;
        }
        else {
            break;
        }
    }
    if(length <= capacity * 0.25) {
        capacity = capacity/2;
        Node<keytype,valuetype> *temp = new Node<keytype,valuetype> [capacity];
        for(int i=1;i<=length;i++) {
            temp[i].value = head[i].value;
            temp[i].key = head[i].key;
        }
        delete [] head;
        head = new Node<keytype, valuetype> [capacity];
        for(int i=1;i<=length;i++) {
            head[i].value = temp[i].value;
            head[i].key = temp[i].key;
        }
        delete [] temp;
    }

    return key;
}

template <class keytype, class valuetype>
void Heap<keytype, valuetype> :: insert(keytype k, valuetype v) {
    //printArray();
    if(length+1 == capacity) {
        capacity = 2 * capacity;
        Node<keytype,valuetype> *temp = new Node<keytype,valuetype> [capacity];
        for(int i=1;i<=length;i++) {
            temp[i].value = head[i].value;
            temp[i].key = head[i].key;
        }
        delete [] head;
        head = new Node<keytype, valuetype> [capacity];
        for(int i=1;i<=length;i++) {
            head[i].value = temp[i].value;
            head[i].key = temp[i].key;
        }
        delete [] temp;
    }

    if(length == 0) {
        head[1].key = k;
        head[1].value = v;
        length++;
    }
    else {
        length++;
        head[length].value = v;
        head[length].key = k;
        //fix
        int num = length;
        while(num!=0) {
            int parent = num/2;
            if(head[parent].key > head[num].key) {

                Node<keytype,valuetype> temp;
                temp.value = head[parent].value;
                temp.key = head[parent].key;

                head[parent].value = head[num].value;
                head[parent].key = head[num].key;

                head[num].value = temp.value;
                head[num].key = temp.key;

            } 
            num = num/2;
        }
    }
}

template <class keytype, class valuetype>
void Heap<keytype, valuetype> :: printNode (int num) {
    cout << head[num].key << " ";
    if(num*2 <= length) {
        printNode(num*2);
    }

    if(num*2+1 <= length) {
        printNode(num*2+1);
    }
    return;
}

template <class keytype, class valuetype>
void Heap<keytype, valuetype> :: printArray () {
    for(int i=1;i<=length;i++) {
        cout << head[i].key << " ";
    }
    cout << endl;
}

template <class keytype, class valuetype>
void Heap<keytype, valuetype> :: printKey() {
    printArray();
    return;

}