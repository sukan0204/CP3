// Down Went the Titanic
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
#define INF 1000
#define loop(x,n) for(int x = 0;x < n; ++x)

int X, Y, P;
char areas[31][31];
void constructGraph();
void edmondsKarp();
int main(){
    string line;
    while(true){
        memset(areas, 0, sizeof(areas));
        if(!getline(cin, line)) break;
        stringstream ss(line);
        ss>>X>>Y>>P;
        loop(x, X){
            getline(cin, line);
            loop(y, Y){
                areas[x][y] = line[y];
            }
        }
        constructGraph();
        edmondsKarp();
       // cout<<"edmond"<<endl;
        getline(cin, line);
    }
}

int s = 0, t = 1;
int xoff[4] = {-1, 1, 0, 0};
int yoff[4] = {0, 0, 1, -1};
int res[1810][1810];
int mapping1[30][30];
int mapping2[30][30];
void constructGraph(){
    t = 1;
    map<char, int> vertex, weight;
    vertex['*'] = 1; weight['*'] = 1;
    vertex['.'] = 1; weight['.'] = 1;
    vertex['@'] = INF; weight['@'] = 1;
    vertex['#'] = INF; weight['#'] = P;
    memset(res, 0, sizeof(res));
    memset(mapping1, 0, sizeof(mapping1));
    memset(mapping2, 0, sizeof(mapping2));
    loop(x, X){
        loop(y, Y){
            if(areas[x][y]!='~'){
                int nodeId = t++; mapping1[x][y] = nodeId;
                int secondNodeId = t++; mapping2[x][y] = secondNodeId;
                int w = vertex[areas[x][y]];
                res[nodeId][secondNodeId] = w;
                if(areas[x][y]=='*'){
                    res[s][nodeId] = 1;
                }

            }
        }
    }
    loop(x, X){
        loop(y, Y){
            if(areas[x][y]!='~'){
                for(int i = 0;i<4;i++){
                int neighborX = x+xoff[i];
                int neighborY = y+yoff[i];
                if(neighborX>=0&&neighborX<X&&neighborY>=0&&neighborY<Y){
                    if(areas[neighborX][neighborY]!='~'){
                        int firstId = mapping2[x][y];
                        int secondId = mapping1[neighborX][neighborY];
                        int w = vertex[areas[neighborX][neighborY]];
                        res[firstId][secondId] = w;
                    }
                }
                }
                if(areas[x][y]=='#'){
                    int second = mapping2[x][y];
                    res[second][t] = P;
                }
            }
        }
    }

}
int mf, f;
vi p;
void augment(int v, int minEdge){
    if(v == s){ f = minEdge; return; }
    else if(p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -=f; res[v][p[v]]+=f;
    }
}
void edmondsKarp(){
    mf = 0;
    while(1){
        f = 0;
        vi dist(t+1, INF);
        p.clear();
        dist[s] = 0; queue<int> q; q.push(s);
        p.assign(t+1, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v = 0; v<t+1;v++){
                if(res[u][v]>0&&dist[v]==INF){
                    dist[v] = dist[u]+1;q.push(v), p[v] = u;
                }
            }
        }
        augment(t, INF);
        if(f==0) break;
        mf+=f;
    }
    printf("%d\n", mf);
}