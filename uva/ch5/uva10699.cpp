// Count the factors

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
#define INF 1000000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

int sieves[100000];
vi primes;

void solve();

void sieve(int size);

string line;
int n;
int main(){
    sieve(2000);
    while(cin>>n&&n!=0){
        solve();
    }
    return 0;
}

void sieve(int size){
    clr(sieves);
    primes.push_back(2);
    for(int i=3;i<=size;i+=2){
        if(sieves[i]==0){
            primes.push_back(i);
            for(int j=i*3;j<=size;j+=2*i){
                sieves[j] = 1;
            }
        }
    }
}

void solve(){
    set<int> factors;
    int nn = n;
    int i=0;
    while(i<primes.size()&&primes[i]*primes[i]<=nn){
            if(nn%primes[i]==0){
                nn/=primes[i];
                factors.insert(primes[i]);
            }
            else{
                i++;
            }
    }
    if(nn>=2) factors.insert(nn);
    printf("%d : %d\n", n, factors.size());
}