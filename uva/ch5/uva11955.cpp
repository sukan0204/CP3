// Binomial Theorem

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

string a, b, line;
int T;
int n;
vector<vi> binom;
void init();
void solve(int i);
void parse();
int main(){
    getline(cin, line);
    T = stoi(line);
    init();
    loop(x, T){
        getline(cin, line);
        parse();
        solve(x+1);
    }
}

void parse(){
    int pos, pos1, pos2;
    pos = line.find('+');
    a = line.substr(1, pos-1);
    pos1 = line.find(')');
    b = line.substr(pos+1, pos1-pos-1);
    pos2 = line.find('^');
    string N = line.substr(pos2+1,line.size()-pos2);
    n = stoi(N);
}

void init(){
    binom.resize(51);
    binom[1].push_back(1); binom[1].push_back(1);
    for(int i=2;i<=50;i++){
        for(int j=0;j<=i;j++){
            ll sum = 0;
            if(j==0||j==i){
                sum = 1;
            }
            else if(j==i){
                sum = 1;
            }
            else{
                sum = binom[i-1][j-1]+binom[i-1][j];
            }
            binom[i].push_back(sum);
        }
    }
}

void solve(int i){
    string s="";
    char buf[110], buf2[110];
    for(int i=0;i<=n;i++){
        if(i==0){
            if(n==1) sprintf(buf, "%s", a.c_str());
            else sprintf(buf, "%s^%d", a.c_str(), n);
            s+=buf;
        }
        else if(i==n){
            if(n==1) sprintf(buf, "%s", b.c_str());
            else sprintf(buf, "%s^%d", b.c_str(), n);
            s+="+";
            s+=buf;
        }
        else {
            int c, d;
            c = i; d = n-i;
            ll coef = binom[n][i];
            if(d==1){
                sprintf(buf, "%lld*%s*", coef, a.c_str());
            }
            else{
                sprintf(buf, "%lld*%s^%d*", coef, a.c_str(), d);
            }
            if(c==1){
                sprintf(buf2, "%s", b.c_str());
            }
            else{
                sprintf(buf2, "%s^%d", b.c_str(), c);
            }
           s+="+";
           s+=buf;
           s+=buf2;  
        }
        // alpha^2+2*alpha*omega+omega^2
       // s+=buf;
    }
    printf("Case %d: %s\n", i, s.c_str());
}