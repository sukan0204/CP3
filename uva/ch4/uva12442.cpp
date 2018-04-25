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

#define limit 50010
int T, N;
vector<int> mar;
vi dp;
bool visited[limit];

int dfs(int a){
    visited[a] = 1;
    int sum = 0;
    if(mar[a]!=-1 && !visited[mar[a]])
        sum = 1+dfs(mar[a]);
    visited[a] = 0;
    return dp[a] = sum;
}


int main(){
    cin>>T;
    loop(x, T){
        cin>>N;
        mar.clear();
        mar.resize(limit, -1);
        memset(visited, 0, sizeof(visited));
        dp.clear();
        dp.resize(limit, -1);
        loop(y, N){
            int a, b;
            cin>>a>>b;
            mar[a] = b;
        }
        int maxS = -1;
        int ans = -1;
        loop(y, N){
            int temp;
            if(dp[y+1]!=-1) temp = dp[y+1];
            else temp = dfs(y+1);
  
            if(maxS < temp){
                maxS = temp;
                ans = y+1;
            }
        }
        printf("Case %d: %d\n", x+1, ans);
    }
}