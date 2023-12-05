#include<bits/stdc++.h>
using namespace std;

class Hero{
    public:
    Hero(){
        cout<<"Default constructor is called\n";
    }
    ~Hero(){
        cout<<"Default destructor is called\n";
    }
};

int main(){
    Hero H1;
    Hero* H2 = new Hero();
    delete H2;
    return 0;
}