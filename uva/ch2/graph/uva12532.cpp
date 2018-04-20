// Interval product

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

int N, K;
int x;
int i, j;
char c;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))
class FenwickTree {
bool * tr;
int n;
private: vi v1;
private: vi ft; // recall that vi is: typedef vector<int> vi; 
public: FenwickTree(int N) { 
    n = N;
    v1.assign(n + 2, 1); ft.assign(n + 2, 1); 
    tr = new bool[4*(n+1)];
    for(int i=0;i<4*(n+1);i++) tr[i] = false;
} // init n + 1 zeroes

bool rq(int node, int l, int r, int start, int end){

    if(l>=start&&r<=end){
        return tr[node];
    }
    if(r<start||l>end)
        return 0;

    int mid = (l + r) / 2;
    bool p1 = rq(2*node, l, mid, start, end);
    bool p2 = rq(2*node+1, mid+1, r, start, end);
    return p1||p2;

}
int rsq(int b) { // returns RSQ(1, b) 
if(b<=0) return 1;
int mul = 1; for (; b; b -= LSOne(b)) mul *= ft[b];
return mul; } // note: LSOne(S) (S & (-S))
int rsq(int a, int b) {
if(rq(1, 1, n, a, b)) return 0;
int aa = rsq(a-1);
return rsq(b) *  aa; 
}

void rangeUpdate(int node, int idx, int val, int start, int end){

    if(start == end){
        tr[node] = (val==0);
        return;
    }
    else{
        int mid = (start + end) / 2;
        // First Half
        if(start <= idx && idx <= mid){
            rangeUpdate(2*node, idx, val, start, mid);
        }
        // Latter Half
        else{
            rangeUpdate(2*node + 1, idx, val, mid+1, end);
        }
    }
    tr[node] = (tr[2*node]||tr[2*node+1]);
}

void build(int k, int v){
    rangeUpdate(1,k,v,1,n);

    if(v>=0) v=1;
    if(v<0) v=-1;

    if(v1[k]!=v){
            v1[k] = v;

    for (; k < (int)ft.size(); k += LSOne(k)) {
        ft[k] *= -1;
    }
    }

}

};
     
int main(){
    while(cin>>N){
        cin>>K;
        FenwickTree ft(N);
        for(int i=0;i<N;i++){
            cin>>x;
            ft.build(i+1, x);
        }
      
        while(K--){
            cin>>c>>i>>j;
  
            if(c=='C'){
                ft.build(i, j);

            }
            else{
                int a = ft.rsq(i, j);

                char c = (a>0?'+':(a==0)?'0':'-');
                cout<<c;
            }
        }
        cout<<endl;
  


    }

}