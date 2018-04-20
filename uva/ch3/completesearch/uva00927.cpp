// UVa 00927 Integer Sequence from

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
using namespace std;

#define loop(x,n) for(int x = 0;x < n; ++x)

typedef uint64_t ll;

int N, cn;
int C[100] = {0};
int d, k;
ll answer;

int findN(int d, int k){
    int n = 1;
    int dd = d;
    while(dd<k){
        n++;
        dd += n*d;
    }
    return n;
}

int main(){
    cin>>N;
    while(N--){
        cin>>cn;
        loop(x, cn + 1){
            cin>>C[x];
        }
        cin>>d>>k;
        int n = findN(d, k);
        answer = 0;
        loop(x, cn + 1){
            ll power = pow(n*1.0, x);
            answer += C[x]*power;
        }
        cout<<answer<<endl;

    }

}