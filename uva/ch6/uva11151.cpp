// Longest Palindrome

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

int tc;
string line;

int solve();
int main(){
    getline(cin, line);
    tc = stoi(line);
    while(tc--){
        getline(cin, line);
        cout<<solve()<<endl;
    }
}

int dp[1010][1010];
int solve(){
    clr(dp);
    for(int i=0;i<line.length();i++){
        dp[i][i] = 1;
        if(i>0)
            dp[i-1][i] = ((line[i-1]==line[i])?2:1);
    }
    for(int i=2;i<line.length();i++){
        for(int j=0;j<line.length()-i;j++){
            if(line[j]==line[j+i]){
                dp[j][j+i] = dp[j+1][j+i-1]+2;
            }
            else{
                dp[j][j+i] = max(dp[j][j+i-1], dp[j+1][j+i]);
            }

        }
    }

    return dp[0][line.length()-1];
}