// what goes up


// 1. LIS(0) = 1 // the base case
//2. LIS(i) = max(LIS(j) + 1), ∀j ∈ [0..i-1] and A[j] < A[i] // the recursive case,
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

int N = 0;
vector<int> ar;
vector<int> L;
vector<int> path;
/*
vector<int> path;
vector<int> lenAr;
vector<vector<int>> pathv;
*/
/*
void answer1(){
    path.resize(ar.size());
    lenAr.resize(ar.size(), -1);
    pathv.resize(ar.size());
    lenAr[0] = 1;
    path[0] = 0;
    int maxLen = -1;
    int maxLast = -1;
    pathv[0].push_back(ar[0]);
    for(int i=1;i<N;i++){
        int len = 1;
        path[i] = i;
        for(int j=0;j<i;j++){
            if(ar[i]>ar[j]&&len<=1+lenAr[j]){
                len = 1 + lenAr[j];
                path[i] = j;
                if(maxLen<=len){
                maxLen = max(maxLen, len);
                maxLast = i;
                }
                pathv[i] = pathv[j];
            }
        }
        pathv[i].push_back(ar[i]);
        lenAr[i] = len;

    }
    cout<<maxLen<<endl;
    cout<<"-"<<endl;


   for(auto i: pathv[maxLast])
        cout<<i<<endl;
}
*/
void answer2(){
    vector<int> L_id;
    int lis = 0, lis_end = 0;
    L.resize(ar.size());
    L_id.resize(ar.size());
    path.resize(ar.size());
    path[0] = 0;
  for (int i = 0; i < N; ++i) {
    int pos = lower_bound(L.begin(), L.begin() + lis, ar[i]) - L.begin();
    L[pos] = ar[i];
    L_id[pos] = i;
    path[i] = pos ? L_id[pos-1]: -1;
    if (pos + 1 > lis) {
      lis = pos + 1;
      lis_end = i;
    }
    }
    cout<<lis<<endl;
    cout<<"-"<<endl;

    stack<int> st;
    st.push(lis_end);
    while(path[lis_end]!=-1){
        st.push(path[lis_end]);
        lis_end = path[lis_end];
    }
    while(!st.empty()){
        cout<<ar[st.top()]<<endl;
        st.pop();
    }
}
int main(){
    int d;
    while(cin>>d){
        ar.push_back(d);
        N++;
    }
    answer2();

    return 0;
}