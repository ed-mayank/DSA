#include<bits/stdc++.h>
using namespace std;

class A {
    public:
    int a;

    // overloading + operator
    void operator+ (A &obj){
        int val1 = this->a;
        int val2 = obj.a;

        cout<<val1-val2<<endl;
    }

    // overloading () operator
    void operator() (){
        cout<<"Bracket is called "<<this->a<<endl;
    }

    // overloading * operator
    void operator* (A &obj){
        cout<<"* operator is called"<<endl;
    }

    // overloading ++ operator (prefix)
    void operator++ (){
        cout<<"Prefix Increment operator is called "<<this->a<<endl;
    }

    //overloading ++ postfix operator
    void operator++ (int){
        cout<<"Postfix increment operator is called "<<this->a<<endl;
    }
};

int main(){

    A obj1,obj2;
    obj1.a = 6;
    obj2.a = 4;
    obj1+obj2;  // obj2 is passed as parameter to operator+
    obj2+obj1;  // obj1 is passed as parameter
    obj1();
    obj1*obj2;
    ++obj1;     
    obj1++;
    return 0;
}