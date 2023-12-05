#include<bits/stdc++.h>
using namespace std;

class Hero{
    private:
    int Health;
    public:
    Hero(){
        cout<<"this-> "<<this<<endl;
        cout<<"Constructor called"<<endl;
    }
    void setHealth(int Health){
        // Health=Health; // Here both Health is parameter.
        this->Health = Health;
    }
    int getHealth(){
        return Health;
    }
};

int main(){
    Hero H1;
    cout<<"Address of H1: "<<&H1<<endl;
    Hero H2;
    H1.setHealth(40);
    H2.setHealth(60);
    cout<<"H1 Health: "<<H1.getHealth()<<endl;
    cout<<"H2 Health: "<<H2.getHealth()<<endl;
}