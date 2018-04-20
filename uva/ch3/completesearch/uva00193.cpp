// Graph Coloring

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
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

bool edges[101][101];
int m;
int n, k;
int a, b;
int maxSum = 0;
bitset<101> maxBit;

void answer(bitset<101> b, int index=1){
    if(index>n){
        if(b.count()>maxSum){
            maxSum = b.count();
            maxBit = b;
        }
        return;
    }
    bool canSet = true;
    for(int i = 1; i <= n; i++){
        if(edges[index][i] && b.test(i)){
            canSet = false;
        }
    }
    if(canSet){
        b.set(index, 1);
        answer(b, index + 1);
    }
    b.set(index, 0);
    answer(b, index + 1);
    
}

int main(){
    cin>>m;
    while(m--){
        maxSum = 0;
        memset(edges, 0, sizeof(edges[0][0]) * 101 * 101);
        cin>>n>>k;
        while(k--){
            cin>>a>>b;
            edges[a][b] = 1;
            edges[b][a] = 1;

        }
        answer(bitset<101>());
        cout<<maxSum<<endl;
        bool first = true;
        for(int i=1;i<=n;i++){
            if(maxBit.test(i)){
                if(!first)
                    cout<<" ";
                cout<<i;
                first = false;
            }
        }
        cout<<endl;  
    }
    return 0;
}