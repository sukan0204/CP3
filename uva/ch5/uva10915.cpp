// Factstone Benchmark

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
typedef vector<ll> vi;
typedef pair<int,int> pi;
#define INF 100000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

vi sol;
int start = 1960;
int end = 2160;
int n;

void computeAll(){
    double logSoFar = 0;
    int nSoFar = 1;
    for(ll x=0;x<=(2160-1960)/10;x++){
        double limit = 4*(1<<x);
        while(logSoFar<=limit){
            nSoFar+=1;
            logSoFar += log2(nSoFar);
        }
        sol.push_back(nSoFar-1);
    }
}


int main(){
    computeAll();
    while(scanf("%d", &n)!=EOF&&n!=0){
        int x = (n-1960)/10;
        cout<<sol[x]<<endl;
    }
  
}

