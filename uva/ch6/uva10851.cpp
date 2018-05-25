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

int N;
vector<string> hiero;

void solve();

int main(){
    string line;
    getline(cin, line);
    N = stoi(line);
    while(N--){
        hiero.clear();
        while(true){
            getline(cin, line);
            if(!cin||line.empty()) break;
            hiero.push_back(line);
        }
        solve();
    }
}

void solve(){
    vector<short> mat;
    int r, c;
    r = hiero.size();
    c = (*hiero.begin()).length();
    for(int i=1;i<c-1;i++){
        char c = 0;
        for(int j=1;j<r-1;j++){
            if(hiero[j][i]!='/')
                c += 1<<(j-1);
        }
        cout<<c;
    }
    cout<<endl;
}