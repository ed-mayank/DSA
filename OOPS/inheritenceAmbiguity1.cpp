#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int x=9;
    void func1(){
        cout<<"From inside class A"<<endl;
    }
};

class B: public A{
    public:
    int x=0;
    void func1(){
        cout<<"From inside class B"<<endl;
    }
};

int main(){
    B obj1;
    obj1.func1();
    cout<<obj1.x<<endl;
    return 0;
}