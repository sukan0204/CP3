// Digit Counting

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

#define SIZE 10000
void compute(int i);
void compute2(int i);
void solve(int a);

int a;
set<int> factors;

void factor(int i){
    factors.clear();
    int root = ceil(sqrt(i-1));
    int ii = i-1;
    for(int a=2;a<=root;a++){
        if(ii%a==0){
            factors.insert(a);
        }
    }
}

bool simulate(int coconut, int n){
    int coco = coconut;
    for(int i=1;i<=n;i++){
        coco-=1;
        if(coco%n!=0) return false;
        coco = coco-coco/n;
    }
    if(coco%n==0) return true;
    else return false;
}

void solve(int i){
    int person = -1;
    factor(i);
    for(auto a:factors){
        if(simulate(i, a))
            person = a;
    }
    if(person!=-1)
        printf("%d coconuts, %d people and 1 monkey\n", i, person);
    else
        printf("%d coconuts, no solution\n", i);
}
int main(){
    while(scanf("%d", &a)&&a!=-1){
        solve(a);
    }
}

