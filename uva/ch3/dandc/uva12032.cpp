// The monkey and the oiled bamboo

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

int r[100010];
int diff[100010];
int T, n;
int ans;

int temp = 0;
void answer(){
    diff[0] = r[0];
    int maxDiffId = 0;
    int maxDiff = diff[0];
    loop(x, n-1){
        diff[x+1] = r[x+1]-r[x];
        if(maxDiff<diff[x+1]){
            maxDiff = diff[x+1];
            maxDiffId = x+1;
        }
    }
    int k = maxDiff;
    for(int i = maxDiffId;i<n;i++){
        if(diff[i] == k){
            k--;
            continue;
        }
        if(diff[i]>k){
            maxDiff += 1;
            break;
        }
    }

    ans = maxDiff;

}

int main(){
    cin>>T;
    loop(x,T){
        cin>>n;
        loop(y, n){
            cin>>r[y]; 
        }
        answer();
       printf("Case %d: %d\n", x+1, ans);
    }
 
    return 0;
}