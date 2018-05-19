// Pseudo-Random numbers

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

int Z, I, M, L;

int f(int l){
    return (Z*l+I)%M;
}

int floydCycleFinding(int l){
    // 1st: finding k*mu
    int tortoise = f(l), hare = f(f(l));
    while(tortoise != hare){
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    // 2nd: finding mu
    int mu = 0; hare = l;
    while(tortoise != hare){
        tortoise = f(tortoise); hare = f(hare); mu++;
    }
    int lambda = 1; hare = f(tortoise);
    while(tortoise!=hare){
        hare = f(hare); lambda++;
    }
    return lambda;
}

int main(){
    int ca = 1;
    while(scanf("%d %d %d %d", &Z, &I, &M, &L)){
        if(Z|I|M|L){
            int cycle = floydCycleFinding(L);
            printf("Case %d: %d\n", ca++, cycle);
        }
        else break;
    }
}