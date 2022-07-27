//Search element just greater than or equal to given number
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define nline "\n"

lli binarySearch(lli arr[], lli l, lli r, lli x){
    if(r>=l){
        lli mid=l+(r-l)/2;
        if(arr[mid]==x)return mid;
        if((mid>0 && arr[mid]>x && arr[mid-1]<x) || mid==0)return mid;
        if(arr[mid]>x){
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void solve(){
    lli n;cin>>n;
    lli arr[n];
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(lli i=0;i<n;i++){
        lli t;cin>>t;
        cout<<binarySearch(arr,0,n-1,t)<<nline;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}