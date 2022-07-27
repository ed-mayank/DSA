#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    private:
        int _size{};
        vector<int> v = {-1};

        int parent(int i) {return i>>1;};
        int lchild(int i) {return i<<1;};
        int rchild(int i) {return (i<<1)+1;};

    public:
        bool isEmpty() const {return _size==0;};
        int getMax() const {return v[1];};
        void insertElement(int val);
        void shiftUp(int i);
        int extractMax();
        void shiftDown(int i);
        void printHeap();
};

void MaxHeap::shiftUp(int i){
    if(i>_size) return;
    if(i == 1) return;
    if(v[i] > v[parent(i)]){
        swap(v[i],v[parent(i)]);
    }else{
        return;
    }
    shiftUp(parent(i));
    return;
}

void MaxHeap::insertElement(int val){
    _size++;
    v.push_back(val);
    shiftUp(_size);
    return;
}

void MaxHeap::shiftDown(int i){
    if(i > _size) return;
    int swapId=i;
    if(lchild(i)<=_size){
        if(v[lchild(i)]>v[rchild(i)]){
            swapId=lchild(i);
        }else{
            swapId=rchild(i);
        }
    }
    if(i==swapId)return;
    swap(v[i],v[swapId]);
    shiftDown(swapId);
}

int MaxHeap::extractMax(){
    int Max = v[1];
    v[1]=v[_size];
    v.pop_back();
    _size--;
    shiftDown(1);
    return Max;
}

void MaxHeap::printHeap(){
    for(auto x : v){
        if(x>0)
            cout<<x<<" ";
    }
    cout<<endl;
}


int main(){
    MaxHeap* pq = new MaxHeap();
    pq->insertElement(2);
    pq->insertElement(23);
    pq->insertElement(88);
    pq->insertElement(6);
    pq->insertElement(5);
    pq->insertElement(3);
    pq->insertElement(8);
    pq->insertElement(5);
    if(pq->isEmpty()){
        cout<<"Heap is empty\n";
    }
    pq->printHeap();
    pq->extractMax();
    pq->printHeap();
}