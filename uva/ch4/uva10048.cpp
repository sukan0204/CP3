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
typedef pair<int,int> ii;

#define loop(x,n) for(int x = 0;x < n; ++x)

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


int C, S, Q;
int c1, c2, d;
vector<ii> edges[110];
bool visited[110];
vector<pair<int, ii>> edgeList;
int minWeight[110][110];


void query(int cc1, int cc2);
//void dfs(int original, int i, int answer=0);
int path(int cc1, int cc2);
int main(){
    int tc = 1;
    while(true){
        cin>>C>>S>>Q;
        edgeList.clear();
        if(C==0&&S==0&&Q==0) break;
        fill(edges, edges+C, vector<ii>());
        loop(x, S){
            cin>>c1>>c2>>d;
            edgeList.push_back(make_pair(d, ii(c1, c2)));
 
        }
        for(int i=1;i<=C;i++){
            for(int j=1;j<=C;j++){
                minWeight[i][j] = -1;
            }
            minWeight[i][i] = 0;
        }
        UnionFind UF(C+1);
        
        sort(edgeList.begin(), edgeList.end());
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<edgeList.size();i++){
            pair<int, ii> front = edgeList[i];
            if(!UF.isSameSet(front.second.first, front.second.second)){
                minWeight[front.second.first][front.second.second] = front.first;
                minWeight[front.second.second][front.second.first] = front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
        }
  
        if(tc>1) cout<<endl;
        printf("Case #%d\n", tc++);
        loop(x, Q){
            int cc1, cc2;
            cin>>cc1>>cc2;
            if(!UF.isSameSet(cc1, cc2)){
                cout<<"no path"<<endl;
            }
            else{
                memset(visited, 0, sizeof(visited));
               cout<<path(cc1, cc2)<<endl; 
            }
        }
        
        
    }
    return 0;
}

int path(int a, int b){
    if(a==b) return 0;
    visited[a] = 1;
    int pathWeight = INT_MAX;
    for(int j=1;j<=C;j++){
        if(minWeight[a][j]>=0&&a!=j&&!visited[j]){
            int temp = max(minWeight[a][j], path(j, b));
           pathWeight = min(pathWeight, temp);
        }
    }
    return pathWeight;
}
