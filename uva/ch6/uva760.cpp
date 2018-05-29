// DNA Sequencing
// Get Longest common sequence in lexicographic order

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


#define MAX_N 700
//char T1[MAX_N];
//char T2[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int Phi[MAX_N], PLCP[MAX_N];
int LCP[MAX_N];
string a, b;
string T;
void countingSort(int k){
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for(int i=0;i<n;i++){
        c[i+k<n?RA[i+k]:0]++;
    }
    for(i = sum = 0; i < maxi; i++){
        int t = c[i]; c[i] = sum; sum += t;
    }
    for(i = 0;i<n;i++){
        tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++] = SA[i];
    }
    for(i = 0;i<n;i++)
        SA[i] = tempSA[i];
}

void constructSA(){
    int i, k, r;

    for(k=1;k<n;k<<=1){
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for(i=1;i<n;i++){
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k])?r:++r;
        }
        for(i=0;i<n;i++){
            RA[i] = tempRA[i];
        }
        if(RA[SA[n-1]] == n-1) break;
    }
}

void computeLCP(){
    int i, L;
    Phi[SA[0]] = -1;
    for(i = 1; i<n; i++)
        Phi[SA[i]] = SA[i-1];
    for(i = L = 0; i<n; i++){
        if(Phi[i]==-1){ PLCP[i] = 0; continue;}
        while(T[i+L] == T[Phi[i]+L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for(i=0;i<n;i++)
        LCP[i] = PLCP[SA[i]];
}

void solve(){
    a = a+'$';
    b = b+'#';
    T = a+b;
    n = T.length();
    int i;
    for(i = 0;i<n;i++) {
        RA[i] = T[i];
        SA[i] = i;
    }

    constructSA();
    computeLCP();
    int maxLCP = 1;
    set<string> ans;
  //  for(int i=0;i<n;i++){
  //      printf("SA[%d] %d %s\n", i, SA[i], T.substr(SA[i]).c_str());
  //  }
    for(int i=0;i<n;i++){
        if(LCP[i]>maxLCP){
            if(SA[i]>=a.length()&&SA[i-1]<a.length()){
                ans.clear();
                string sub = T.substr(SA[i], LCP[i]);
                ans.insert(sub);
                maxLCP = LCP[i];
            }
            else if(SA[i]<a.length()&&SA[i-1]>=a.length()){
                ans.clear();
                string sub = T.substr(SA[i], LCP[i]);
                ans.insert(sub);
                maxLCP = LCP[i];
            }
        }
        else if(LCP[i] == maxLCP){
            if(SA[i]>=a.length()&&SA[i-1]<a.length()){
                string sub = T.substr(SA[i], LCP[i]);
                ans.insert(sub);                
            }
            else if(SA[i]<a.length()&&SA[i-1]>=a.length()) {
                string sub = T.substr(SA[i], LCP[i]);
                ans.insert(sub);
            }           
        }
    }
    if(ans.empty()){
        cout<<"No common sequence."<<endl;
    }
    else
    for(auto s: ans){
        cout<<s<<endl;
    }
}

int main(){
    bool first = true;
    while(getline(cin, a)){
        getline(cin, b);
        if(!first) cout<<endl;
       // cout<<a<<endl;
       // cout<<b<<endl;
        solve();
        string line;
        getline(cin, line);
        first = false;
    }
}