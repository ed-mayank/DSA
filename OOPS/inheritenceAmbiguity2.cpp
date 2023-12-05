#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int x=9;
    void func1(){
        cout<<"From inside class A"<<endl;
    }
};

class B{
    public:
    int x=0;
    void func1(){
        cout<<"From inside class B"<<endl;
    }
};

class C: public A, public B{
    public:
    int y=0;
};

int main(){
    C obj1;
    obj1.A::func1();
    cout<<obj1.B::x<<endl;
    return 0;
}