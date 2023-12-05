#include<bits/stdc++.h>
using namespace std;

class Hero{
    // int x,y;
    private:
        int Health;
    public:
        char level;
        
        void setHealth(int h){
            Health = h;
        }
        int getHealth(){
            return Health;
        }
};

int main(){
    //static allocation
    Hero h1;
    h1.setHealth(49);
    cout<<h1.getHealth()<<endl;
    
    //dynamic allocation
    Hero *a = new Hero;
    a->level = 'B';
    a->setHealth(30);
    cout<<"Level: "<<a->level<<endl;
    cout<<"Health: "<<a->getHealth()<<endl;

    (*a).level = 'A';
    (*a).setHealth(10);
    cout<<"Level: "<<(*a).level<<endl;
    cout<<"Health: "<<(*a).getHealth()<<endl;
}