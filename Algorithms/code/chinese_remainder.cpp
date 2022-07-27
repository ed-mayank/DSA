#include<bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int* x, int* y){
    if(a==0){
        *x=0;
        *y=1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1- (b/a)*x1;
    *y = x1;

    return gcd;
}

int modInverse(int a, int m){
    int x, y;
    int gcd = gcdExtended(a, m, &x, &y);
    if(gcd != 1){
        cout<<"Inverse doesn't exist\n";
        return 0;
    }
    else{
        int res = (x%m + m)%m;
        return res;
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>mod;
    vector<int>rem;
    int M=1;
    cout<<"Enter array of modulus: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mod.push_back(x);
        M = M*x;
    }
    cout<<"Enter array of remaindes: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        rem.push_back(x%M);
    }

    int X=0;
    for(int i=0;i<n;i++){
        X+= ((rem[i])*(M/mod[i])*(modInverse(M/mod[i],mod[i])%M))%M;
    }

    cout<<X%M<<endl;


    return 0;
}