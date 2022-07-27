#include<bits/stdc++.h>
using namespace std;

void modularExponent(int base, int exp, int mod){
    int res=1;
    base=base % mod;
    while(exp){
        if(exp%2==1){
            res = (res*base)%mod;
        }
        exp=exp>>1;
        base = (base*base)%mod;
    }
    cout<<res<<endl;
}

int main(){
    int base,exp,mod;
    cout<<"Enter base, exp and mod: ";
    cin>>base>>exp>>mod;
    modularExponent(base,exp,mod);
}