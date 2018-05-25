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

int c;
string s;
ll N;
vector<ll> fact;

void solve();
int main(){
    cin>>c;
    ll maxi = 1;
    fact.push_back(maxi);
    for(int i=1;i<=20;i++){
        maxi *=i;
        fact.push_back(maxi);
    }
    
    while(c--){
        cin>>s>>N;
        solve();
    }

}


ll calculate(string n){
    int cnt[30] = {0};
    ll num = fact[n.length()];
    for(auto c: n){
        cnt[c-'a'] += 1;
        num /= cnt[c-'a'];
    }
    return num;
}
// abcd dabc
// aabc
string getPerm(string st, ll left){
    if(left==0)
        return st;
    else{
        int idx = 0;
        string prefix = "";
        string suffix = "";
        for(int i=1;i<=st.length();i++){
            string pre = st.substr(0, st.length()-i);
            string subs = st.substr(st.length()-i, i);
            if(calculate(subs)>left){
                idx = i-1;
                prefix = pre; suffix = subs;
                break;
            }
        }

        char c = suffix[0];
        string rest = "";
        for(int i=0;i<suffix.length();i++){
            if(i!=0&&suffix[i]==c) continue;
            c = suffix[i];
            string pre = suffix.substr(0, i);
            string subs = suffix.substr(i+1, suffix.length()-i-1);
            rest = pre+subs;
            ll b = calculate(rest);
            if(b<=left){
                left -= b;
            }
            else{
                break;
            }
        }
        prefix = prefix+c;
        return prefix+getPerm(rest, left);
    }
}

void solve(){
    sort(s.begin(), s.end());
    string answer = getPerm(s, N);
    cout<<answer<<endl;
    // abcde
    // abcde
}