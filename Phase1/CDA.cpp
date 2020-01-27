#include <iostream>
using namespace std;


template <class elmtype>
class CDA {

private:
    int front;
    int end;
    int capacity;
    int length;
    bool order;
    elmtype *array;

public:
    CDA();
    CDA(int s);
    ~CDA();
    CDA(const CDA &cda);
    CDA& operator=(const CDA &src);
    elmtype& operator[](int i);
    void Printarray();
    void AddEnd(elmtype v);
    void AddFront(elmtype v);
    void DelEnd();
    void DelFront();
    int Length();
    int Capacity();
    int Clear();
    bool Ordered();
    int SetOrdered();
    void QuickSort();
    elmtype Select(int k);
    void InsertionSort();
    void CountingSort(int m);
    int Search(elmtype e);
};

template <class elmtype>
CDA<elmtype> :: CDA(){
    capacity = 1;
    length = 0;
    array = new elmtype[capacity];
    front = 0;
    end = 0;
    order = false;
}

template <class elmtype>
CDA<elmtype> :: CDA(int s) {
    capacity = s;
    length = 0;
    array = new elmtype[capacity];
    front = end = 0;
    order = false;
}

template <class elmtype>
CDA<elmtype> :: ~CDA() {
     delete array;
     capacity = 0;
     front = 0;
     end = 0;
     length = 0;
     order = false;
}


//Copy constructor
template <class elmtype>
CDA<elmtype> :: CDA(const CDA &src){
    cout << "In copy Constructor\n";
    capacity = src.capacity;
    end = src.end;
    front = src.front;
    length = src.length;
    order = src.order;
    array = new elmtype[capacity];
    for(int i=0;i<length;i++) {
        array[(front+i)%capacity] = src.array[(front+i)%capacity];
    }
}

//Copy assignment operator
template <class elmtype>
CDA<elmtype>& CDA<elmtype> :: operator=(const CDA<elmtype> &src) {
    cout << "In copy assignment operator\n";
    if (this != src) {
        capacity = src.capacity;
        end = src.end;
        length = src.length;
        order = src.order;
        array = new elmtype[capacity];
        for(int i=0;i<length;i++) {
            array[(front+i)%capacity] = src.array[(front+i)%capacity];
        }
    }
    return *this;
} 

template <class elmtype>
elmtype& CDA<elmtype> :: operator[](int i) {
    
}

template <class elmtype>
void CDA<elmtype> :: Printarray() {
    cout << "Capacity: " << capacity << endl;
    cout << "Length: " << length << endl;
    cout << "Front: " << front << endl;
    cout << "End: " << end << endl;
    cout << "Array\n";
    for (int i=0; i<length;i++){
            cout << array[(front + i)%capacity] << " ";
        }
    cout << endl << endl;
}

template <class elmtype>
void CDA<elmtype> :: AddEnd(elmtype v) {
    if (length == capacity){ // Out of space
        capacity = 2 * capacity;
        cout << "Doubling to: " << capacity << endl;
        elmtype *temp = new elmtype[capacity];
        for (int i=0; i<length;i++){
            temp[i] = array[(front + i)%length];
        }
        delete array;
        array = new elmtype[capacity];
        for(int i=0;i<length;i++){
            array[i] = temp[i];
        }
        free(temp);
        front = 0;
        end = length-1;
    }
    if (length == 0) { //no element
        array[front] = v;
        length++;
    }
    else {
        array[end + 1] = v;
        end++;
        length++;
    }

    
}

template <class elmtype>
void CDA<elmtype> :: AddFront(elmtype v) {
    if (length == capacity){ // Out of space
        capacity = 2 * capacity;
        cout << "Doubling to: " << capacity << endl;
        elmtype *temp = new elmtype[capacity];
        for (int i=0; i<length;i++){
            temp[i] = array[(front + i)%length];
        }
        free (array);
        array = new elmtype[capacity];
        for(int i=0;i<length;i++){
            array[i] = temp[i];
        }
        free(temp);
        front = 0;
        end = length-1;
    }
    if (length == 0) { //no element
        array[front] = v;
        length++;
    }
    else {
        if (front == 0) {
            front = capacity -1;
            array[front] = v;
            length++;
        }
        else {
            front--;
            array[front] = v;
            length++;
        }
    }
}

template <class elmtype>
void CDA <elmtype> :: DelEnd(){
    if(length == 0) {
        cout << "The array is empty\n";
        front = 0;
        end = 0;
    }
    
    else {
        if(end == 0) {
            end = capacity - 1;
            length--;
        }
        else {
            end--;
            length--;
        }
    
        if(length <= capacity * 0.25){
            capacity = capacity/2;
            cout << "Reducing to : " << capacity << endl;
            elmtype *temp = new elmtype[capacity];
            for (int i=0; i<length;i++){
                temp[i] = array[(front + i)%(2*capacity)];
            }
            free(array);
            array = new elmtype[capacity];
            for(int i=0;i<length;i++){
                array[i] = temp[i];
            }
            front = 0;
            end = length-1;
        }
        if(length == 0) {
            end = 0;
            front =0;
        }
    }
        
}

template <class elmtype>
void CDA <elmtype> :: DelFront() {
    if (length == 0){
        cout << "THe array is empty\n";
        front = 0;
        end = 0;
    }
    else {
        front = (front + 1) % capacity;
        length--;

        if(length <= capacity * 0.25){
            capacity = capacity/2;
            cout << "Reducing to : " << capacity << endl;
            elmtype *temp = new elmtype[capacity];
            for (int i=0; i<length;i++){
                temp[i] = array[(front + i)%(2*capacity)];
            }
            free(array);
            array = new elmtype[capacity];
            for(int i=0;i<length;i++){
                array[i] = temp[i];
            }
            front = 0;
            end = length-1;
        }
        if (length == 0) {
            front = 0;
            end = 0;
        }
    }
}

template <class elmtype>
int CDA <elmtype> :: Length() {
    return length;
}

template <class elmtype>
int CDA <elmtype> :: Capacity() {
    return capacity;
}

template <class elmtype>
int CDA <elmtype> :: Clear(){
    capacity = 1;
    length = 0;
    order = false;
    front = 0;
    end = 0;
    free(array);
    array = new elmtype[1];

}

template <class elmtype> 
bool CDA <elmtype> :: Ordered(){
    return order;
}

template <class elmtype>
int CDA <elmtype> :: SetOrdered() {
    if (length == 0) {
        cout << "The array is empty\n";
        order = false;
        return -1;
    }
    order = true;
    for(int i=0;i<length-1;i++) {
        if(array[(front + i) % capacity] > array[(front + i + 1)%capacity]){
            order = false;
        }
    }

    if (order == false){
        return -1;
    }
    else {
        return 1;
    }
}

template  <class elmtype>
void CDA <elmtype> :: QuickSort() {
    
}

template <class elmtype>
elmtype CDA <elmtype> :: Select(int k){

}

template <class elmtype>
void CDA <elmtype> :: InsertionSort() {
    for(int i=1;i<length;i++) {
        for(int j=i-1;j>=0 && array[(front+j+1)%capacity] < array[(front+j)%capacity];j--){
            elmtype temp = array[(front+j)%capacity];
            array[(front+j)%capacity] = array[(front+j+1)%capacity];
            array[(front+j+1)%capacity] = temp;
        }
    }
}

template <class elmtype>
void CDA <elmtype> :: CountingSort(int m){

}
template <class elmtype> 
int CDA <elmtype> :: Search (elmtype e){

}