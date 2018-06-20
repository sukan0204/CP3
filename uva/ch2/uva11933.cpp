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
#define EPS 1.0E-3

int main(){
    int d;
    
    while(cin>>d&&d!=0){
        int a, b; a=b=0;
        bool odd = true;
        for(int i=0;i<32;i++){
            
            if(d&(1<<i)){
                if(odd) a|=(1<<i);
                else b|=(1<<i);

                odd = !odd;
            }

        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}