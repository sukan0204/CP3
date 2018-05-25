// Triangle Wave

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

int N;
int A, F;

void solve();

int main(){
    cin>>N;
    while(N--){
        cin>>A>>F;
        while(F--){
            solve();
            if(N!=0||F!=0)
            cout<<endl;
        }
    }
}

void solve(){
    for(int i=1;i<=A;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
    for(int i=A-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
}