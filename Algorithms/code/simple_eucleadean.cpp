#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

int main(){
    int a,b;
    cout<<"Enter a and b (b>a): ";
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
}