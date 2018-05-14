// Count on Cantor

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

#define MAX 10000010

int n;
vi ar;
void init(){
    ar.push_back(1);
    int sum = 1;
    int k = 1;
    while(sum < MAX){
        sum+=k;
        ar.push_back(sum);
        k++;
    }
}

void solve(int a){
    int j = 0;
    for(int i=0;i<ar.size();i++){
        if(a<ar[i]){
            j = i;
            break;
        }
    }
    int n = ar[j-1];
    if(j%2==0){
    int b = a-n+1;
    int c = j-b+1;
    printf("TERM %d IS %d/%d\n", a, b, c);
    }
    else{
    int b = j-a+n;
    int c = j-b+1;
    printf("TERM %d IS %d/%d\n", a, b, c);        
    }
}

int main(){
    init();
    while(scanf("%d", &n)!=EOF){
        solve(n);
    }
  
}

