// Integer Game

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

int T;
char c;
string s;
int len[3];
int sum;
char win(char turn, char next){    
    if(len[0]==0&&len[1]==0&&len[2]==0)
        return next;
    if(len[sum%3]==0)
        return next;
    if(sum%3==0&&len[sum%3]%2==1)
        return turn;
    else if(sum%3==0)
        return next;
    else{
        len[sum%3]--;
        sum -= sum%3;
        return win(next, turn);
    }
}

int main(){
    cin>>T;
    loop(x,T){
        cin>>s;
        clr(len);
        sum=0;
        for(auto digit: s){
            len[digit%3]+=1;
        }
        sum+=len[1]*1+len[2]*2;
        char c = win('S', 'T');
        printf("Case %d: %c\n",x+1, c);
    }
}