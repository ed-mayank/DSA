#include<bits/stdc++.h>
using namespace std;

class Hero{
    public:
    int Health = 12;
    static int timeToComplete; //can not be initilized here

    static int Hello(){
        return timeToComplete;
    }
};

int Hero::timeToComplete  = 9;

int main(){
    // Hero H1;
    // cout<<H1.Health<<endl;
    // cout<<H1.timeToComplete<<endl;
    cout<<Hero::timeToComplete<<endl;
    cout<<Hero::Hello()<<endl;
    return 0;
}