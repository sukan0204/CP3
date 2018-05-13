// Bubble Sort

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


int k;
int a;
ll ans[100001];

int main(){
    scanf("%d", &k);
    clr(ans);
    ans[1] = 0;
    for(int i=2;i<=100000;i++){
        ans[i] = ans[i-1]+(i-1);
    }
    loop(x,k){
        scanf("%d", &a);
        if(ans[a]%2==0)
        printf("Case %d: %lld\n", x+1, ans[a]/2);
        else
        printf("Case %d: %lld/2\n", x+1, ans[a]);
        
    }

}

