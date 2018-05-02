// Dominos

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
#define SIZE 100010
int t;
int n, m;
int x, y;
vector<vi> adj;
stack<int> st;
bool visited[SIZE];

void topo_sort(int i);
void scc(int i);
int main(){
    cin>>t;
    adj.resize(SIZE, vi());
    while(t--){
        cin>>n>>m;
        fill(adj.begin(), adj.begin()+n+1, vi());
        memset(visited, 0, SIZE);
        loop(i, m){
            cin>>x>>y;
            adj[x].push_back(y);
        }
        for(int i=1;i<=n;i++)
            if(!visited[i])
                topo_sort(i);
        memset(visited, 0, SIZE);
        int ans = 0;
        while(!st.empty()){
            int cur = st.top();
            if(!visited[cur]){
                ans++;
                scc(cur);
            }
            st.pop();
        }
        cout<<ans<<endl;
    }

}

void topo_sort(int i){
    visited[i] = true;
    for(auto& n: adj[i]){
        if(!visited[n])
            topo_sort(n);
    }
    st.push(i);
}

void scc(int i){
    visited[i] = true;
    for(auto& n: adj[i]){
        if(!visited[n]){
            scc(n);
        }
    }
}