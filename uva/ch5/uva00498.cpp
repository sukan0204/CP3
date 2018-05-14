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

vi sol;
vi cv;

string line;
ll solve(ll x){
    long double sum = 0;
    for(int i=cv.size()-1;i>=0;i--){
        sum += cv[i]*pow((long double)x, (long double)cv.size()-i-1);
    }
    return (ll)sum;
}
int main(){
  //  computeAll();
    while(getline(cin, line)){
        cv.clear();
       // cout<<line<<endl;
        stringstream ss(line);
        int c;
        while(ss>>c){
            cv.push_back(c);
        }
        getline(cin, line);
        stringstream ss2(line);
        int x;
        bool first = true;
        while(ss2>>x){
            if(first) cout<<solve(x);
            else cout<<" "<<solve(x);
            first = false;
        }
        cout<<endl;
    }
  
}

