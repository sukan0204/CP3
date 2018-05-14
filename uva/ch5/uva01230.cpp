// MODEX

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

int c;
int x, y, n;
int mode(int x, int y, int n){
    int logtwo = (int)log2(y);
    vi two;
    int mod = x%n;
    two.push_back(mod);
    for(int i=1;i<=logtwo;i++){
        int bac = two.back();
        mod = (bac*bac)%n;
        two.push_back(mod);
    }
    int answer = 1;
    while(y!=0){
        int ylog = (int)log2(y);
        y-=pow(2.0, ylog);
        answer = answer*two[ylog];
        answer %= n;
    }
    return answer;
}
int main(){
    scanf("%d", &c);
    loop(i, c){
        scanf("%d %d %d", &x, &y, &n);
        cout<<mode(x, y, n)<<endl;
    }
}