// Project Scheduling

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

int T;
bool exist[30];
int edges[30][30];
int revEdges[30][30];
int weight[30];

void topo();
void solve();
int main(){
    string line;
    getline(cin, line);
    T = stoi(line);
    getline(cin, line);
    int first = true;
    while(T--){
        memset(exist, 0, sizeof(exist));
        memset(edges, 0, sizeof(edges));
        memset(revEdges, 0, sizeof(revEdges));
        memset(weight, 0, sizeof(weight));
        while(getline(cin, line)&&!line.empty()){
            stringstream ss(line);
            char c; int d; string s;
            ss>>c>>d>>s;
            weight[c-'A'] = d;
            exist[c-'A'] = true;
            for(auto cc:s){
                edges[cc-'A'][c-'A'] = 1;
                revEdges[c-'A'][cc-'A'] = 1;
            }
        }
        if(!first) cout<<endl;
        topo();
        solve();
        first = false;
    }
}

vi ordered;
bool visited[30];
void dfs(int i);
void topo(){
    ordered.clear();
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<30;i++){
        if(!visited[i]&&exist[i])
            dfs(i);
    }
    reverse(ordered.begin(), ordered.end());

}
void dfs(int i){
    visited[i] = true;
    for(int j=0;j<30;j++){
        if(edges[i][j]){
            if(!visited[j]&&exist[j])
                dfs(j);
        }
    }
    ordered.push_back(i);
}
int dp[30];
void solve(){
    fill(dp, dp+30, 0);
    dp[0] = weight[ordered[0]];
    for(int i=0;i<ordered.size();i++){
        for(int j=0;j<=i;j++){
            int id1 = ordered[i];
            int id2 = ordered[j];
            if(revEdges[id1][id2]){
                dp[i] = max(dp[i], dp[j]+weight[ordered[i]]);
            }
        }
    }
    int ans = dp[0];
    for(int i=0;i<ordered.size();i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
}