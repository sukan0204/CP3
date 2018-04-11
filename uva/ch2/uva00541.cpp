// Stack
// Rails

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
string line;
bool checked[1010];
void answer(string line){
    memset(checked, 0, sizeof(checked));
    stringstream ss(line);
    string buf;
    vector<int> v;
    while(ss >> buf){
        v.push_back(stoi(buf));
    }
    stack<int> st;
    auto it = v.begin();
    int current;
    bool possible = true;
    while(it!=v.end()){
        current = *it;
        it++;
        if(st.empty() || st.top() < current){
            checked[current] = true;
            for(int a = 1;a<current;a++) 
                if(checked[a] == false) 
                    st.push(a);
            continue;
        }
        if(st.top() == current){
            checked[current] = true;
            st.pop();
        }
        else{
            possible = false;
            break;
        }


    }
    if(possible) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    while(true){
        getline(cin, line);
        N = stoi(line);
        if(N==0) break;

        while(true){
            getline(cin, line);
            if(line == "0") break;

            answer(line);
        }
        cout<<endl; 
    }
}