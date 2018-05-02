// Heavy Cycle Edges

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
typedef pair<int,int> ii;

#define loop(x,n) for(int x = 0;x < n; ++x)

#define SIZE 1010
int n, m;
int u, v, w;
vector<pair<int, ii>> edges;
vi adj[SIZE];
bool visited[SIZE];
set<int> nodes; 
int cnt;

int dfs(int i);
int main(){
    while(true){
        edges.clear();
        memset(visited, 0, SIZE);
        scanf("%d %d", &n, &m);
        nodes.clear();
        if(n==0&&m==0) break;
        fill(adj, adj+n, vi());
        loop(x, m){
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back(make_pair(w, make_pair(u, v)));
            adj[u].push_back(v);
            adj[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }
        sort(edges.begin(), edges.end());
        bool exist = false;
        bool first = true;
        vi ans;

        if(nodes.size()==0){
            cout<<"forest"<<endl;
            continue;
        }

        for(vector<pair<int, ii>>::reverse_iterator it = edges.rbegin(); it!= edges.rend(); it++){
            memset(visited, 0, sizeof(visited));
            auto e = *it;
            int weight = e.first;
            ii edg = e.second;

            int cnt1 = dfs(edg.first);

            vi & v1 = adj[edg.first];
            vi & v2 = adj[edg.second];
            auto index1 = find(v1.begin(), v1.end(), edg.second);
            auto index2 = find(v2.begin(), v2.end(), edg.first);
            if(index1 != v1.end())
            adj[edg.first].erase(index1);
            if(index2 != v2.end())
            adj[edg.second].erase(index2);
            memset(visited, 0, sizeof(visited));
            int cnt2 = dfs(edg.first);
            if(cnt1 == cnt2){
                ans.push_back(weight);
                exist = true;
            }
            else{
                adj[edg.first].push_back(edg.second);
                adj[edg.second].push_back(edg.first);
            }
     
        }

        if(!exist)
            cout<<"forest"<<endl;
        else{
            sort(ans.begin(), ans.end());
            for(int a: ans){
                if(!first)
                cout<<" ";
                cout<<a;
                first = false;
            }
            cout<<endl;

        }
    }
}

int dfs(int i){
    int visitCnt = 0;
    if(visited[i]) return 0;
    visited[i] = 1;
    
    visitCnt++;
    for(auto x: adj[i]){
        visitCnt += dfs(x);
        
    }
    return visitCnt;
}