#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    set<int>s;
    primeFactors(n,s);
    for(auto x: s)cout<<x<<" ";
    cout<<endl;
}