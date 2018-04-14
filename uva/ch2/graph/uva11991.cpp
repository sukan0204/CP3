// Easy Problem from ...

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

vector<int> adj[1000010];
int n,m,k,v;
int d;

int main(){
    while(cin>>n){
    cin>>m;
    for(int i=0;i<1000010;i++){
        adj[i].clear();
    }
    for(int i=1;i<=n;i++){
        cin>>d;
        adj[d].push_back(i);
    }
    while(m--){
        cin>>k>>v;
        vector<int> &vi = adj[v];
        if(vi.size()<k){
            cout<<"0"<<endl;
        }
        else{
            cout<<vi[k-1]<<endl;
        }
    }
    }
    return 0;
}
