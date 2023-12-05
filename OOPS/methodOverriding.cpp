#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void Hello(){
        cout<<"From class A"<<endl;
    }
};

class B: public A{
    public:
    void Hello(){
        cout<<"From class B"<<endl;
    }
};

class C: public A{
    public:
    void Hello(){
        cout<<"From class C"<<endl;
    }
};

int main(){
    A obj1;
    B obj2;
    C obj3;
    obj1.Hello();
    obj2.Hello();
    obj3.Hello();
    return 0;
}