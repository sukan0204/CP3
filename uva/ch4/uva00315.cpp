// Network

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

int edges[101][101];
int parent[101];
bool visited[101];
int low[101];
int num[101];
string line;
int N;
int counter;
int ans;
set<int> arp;
int root;

void findArt(int v){
    visited[v] = true;
    low[v] = num[v] = counter++;
    for(int i=0;i<=N;i++){
        if(edges[v][i]){
            if(!visited[i]){
                parent[i] = v;
                if(v == 1){
                    root++;
                }
                findArt(i);
                if(low[i]>=num[v]){
                    if(v!=1){
                        arp.insert(v);
                    }
                }
                low[v] = min(low[v], low[i]);
            }        
        else if(parent[v]!=i)
                low[v] = min(low[v], num[i]);
        
        }
    }
}

void solve(){
    counter = 0;
    ans = 0;
    memset(low, 0, sizeof(low));
    memset(num, 0, sizeof(num));
    memset(parent, 0, sizeof(parent));
    memset(visited, 0, sizeof(visited));
    arp.clear();
    root = 0;
    findArt(1);

    ans = arp.size();
    
    if(root>1) ans++;
    cout<<ans<<endl;
}

int main(){
    while(true){
        getline(cin, line);
        N = stoi(line);
        if(N==0) break;
        memset(edges, 0, sizeof(edges));

        while(true){
            getline(cin, line);
            int first;
            int temp;
            stringstream ss(line);
            ss>>first;
            if(first == 0) break;
            while(ss>>temp){
                edges[first][temp] = 1;
                edges[temp][first] = 1;   
            }
        }
        solve();    
        
    }
}