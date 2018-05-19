// Divisors

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

int sieves[100010];
vi primes;

void solve();

void sieve(int size);

string line;
ll a, b;
int k;
int main(){
    sieve(100010);
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
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

int factor(ll n){
    vector<ll> factors;
    ll nn = n;
    int i=0;

    while(i<primes.size()&&primes[i]*primes[i]<=nn){
            if(nn%primes[i]==0){
                nn/=primes[i];
                factors.push_back(primes[i]);
            }
            else{
                i++;
            }
    }
    if(nn>=2) factors.push_back(nn);
    sort(factors.begin(), factors.end());
    int divisornum = 1;
    int divisorcount = 0;
    ll prev = -1;
    for(int i=0;i<factors.size();i++){
        ll current = factors[i];

        if(i!=0&&prev != current){
            divisornum *= (divisorcount+1);
            divisorcount = 1;
        }
        else{
            divisorcount+=1;
        }
        prev = current;
      
    }    
    divisornum *= (divisorcount+1);
    return divisornum;
}

void solve(){
    int maxnum = 0;
    int maxcount = 0;
    for(int i=a;i<=b;i++){
        int divcount = factor(i);
        if(maxcount<divcount){
            maxcount = divcount;
            maxnum = i;
        }
    }
    printf("Between %lld and %lld, %d has a maximum of %d divisors.\n", a, b, maxnum, maxcount);
}