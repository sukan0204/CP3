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


int N, fibN;
string fibs, cipher;
string line;

map<int, int> fibMap;

void findFib();
void solve();

int main(){
    findFib();
    getline(cin, line);
    N = stoi(line);
    while(N--){
        getline(cin, line); fibN = stoi(line);
        getline(cin, fibs); getline(cin, cipher);
        solve();
    }
}

void solve(){
    string s = "";
    for(auto c: cipher){
        if(c>='A'&&c<='Z') {
            s+=c;
        }
    }

    string ans(fibMap.size(), ' ');

    stringstream ss(fibs);
    int fi; int i=0;
    int maxIdx = 0;
    while(ss>>fi){
        int idx = fibMap[fi];
        ans[idx-1] = s[i++]; maxIdx = max(maxIdx, idx);
    }
    ans = ans.substr(0, maxIdx);
    cout<<ans<<endl;
}

void findFib(){
    int f1 = 1, f2 = 1, idx = 1;
    fibMap[f2] = idx++;
    while(f1+f2>0){
        int f3 = f1+f2;
        fibMap[f3] = idx++;
        f1 = f2;
        f2 = f3;
    }
}