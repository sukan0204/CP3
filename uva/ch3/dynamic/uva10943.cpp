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
#define mod 1000000
int N, K;
int dp[110][110];
int answer(int n, int k){
    if(dp[n][k]!=-1)
        return dp[n][k];
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(k==0){
        return 0;
    }
    int sum = 0;
    for(int i=0;i<=n;i++){
        sum += answer(n-i, k-1);
        sum %= mod;
    }
    return dp[n][k] = sum;
}
int main(){
    memset(dp, -1, sizeof(dp));
    while(true){
        cin>>N>>K;
        if(N==0&&K==0)
            break;
        cout<<answer(N, K)<<endl;
    }
    return 0;
}