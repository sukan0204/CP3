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

int k, a, b, n, m;
string line;
vi fib;
int findPisanoPeriod(int a, int b, int m){
    fib.clear();
    int mod = (int)pow(10.0, m);
    fib.push_back(a%mod);
    fib.push_back(b%mod);
    while(true){
        int f_2 = fib[fib.size()-2];
        int f_1 = fib[fib.size()-1];
        int f_0 = (f_2+f_1)%mod;
        fib.push_back(f_0);
        if(f_1==a%mod&&f_0==b%mod){
            return fib.size()-2;
        }
    }
}



void solve(){
    int period = findPisanoPeriod(a, b, m);
    n = n%period;
    cout<<fib[n]<<endl;
}

int main(){
    getline(cin, line);
    sscanf(line.c_str(), "%d", &k);
    while(k--){
        getline(cin, line);
        sscanf(line.c_str(), "%d %d %d %d", &a, &b, &n, &m);
        //printf("%d %d %d %d\n", a, b, n, m);
        solve();
    }
}