// Factovisors

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

int sieves[35000];
vi primes;

void solve();

void sieve(int size);

string line;
ll m, n;
int main(){
    sieve(32768);
    while(getline(cin, line)){
        stringstream ss(line);
        ss>>m>>n;
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
    ll prev = -1; int leftCount = 0;
    bool divisible = true;
    for(int i=0;i<factors.size();i++){
        ll current = factors[i];
        if(prev == current){
            leftCount--;
        }
        else{
            leftCount = 0;
            ll curpower = current;
            while(curpower<=m){
                leftCount += m/curpower;
                curpower *= current;
            }
            leftCount--;
        }
        if(leftCount<0){
        divisible = false;
        break;
        }
        prev = current;
    }
    if(divisible){
        printf("%lld divides %lld!\n", n, m);
    }    
    else{
        printf("%lld does not divide %lld!\n", n, m);
    }
}