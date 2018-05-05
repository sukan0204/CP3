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

#define loop(x,n) for(int x = 0;x < n; ++x)

int n;
// Positive cycle along the way makes it reachable
string line;
int energies[110];
vi edges[110];
void solve();
int c=1;
int main(){
    while(true){
        cin>>n;
        if(n==-1) break;
        for(int i=1;i<=n;i++){
            int energy, doors;
            cin>>energy>>doors;
            energies[i] = energy;
            int temp;
            edges[i].clear();
            loop(x, doors){
                cin>>temp;
                edges[i].push_back(temp);
            }
        }
        solve();
    }

}

bool visited[110];
bool connected[110][110];
void dfs(int i){
    visited[i] = 1;
    for(auto j: edges[i]){
        if(!visited[j])
        dfs(j);
    }
}
void connect(){
    memset(connected, 0, sizeof(connected));
    for(int i=1;i<=n;i++){
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for(int j=1;j<=n;j++){
            if(visited[j]){
                connected[i][j] = 1;
            }
        }
    }
}

vi dist;
void solve(){
    dist.clear();
    dist.resize(n+1, 0);
    dist[1] = 100;
    for(int i=0;i<n-1;i++){
        for(int u = 0;u<n;u++){
            for(int& door: edges[u+1]){
                if(dist[u+1]!=0){
                    dist[door] = max(dist[door], dist[u+1]+energies[door]);
                }
            }
        }
    }
    connect();
    bool hasPositiveCycle = false;
    for(int u = 0;u<n;u++){
        for(int& door: edges[u+1]){
            if(connected[1][door]&&connected[door][n]&&dist[u+1]!=0 && dist[door] < dist[u+1]+energies[door]){
                hasPositiveCycle = true;
                break;
            }
        }
    }
    c++;

    if(connected[1][n]&&(hasPositiveCycle||dist[n]>0))
        cout<<"winnable"<<endl;
    else
        cout<<"hopeless"<<endl;
}