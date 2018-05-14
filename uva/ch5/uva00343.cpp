// What base is this?

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
typedef pair<int,int> pi;
#define INF 1000000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

int detectMinBase(string s){
    int base = 2;
    for(auto c: s){
        if(c>='0'&&c<='9'){
            base = max(base, c-'0'+1);
        }
        if(c>='A'&&c<='Z'){
            base = max(base, c-'A'+11);
        }
    }
    return base;
}

ll calculate(string a, int base){
    ll dec = 0;
    ll mult = 1;
    reverse(a.begin(), a.end());
    for(auto c: a){
        int digit = c<='9'&&c>='0'?c-'0':c-'A'+10;
        dec += mult*digit;
        mult*=base;
    }
    return dec;
}
vi avec;
vi bvec;
string a, b;
string line;

void solve(){
    avec.clear();
    bvec.clear();
    avec.resize(40, 0);
    bvec.resize(40, 0);
    int amin = detectMinBase(a);
    int bmin = detectMinBase(b);
    for(int i=amin;i<=36;i++){
        avec[i] = calculate(a, i);
    }
    for(int i=bmin;i<=36;i++){
        bvec[i] = calculate(b, i);

    }
    for(int i=amin;i<=36;i++){
        for(int j=bmin;j<=36;j++){
            if(avec[i]==bvec[j]){
                printf("%s (base %d) = %s (base %d)\n", a.c_str(), i, b.c_str(), j);
                return;
            }
        }
    }
    printf("%s is not equal to %s in any base 2..36\n", a.c_str(), b.c_str());
}


int main(){
    while(getline(cin, line)){
        stringstream ss(line);
        ss>>a>>b;
        solve();
    }
}