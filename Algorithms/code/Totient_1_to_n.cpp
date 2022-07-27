#include<bits/stdc++.h>
using namespace std;

void PhiCalculate(int n){
    vector<int>phi;
    for(int i=0;i<=n;i++){
        phi.push_back(i);
    }
    for(int p=2;p<=n;p++){
        if(phi[p]==p){  //p is prime
            phi[p]=p-1;
            for(int i=2*p;i<=n;i+=p){
                phi[i]=(phi[i]/p)*(p-1);
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<"phi("<<i<<") = "<<phi[i]<<endl;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    PhiCalculate(n);
}