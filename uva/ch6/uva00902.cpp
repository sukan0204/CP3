// Password Search

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

string line;
int N; string str;

void solve();

int main(){
    while(cin>>N){
        cin>>str;
        solve();
    }
}

void solve(){
    map<string, int> freq;
    int maxFreq = 0;
    string ans = "";
    for(int i=0;i<=str.length()-N;i++){
        string s = str.substr(i, N);
        if(freq.find(s)!=freq.end()){
            freq[s] += 1;
        }
        else{
            freq[s] = 1;
        }
       // cout<<s<<":"<<freq[s]<<endl;

        if(maxFreq<freq[s]){
            ans = s; maxFreq = freq[s];
        }
    }
    cout<<ans<<endl;
}