#include<bits/stdc++.h>
using namespace std;

void binaryExponentiation(int base,int exp){
    int res=1;
    while(exp){
        if(exp%2==1){
            res=res*base;
        }
        exp=exp>>1;
        base=base*base;
    }
    cout<<res<<endl;
}

int main(){
    int base,exp;
    cout<<"Enter base and exponent: ";
    cin>>base>>exp;
    binaryExponentiation(base,exp);
}