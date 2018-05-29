// Vacation

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

int dp[110][110];
string a, b;
int solve();

int main(){
    int c = 1;
    while(getline(cin, a)){
        if(a.length()==1&&a[0]=='#') break;
        getline(cin, b);
     //   cout<<a<<endl;
     //   cout<<b<<endl;
        printf("Case #%d: you can visit at most %d cities.\n", c++, solve());
    }
}

// longest sequence
int solve(){
    clr(dp);
    for(int i=0;i<=a.length();i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=b.length();j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            dp[i][j] = max(dp[i-1][j-1]+(a[i-1]==b[j-1]?1:0), dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        //    printf("i: %d j: %d %d\n", i, j, dp[i][j]);
        }
    }
    return dp[a.length()][b.length()];
}