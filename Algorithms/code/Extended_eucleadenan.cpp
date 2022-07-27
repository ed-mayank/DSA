#include <bits/stdc++.h>
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

int main(){
    int x,y,a,b;
    cout<<"Enter a and b (b>a): ";
    cin>>a>>b;
    int gcd = gcdExtended(a,b,&x,&y);
    cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<" = "<<gcd<<endl;
    return 0;
}