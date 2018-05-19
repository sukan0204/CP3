// Twin Primes

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

#define SIZE 20001000
bool sieve[SIZE];


int main(){
    clr(sieve);    
    vi primes;
    vector<pi> answer;
    for(int i=2;i<=SIZE;){
        if(!sieve[i]){
            if(primes.size()>=1){
                int back = primes.back();
                if(i-back==2){
                    answer.push_back(pi(back, i));
                }
            }
            primes.push_back(i);
            
            for(int j=2*i;j<=SIZE;j+=i){
                sieve[j] = 1;
            }
        }
        if(i==2) i+=1;
        else i+=2;
    }
    int n;
    while(cin>>n){
        printf("(%d, %d)\n", answer[n-1].first, answer[n-1].second);
    }
}