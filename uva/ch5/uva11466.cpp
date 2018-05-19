// uva11466.cpp Largest Prime Divisor

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

ll n;
int sieves[10000001];
vi primes;

void solve();
void sieve(int size);

int main(){
    sieve(10000000);
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
    set<ll> factors;
    int i=0;
    n = abs(n);
    while(i<primes.size()&&primes[i]*primes[i]<=n){
            if(n%primes[i]==0){
                n/=primes[i];
                factors.insert(primes[i]);
            }
            else{
                i++;
            }
    }
    if(n!=1) factors.insert(n);
    if(factors.size()<=1){
        cout<<-1<<endl;
        return;
    }    
    cout<<*factors.rbegin()<<endl;
    return;
}