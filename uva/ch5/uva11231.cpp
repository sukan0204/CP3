// Black and white painting

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
#define INF 100000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))


int n, m, c;

int solve(int n, int m, int c){
    if(n<8||m<8)
        return 0;
    int ans = (n-7)*(m-7)/2;
    if(c==1&&m%2==0&&n%2==0)
        ans+=1;
    return ans;
}

int main(){
    while(scanf("%d %d %d", &n, &m, &c)!=EOF&&(n!=0||m!=0||c!=0)){
        cout<<solve(n, m, c)<<endl;
    }
  
}

