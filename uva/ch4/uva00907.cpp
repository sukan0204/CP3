// Winterim Backpacking Trip
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

int N, K;
int dist[610];
int mem[610][310];

void solve();

int main(){
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        ss>>N>>K;
        int sum = 0;
        loop(x, N+1){
            getline(cin, line);
            sum += stoi(line);
            dist[x] = sum;
        }
        solve();
    }

}

// min cost when spending jth night on ith campsite
int dp(int i, int j){
    if(j == 0){
        mem[i][j] = dist[i];
    }
    if(mem[i][j]!=-1) return mem[i][j];
    mem[i][j] = INF;
    for(int k=0;k<=i;k++){
        mem[i][j] = min(mem[i][j], max(dp(k, j-1), dist[i]-dist[k]));
    }
    return mem[i][j];
}

void solve(){
    memset(mem, -1, sizeof(mem));
    dp(N, K);
    int mincost = INF;
    for(int i=0;i<=K;i++){
        mincost = min(mem[N][i], mincost);
    }
    cout<<mincost<<endl;
}

