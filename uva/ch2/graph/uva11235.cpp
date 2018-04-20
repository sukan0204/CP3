// Frequent values

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

int n, q;
int num;
int i, j;
int * ar0;
int * tr;
// 
void build(int l, int r, int p){
    if(l == r){
        tr[p] = 1;
    }
    else{
        int pl = 2*p;
        int pr = 2*p+1;
        int mid = (l+r)/2;
        build(l,mid,pl);
        build(mid+1,r,pr);
        int more = max(tr[pl], tr[pr]);

        int middle = 1;
        if(ar0[mid] == ar0[mid+1]){
            int temp = mid-1;
            while(temp>=l&&ar0[temp]==ar0[mid]){
                temp--;
                middle++;
            }
            temp = mid+1;
            while(temp<=r&&ar0[temp]==ar0[mid]){
                temp++;
                middle++;
            }
        }
        tr[p] = max(middle, more);
    }
}
int rq(int node, int l, int r, int start, int end){

    if(l>=start&&r<=end){
        return tr[node];
    }
    if(r<start||l>end)
        return -1;
    //l 0,r 4
    //5,10
    int mid = (l + r) / 2;
    int p1 = rq(2*node, l, mid, start, end);
    int p2 = rq(2*node+1, mid+1, r, start, end);
    int more = max(p1, p2);
    if(p1==-1||p2==-1)
        return more;
    int middle = 1;
    if(ar0[mid] == ar0[mid+1]){
        int temp = mid-1;
        while(temp>=start&&ar0[temp] == ar0[mid]){
            temp--;
            middle++;
        }
        temp = mid+1;
        while(temp<=end&&ar0[temp] == ar0[mid]){
            temp++;
            middle++;
        }
    }
    
    return max(middle, more);

}
int rq(int start, int end){
    int answer = rq(1, 0, n-1, start, end);
    cout<<answer<<endl;
    return answer;
}
int main(){
    while(true){
        cin>>n;
        if(n==0) break;
        cin>>q;
        ar0 = new int[n];
        tr = new int[3*n];
        for(int i=0;i<n;i++){
            cin>>ar0[i];
        }

        build(0, n-1, 1);

        while(q--){
            cin>>i>>j;
            rq(i-1,j-1);
        }

    }

}