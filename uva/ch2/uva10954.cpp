// Add All

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

int N;
int d;
class Compare {
    public:
    bool operator()(int& o1, int& o2)
    {   
        return o1>o2;
    }
};

priority_queue<int, vector<int>, Compare> pq;
long cost;

int main(){
    while(true){
    cin>>N;
    cost = 0;
    if(N == 0) break;
    while(N--){
        cin>>d;
        pq.push(d);
    }
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += (a+b);
        pq.push(a+b);
    }
    cout<<cost<<endl;
    pq.pop();
    }

}