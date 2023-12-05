#include<bits/stdc++.h>
using namespace std;

class Hero{
    private:
    int Health;
    char Level;
    char *name;
    public:
    Hero(){
        cout<<"Constructor called\n";
    }

    Hero(int Health){
        this->Health = Health;
        cout<<"First constructor: Health = "<<this->Health<<endl;
    }

    Hero(int Health, char Level){
        name = new char[100];
        this->Health = Health+2;
        this->Level = Level;
        cout<<"2nd constructor: Health = "<<this->Health<<endl;
    }

    Hero(Hero& temp){
        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        cout<<"User defined copy constructor called"<<endl;
        this->Health = temp.Health;
        this->Level = temp.Level;
        this->name = ch;
    }

    void print(){
        cout<<"[ Name: "<<this->name<<" ,";
        cout<<" Health: "<<this->Health<<" ,";
        cout<<" Level: "<<this->Level<<" ]"<<endl;
    }
    void setHealth(int H){
        this->Health = H;
    }
    void setName(char name[]){
        strcpy(this->name,name);
    }
};


int main(){

    Hero H1(23,'E');
    char name[10]="Hello";
    H1.setName(name);
    H1.print();
    Hero H2(H1);  //Copy constructor will be called only.
    H2.print();
    strcpy(name,"Below");
    H1.setName(name);
    H1.print();
    H2.print();
    H2=H1; //copy assignment operator
    H1.print();
    H2.print();
    
    // Hero H;  //calls the constructor without parameter
    // Hero H1(60); // calls the constructor with 1 parameter
    // Hero H2(24,'A'); //calls the constructor with 2 parameters 
}