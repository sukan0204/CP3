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

int gcd(int a, int b){
    if(a==1||b==1){
        return 1;
    }
    if(a==0||b==0){
        return max(a,b);
    }
    int c = max(a, b);
    int d = min(a, b);
    return gcd(c%d, d);
}

/*
701 1059 1417 2312 0
14 23 17 32 122 0
14 -22 17 -31 -124 0
0
*/
int main(){
    vi num, diff;
    int n;
    while(cin>>n){
        if(n==0) break;
        num.clear();
        diff.clear();
        num.push_back(n);
        while(true){
            cin>>n;
            if(n==0) break;
            num.push_back(n);
        }
        for(int i = 0;i<num.size()-1;i++){
            
            if(num[i]!=num[i+1])
            diff.push_back(abs(num[i]-num[i+1]));
            else
            diff.push_back(abs(num[i]));
        }
        int maxAns = diff[0];
        for(int i=0;i<diff.size();i++){
            maxAns = min(maxAns, gcd(maxAns, diff[i]));
        }
        cout<<maxAns<<endl;
    }

}