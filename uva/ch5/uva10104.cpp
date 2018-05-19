// Euclid Problem
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
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

#define INF 1000000000
#define loop(x,n) for(ll x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

ll c, d;
ll x, y;

string line;
void solve();
ll gcd(ll a, ll b);
int main(){
  //  n1*x+n2*y = n;
    while(getline(cin, line)){
        stringstream ss(line);
        ss>>c>>d;
        solve();
    }
}

void extendedEuclid(ll a, ll b){
    if(b==0){
        x=1; y=0;return;
    }
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = x-(a/b)*y;
    x = x1;
    y = y1;
}


void solve(){
    extendedEuclid(c, d);
    printf("%lld %lld %lld\n", x, y, gcd(c, d));
}

ll gcd(ll a, ll b){
    if(a==1||b==1){
        return 1;
    }
    if(a==0||b==0){
        return max(a,b);
    }
    ll c = max(a, b);
    ll d = min(a, b);
    return gcd(c%d, d);
}
