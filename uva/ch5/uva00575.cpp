// Polly the Polynomial

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


ll solve(string str){
    reverse(str.begin(), str.end());
    ll sum = 0;
    int power = 1;
    for(auto c: str){
        double i = c-'0';
        if(c!=0){
            double base = (1<<power)-1;
            sum += i*base;
        }
        power++;
    }
    return sum;
}

string line;

int main(){
   while(getline(cin, line)){
       if(line.size()==1&&line[0]=='0') break;
       cout<<solve(line)<<endl;
   }
    
}

