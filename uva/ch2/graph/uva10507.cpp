
// Waking up brain

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

string never = "THIS BRAIN NEVER WAKES UP\n";
string wakeupstr = "WAKE UP IN, %d, YEARS\n";
int wakeup[26];
int N, M;
string line;
int year = 0;
set<char> charset;
set<int> links[26];

void init(){
    for(int i=0;i<26;i++){
        wakeup[i] = -1;
        year = 0;
        links[i].clear();
        links[i].insert(i);
    }
    charset.clear();

}

bool allwake(){
    if(charset.size()<N) return false;
    for(auto c: charset){
        if(wakeup[c-'A']<0)
        return false;
    }
    return true;
}

void connect(char a, char b){
    int aa = a-'A';
    int bb = b-'A';

    set<int> &s1 = links[aa];
    set<int> &s2 = links[bb];
    s1.insert(bb);
    s2.insert(aa);
}

void printSet(set<int> & s){
    for(int i: s){
        cout<<i<<", ";
    }
    cout<<endl;
}

void trywakeup(char a){
    int aa = a-'A';
    if(wakeup[aa]>=0) return;
    set<int> &s = links[aa];
    if(s.size()<4) return;
    int count = 0;
    for(auto i:s){
        if(wakeup[i]<year&&wakeup[i]>=0){
            count++;
        }
    }
    if(count>=3) wakeup[aa] = year;
}

int main(){
    while(getline(cin, line)){
    N = stoi(line);
    init();
    getline(cin, line);
    M = stoi(line);
    getline(cin, line);
    for(char &c: line){
        wakeup[c-'A'] = 0;
        charset.insert(c);
    }
    while(M--){
        getline(cin, line);
        charset.insert(line[0]);
        charset.insert(line[1]);
        connect(line[0], line[1]);
    }
    for(int i=0;i<N && !allwake();i++){
        year++;
        for(char c:charset)
            trywakeup(c);
    }

    if(allwake()) printf(wakeupstr.c_str(), year);
    else printf("%s", never.c_str());
    getline(cin, line);
    }
   return 0;
}

