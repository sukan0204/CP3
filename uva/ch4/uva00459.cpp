// Graph Connectivity
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

int T;
bool graph[30][30];
string line;
char large;
bool visited[30];
void dfs(int i){
    visited[i] = true;
    for(int j=0;j<=large-'A'; j++){
        if(graph[i][j]&&!visited[j])
            dfs(j);
    }
}
int solve(){
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for(int i=0;i<=large-'A';i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main(){
   getline(cin, line);
    T = stoi(line);
    bool first = true;
    getline(cin, line);
    while(T--){
        memset(graph, 0, sizeof(graph));
        getline(cin, line);
        large = line[0];
        while(getline(cin, line)){
            if(line.empty()) break;
            graph[line[0]-'A'][line[1]-'A']=1;
            graph[line[1]-'A'][line[0]-'A']=1;
        }
        if(!first)
        cout<<endl;
        cout<<solve()<<endl;
        first = false;
    }

    return 0;
}