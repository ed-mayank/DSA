#include<bits/stdc++.h>
using namespace std;

class Human{
    private:
    int height;

    protected:
    int weight;

    public:
    int age;

    void setAge(int age){
        this->age = age;
    }
    void setHeight(int height){
        this->height = height;
    }
    void setWeight(int weight){
        this->weight = weight;
    }

    int getAge(){
        return this->age;
    }
    int getHeight(){
        return this->height;
    }
};

class Male:public Human{
    public:
    string color;

    void sleep(){
        cout<<"Male sleep alot"<<endl;
    }
    int getWeight(){    //Weight is protected
        return this->weight;
    }
};

class Animal{
    public:
    int species;
    int family;
    int genus;

    Animal(){
        cout<<"Animal constructor called"<<endl;
    }

    void Family(){
        cout<<"This animal belong to dog family"<<endl;
    }
};

class HumanBeing{
    public:
    
    HumanBeing(){
        cout<<"Human constructor called"<<endl;
    }

    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class Mammals: public HumanBeing,public Animal{  //Multiple inheritence
    public:
    Mammals(){
        cout<<"Mammals constructor called"<<endl;
    }
};

int main(){

    Mammals M;
    // M.Family();
    // M.speak();

    // Male M1;
    // M1.setAge(21);
    // cout<<M1.getAge()<<endl;
    // M1.color="Green";
    // cout<<M1.color<<endl;
    // M1.setWeight(63);
    // cout<<M1.getWeight()<<endl;
    return 0;
}