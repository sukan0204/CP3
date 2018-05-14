// Sum of Consecutive Prime Numbers

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

vi prime;
vi primesum;

void genPrime(){
    primesum.push_back(0);
    for(int i=2;i<=10000;i++){
        bool isprime = true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0) isprime = false;
        }
        if(isprime){
            prime.push_back(i);
            int last = primesum.back();
            primesum.push_back(last+i);
        }
    }
}
int n;
int main(){
    genPrime();
    while(scanf("%d", &n)&&n!=0){
        int count = 0;
        for(int i=1;i<primesum.size();i++){
            if(primesum[i]-primesum[i-1]>n) break;
            for(int j=0;j<i;j++){
                if(n==primesum[i]-primesum[j]){
                    count++;
                }
            }

        }
        cout<<count<<endl;
    }
}