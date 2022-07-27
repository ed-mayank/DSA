#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> PLL;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<PLL> VPLL;
#define F first
#define S second
#define SET(a, b) memset(a, b, sizeof(a))
const long long mod = 1e9 + 7;
#define nline "\n"

void solve(){
    map<int,vector<int>>m;
    m[0].push_back(4);
    m[1].push_back(3);
    m[0].push_back(2);
    m[0].push_back(9);
    m[1].push_back(8);

    map<int,vector<int>> :: iterator it;
    for(auto x:m){
        cout<<x.second.size()<<endl;
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