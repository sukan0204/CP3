//The Maximum Sum


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
int ar[1010];
void answer(){
    bool first = true;
    loop(x, N){
        if(ar[x]!=0){
        if(!first) cout<<" ";
        cout<<ar[x];
        first = false;
        }
    }
    if(first) cout<<"0";
    cout<<endl;
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