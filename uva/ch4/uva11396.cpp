// Claw Decomposition

// bipartite graph + if all vertices on each side have three edges

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
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define loop(x,n) for(int x = 0;x < n; ++x)

int V;
bool edges[310][310];
int colors[310];
int a, b;
bool dfs(int i, int color){
    colors[i] = color;
    bool bip = true;
    int nextColor = color==1?2:1;
    loop(x, V){
        if(edges[i][x+1]&&!colors[x+1])
            bip = bip && dfs(x+1, nextColor);
        else if(edges[i][x+1]&&colors[x+1])
            if(colors[x+1]!=nextColor){
                return false;
            }
    }
    return bip;
}
int main(){
    while(true){
        cin>>V;
        if(V==0) break;
        memset(edges, 0, sizeof(edges));
        memset(colors, 0, sizeof(colors));
        while(true){
            cin>>a>>b;
            if(a==0&&b==0) break;
            edges[a][b] = 1;
            edges[b][a] = 1;
        }
        bool claw = true;
        for(int i=0;i<V;i++){
            if(colors[i+1]==0)
                claw = claw && dfs(i+1, 1);
        }
        if(claw) cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
}