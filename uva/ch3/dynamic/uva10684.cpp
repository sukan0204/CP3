// the jackpot

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

int N;
int ar[10010];
void answer(){
    int maxSum = -1;
    int sum = 0;
    loop(x,N){
        sum += ar[x];
        maxSum = max(maxSum, sum);
        if(sum<0) sum = 0;
    }
    if(maxSum<=0)
        printf("Losing streak.\n");
    else{
        printf("The maximum winning streak is %d.\n", maxSum);
    }
}
int main(){
    while(true){
        cin>>N;
        if(N==0) break;
        loop(x, N){
            cin>>ar[x];
        }
        answer();
    }
 
    return 0;
}