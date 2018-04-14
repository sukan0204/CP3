// CD

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

int N, M;
int d;
int main(){
    set<int> s;
    while(true){
    s.clear();
    cin>>N>>M;
    if(N==0&&M==0) break;
    while(N--){
        cin>>d;
        s.insert(d);
    }
    int count = 0;
    while(M--){
        cin>>d;
        if(s.find(d)!=s.end()){
            count++;
        }
    }
    cout<<count<<endl;
    }
    return 0;
}