// Argus

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

struct query {
    int id;
    int time;
    int period;
    query(int _id, int _time, int _period): id(_id), time(_time), period(_period){}
};

class Compare {
    public:
    bool operator()(query& o1, query& o2)
    {   
        if(o1.time == o2.time)
            return o1.id > o2.id;
        return o1.time > o2.time;
    }
};

int id, period, K;
string line;
priority_queue<query, vector<query>, Compare> pq;
query top = query(0,0,0);

int main(){
    while(true){
        getline(cin, line);
        if(line=="#") break;
        sscanf(line.c_str(), "Register %d %d", &id, &period);
        query q(id, period, period);
        pq.push(q);
    }

    getline(cin, line);
    K = stoi(line);    
    for(int i=0;i<K;i++){
        top = pq.top();
        cout<<top.id<<endl;
        top.time = top.period + top.time;
        pq.pop();
        pq.push(top);
    }
}