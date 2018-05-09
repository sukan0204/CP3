// Many Paths, One Destination
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

int vn;
vector<vi> edges;
vector<vi> revEdges;
vi dp;
int solve();
void topo();
int main(){
    string line;
    bool first = true;
    while(getline(cin, line)){
        vn = stoi(line);
        edges.clear(); revEdges.clear(); dp.clear();
        edges.resize(vn+1); revEdges.resize(vn+1); dp.resize(vn+1, 0);
        loop(x, vn){
            getline(cin, line);
            stringstream ss(line);
            int n, e;
            ss>>n;
            if(n==0){
                edges[x].push_back(vn);
                revEdges[vn].push_back(x);
            }
            while(n--){
                ss>>e;
                edges[x].push_back(e);
                revEdges[e].push_back(x);
            }
        }
        topo();
        if(!first) cout<<endl;
        cout<<solve()<<endl;
        getline(cin, line);
        first = false;
    }
}

vi ordered;
vector<bool> visited;
void dfs(int i){
    visited[i] = true;
    for(auto j: edges[i]){
        if(!visited[j]){
            dfs(j);
        }
    }
    ordered.push_back(i);
}
void topo(){
    ordered.clear();
    visited.clear();
    visited.resize(vn+1, 0);
    dfs(0);
    reverse(ordered.begin(), ordered.end());
}

int solve(){
    dp[0] = 1;
    for(int i=0;i<ordered.size();i++){
        for(auto j: revEdges[i]){
            dp[i] += dp[j];
        }
    }
    return dp[vn];
}