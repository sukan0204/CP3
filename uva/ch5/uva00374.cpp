// Big Mod
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define INF 1000000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

ll B, P, M;

void solve();

int main(){
    while(cin>>B){
        cin>>P>>M;
        solve();
    }
}

void solve(){
    // solve B^P mod M
    vector<ll> mods;
    mods.push_back(1);
    ll bit = 1;
    ll mod = B%M;
    while(bit>0&&bit<P){
        mods.push_back(mod);
        bit = bit<<1;
        mod = (mod*mod)%M;
    }
    ll ans = 1;
    while(P>0){
        int highestBit = (int)log2(P);
        P -= (int)pow(2, highestBit);
        ans *= mods[highestBit+1];
        ans %= M;
    }
    cout<<ans<<endl;

}