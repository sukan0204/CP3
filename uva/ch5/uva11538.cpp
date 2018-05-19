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

ll m, n;
int main(){
    while(cin>>m>>n){
        if(n==0&&m==0) break;
        ll ans = 0;
        ans = n*(n-1)*m+m*(m-1)*n;
        ll diag = 0;
        ll o = min(n, m);

        diag = (o-1)*o*(2*o-1)/3;
        diag -= (o-1)*o;
        diag += (abs(n-m)+1)*o*(o-1);
        ans = ans + 2*diag;
        cout<<ans<<endl;
    }
}