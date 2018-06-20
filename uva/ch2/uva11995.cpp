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
#define EPS 1.0E-3

// stack, queue, priority queue, impossible, not sure
int n;

int main(){
    while(cin>>n){
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        bool isSt, isQ, isPQ; isSt = isQ = isPQ = true;

        int a, b;
        while(n--){
            cin>>a>>b;
            if(a==1){ st.push(b), q.push(b), pq.push(b); }
            else if(st.empty()){
                isSt = isQ = isPQ = false;
                continue;
            }
            else{ 
                if(st.top()!=b){ isSt = false; }
                st.pop();
                if(q.front()!=b) { isQ = false; }
                q.pop();
                if(pq.top()!=b) { isPQ = false; }
                pq.pop();
            }
        }
        if((isSt&&isQ)||(isSt&&isPQ)||(isQ&&isPQ)){
            cout<<"not sure"<<endl;
        }
        else if(isSt){
            cout<<"stack"<<endl;
        }
        else if(isQ){
            cout<<"queue"<<endl;
        }
        else if(isPQ){
            cout<<"priority queue"<<endl;
        }
        else{
            cout<<"impossible"<<endl;
        }
    }
    return 0;
}