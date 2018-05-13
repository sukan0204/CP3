// 3n+1 problem

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

#define SIZE 10001
int a, b;
int ar[SIZE];

void compute();
void solve();

int main(){
    clr(ar);
    compute();
    while(scanf("%d %d", &a, &b) != EOF){
        solve();
    }
}

int getCycle(ll i){
  //  cout<<i<<endl;
  //  if(i<0)
    //    cout<<i<<endl;
    if(i<SIZE&&ar[i]!=0) return ar[i];
    if(i==1) return 1;
    
    if(i%2==0){
        return 1 + getCycle(i/2);
    }
    else{
        return 1 + getCycle(3*i+1);
    }
}

void compute(){
    for(int i=1;i<SIZE;i++){
        ar[i] = getCycle(i);
    }
}

void solve(){
   int small = min(a, b);
   int large = max(a, b);
   int bestLen = 0;
   for(int i = small;i<=large;i++){
       bestLen = max(bestLen, getCycle(i));
   }
   printf("%d %d %d\n", a, b, bestLen);
}