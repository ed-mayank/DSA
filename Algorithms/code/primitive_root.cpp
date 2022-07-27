#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    if(n==2 || n==3) return true;

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void primeFactors(int n, set<int>& s){
    while(n%2==0){
        s.insert(2);
        n=n/2;
    }
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            s.insert(i);
            n=n/i;
        }
    }
    if(n>2){
        s.insert(n);
    }
    return;
}

int modularExponent(int base, int exp, int mod){
    int res=1;
    base=base % mod;
    while(exp){
        if(exp%2==1){
            res = (res*base)%mod;
        }
        exp=exp>>1;
        base = (base*base)%mod;
    }
    return res;
}

int primitiveRoot(int n){
    if(!isPrime(n)) return -1;
    int phi = n-1;
    set<int>s;
    primeFactors(phi,s);
    bool flag = false;
    for(int i=2;i<(n-1);i++){
        flag=false;
        for(auto x:s){
            if(modularExponent(i,phi/x,n) == 1){
                flag=true;
                break;
            }
        }
        if(flag==false){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Smallest primitive root of "<<n<<" is "<<primitiveRoot(n)<<endl;
    return 0;
}