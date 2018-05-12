// The Necklace

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
#define clr(ar) memset(ar,0,sizeof(ar))

int T;
#define MAX 55
int edges[MAX][MAX];
int degree[MAX];
set<int> s;

void solve();
int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        int N1; cin>>N1;
        memset(edges, 0, sizeof(edges));
        memset(degree, 0, sizeof(degree));

        s.clear();
        while(N1--){
            int a, b;
            cin>>a>>b;
            s.insert(a); s.insert(b);
            degree[a]+=1;
            degree[b]+=1;
            edges[a][b] += 1;
            edges[b][a] += 1;
        }
    if(i!=1) cout<<endl;
    printf("Case #%d\n", i);
    solve();
    }
}

vector<pi> paths;
void eulerian(int i){
    loop(x, MAX){
        if(edges[i][x]){
            edges[i][x] -= 1;
            edges[x][i] -= 1;
            paths.push_back(make_pair(i, x));
            eulerian(x);
            printf("%d %d\n", x, i);
        }
    }
}

bool isEulerian(){
    loop(x,MAX){
        if(degree[x]%2!=0)
            return false;
    }
    return true;
}

void solve(){
    paths.clear();
    int f = *s.begin();
    if(!isEulerian()){
        printf("some beads may be lost\n");
        return;
    }
    eulerian(f);
   
    return;

}