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
int N;
ll ar[30010][5];
int coin[]={1,5,10,25,50};

ll answer(int n, int k){
    if(k==0||n<0)
        return 0;
    if(n==0)
        return 1;
    
    if(ar[n][k]!=-1)
        return ar[n][k];
    ar[n][k] = answer(n, k-1) + answer(n-coin[k-1], k);
    return ar[n][k];
    
}
int main(){
    memset(ar, -1, sizeof(ar));
    while(cin>>N){     
        ll ans = answer(N, 5);
        if(ans != 1)
            printf("There are %lld ways to produce %d cents change.\n", ans, N);
        else
            printf("There is only 1 way to produce %d cents change.\n", N);
    }

}