#include <bits/stdc++.h>
using namespace std;
 
void primeFactors(int n, vector<int>& v)
{
    int c=2;
    while(n>1)
    {
        if(n%c==0){
            if(v.size()>0 && v[v.size()-1]==c){

            }else v.push_back(c);
            n/=c;
        }
        else c++;
    }
}
 
int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>primes;
    primeFactors(n,primes);
    cout<<"Φ("<<n<<")=";
    int ans=n;
    for(auto x:primes){
        ans=ans*(x-1);
    }
    for(auto x:primes){
        ans=ans/x;
    }
    cout<<ans<<endl;
}