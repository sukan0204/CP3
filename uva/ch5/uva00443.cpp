// Humble Numbers

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

ll LIMIT = 2000000000;

#define SIZE 5842

int n;
vector<ll> ar;
void init(){
    vi two, three, five, seven;
    ll i2=1, i3=1, i5=1, i7=1;
    while(i2<LIMIT){
        two.push_back(i2);
        i2*=2;
    }
    while(i3<LIMIT){
        three.push_back(i3);
        i3*=3;
    }
    while(i5<LIMIT){
        five.push_back(i5);
        i5*=5;
    }
    while(i7<LIMIT){
        seven.push_back(i7);
        i7*=7;
    }
    for(auto a:two){
        ll mult = a;
        for(auto b:three){
            mult = a*b;
            if(mult>LIMIT) 
            break;
            for(auto c:five){
                mult = a*b*c;
                if(mult>LIMIT) 
                break;
                for(auto d:seven){
                   // mult = a*b*c*d;
                    if(mult*d>LIMIT) 
                        break;
                        ar.push_back(mult*d);
            }
            }
    }
    }
    sort(ar.begin(), ar.end());
}

void solve(int a){
    string ch[4] = {"st", "nd", "rd", "th"};
    string s = "th";
    if(a%100>=10&&a%100<20){
        s = "th";
    }
    else if(a%10>0&&a%10<=3){
        s = ch[a%10-1];
    }
    printf("The %d%s humble number is %lld.\n", a, s.c_str(), ar[a-1]);
}

int main(){
    init();
    while(scanf("%d", &n)!=EOF&&n!=0){
        solve(n);
    }
  
}

