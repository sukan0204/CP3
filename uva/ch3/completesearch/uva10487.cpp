// Closest Sums

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

int n, m;
int q;
int ar[1010];
int sums[5000000];
int t = 0;
int c = 1;

void preprocess(){
    t = 0;
    
    loop(x, n-1){
        for(int i = x+1;i<n;i++){
            sums[t++] = ar[x] + ar[i];
        }
    }
    sort(sums, sums+t);

}
void bs(int key){
    int lo = 0;
    int hi = t-1;
    int mid;
    int best = 0;

    while(lo<=hi){
        mid = lo + (hi-lo)/2;
        if(sums[mid]<key)
            lo = mid + 1;
        else if(sums[mid]>key)
            hi = mid - 1;
        else{
            best = mid;
            break;
        }
        if(abs(sums[mid]-key)<abs(sums[best]-key))
            best = mid;
    }
    printf("Closest sum to %d is %d.\n", key, sums[best]);
}
void answer(){
    bs(q);
}
int main(){
    
    while(true){
        cin>>n;
        if(n==0) break;
        loop(x, n){
            cin>>ar[x];
        }
        cin>>m;
        preprocess();

        printf("Case %d:\n", c);
        while(m--){
            cin>>q;
            answer();
        }
        c++;
    }
    return 0;


}