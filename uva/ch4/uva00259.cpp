// software allocation
// network flow

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

int apps[30];
int edges[30][30];
int appsTotal = 0;
void constructGraph();
string solve();
int main(){
    memset(apps, 0, sizeof(apps));
    memset(edges, 0, sizeof(edges));
    for(string line; getline(cin, line);){
        if(line.empty()){
            constructGraph();
            cout<<solve()<<endl;
            memset(apps, 0, sizeof(apps));
            memset(edges, 0, sizeof(edges));
            appsTotal = 0;
            continue;
        }
        string app, comp;
        stringstream ss(line);
        ss>>app>>comp;
        int ap = app[0]-'A'; int apNum = app[1]-'0';
        appsTotal += apNum;
        apps[ap] = apNum;
        for(auto c: comp){
            if(c==';') break;
            int compNum = c-'0';
            edges[ap][compNum] = 1;
        }
    }
    constructGraph();
    cout<<solve()<<endl;
}
#define MAX_V 41
int res[MAX_V][MAX_V], mf, f, s, t;
vi p;
void constructGraph(){
    s = 0; t = 40;
    memset(res, 0, sizeof(res));
    for(int j=0;j<10;j++){
        res[j+30][t] = 1;
     
    }
    for(int i=0;i<30;i++){
        if(apps[i]>0){
            res[s][1+i] = apps[i];
    
            for(int j=0;j<10;j++){
                if(edges[i][j]){
                res[1+i][j+30] = 1;
              
                }
            }
        }
    }
}
void augment(int v, int minEdge){
    if(v == s){ f = minEdge; return; }
    else if(p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}
// Edmond Karp
string solve(){
    mf = 0;
    string ans(10, '_');
    while(1){
        f = 0;
        vi dist(MAX_V, INF); dist[s] = 0;
        queue<int> q; q.push(s);
        p.assign(MAX_V, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v = 0; v < MAX_V; v++){
                if(res[u][v]>0&&dist[v]==INF){
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                }
            }
        }
        augment(t, INF);
        if(f == 0) break;

        mf += f;
    }
    if(mf != appsTotal)
        return "!";
    else{
  
        for(int i=30;i<40;i++){
            if(res[t][i]){
                int pos = -1;
                char c = 'z';
                for(int j=1;j<30;j++){
                    if(res[i][j]){
                        pos = i-30;
                        c = j-1+'A';
                        ans[pos] = c;
                        break;
                    }
                }
            }    
        }

        return ans;
    }
}