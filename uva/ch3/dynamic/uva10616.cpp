// Divisible Group Sums

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
#define loop(x,n) for(int x = 0;x < n; ++x)

int N, Q;
int d, m;
ll ar[210];
int dp[210][11][21];

ll answer(int index, int n, ll rem){
    if(n==0 && rem == 0){
        return dp[index][n][rem] = 1; 
    }
    if(n==0 && rem !=0){
        return 0;
    }
    if(index>=N){
        return 0;
    }
    if(dp[index][n][rem]!=-1){
        return dp[index][n][rem];
    }
    ll num = ar[index];
    ll newRem = rem + num;
    newRem %= d;
    newRem += d;
    newRem %= d;
    return dp[index][n][rem] = answer(index+1, n, rem) + answer(index+1, n-1, newRem);
}

int main(){
    int t = 1;
    while(true){
        cin>>N>>Q;
        if(N==0&&Q==0) break;
        loop(x, N){
            cin>>ar[x];
        }
        printf("SET %d:\n", t++);
        loop(x,Q){
            memset(dp, -1, sizeof(dp));
            cin>>d>>m;
            int ans = answer(0, m, 0);
            printf("QUERY %lld: %lld\n", x+1, ans);
        }
    }
    return 0;
}