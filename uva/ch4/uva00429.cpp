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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define loop(x,n) for(int x = 0;x < n; ++x)
vector<string> dict;
int N;
string word;
string line;

bool edges[210][210];
void constructGraph();
void bfs(string a, string b);
int main(){
    getline(cin, line);
    stringstream ss(line);
    ss>>N;
    bool first = true;
    while(N--){
        dict.clear();
        while(true){
            getline(cin, line);
            stringstream ss(line);
            ss>>word;
            if(word[0]=='*'){
                break;
            }  
            dict.push_back(word);
        }
        constructGraph();
        if(!first) cout<<endl;
        while(getline(cin, line)){
            string a, b;
            if(line[0]=='\0')
                break;
            stringstream ss(line);
            ss>>a>>b;
            bfs(a, b);
        }
        first = false;
    }
}

bool link(string a, string b){
    if(a.length()!=b.length()) return false;
    int diffCnt=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i])
            diffCnt++;
    }
    return diffCnt==1;
}

void constructGraph(){
    memset(edges, 0, sizeof(edges));
    for(int i=0;i<dict.size();i++){
        for(int j=0;j<dict.size();j++){
            if(i!=j&&link(dict[i], dict[j])){
                edges[i][j] = 1;
            }
        }
    }
}

void bfs(string a, string b){
    int idx = find(dict.begin(), dict.end(), a) - dict.begin();
    int num[210];
    fill(num, num+dict.size(),210);
    queue<int> q;
    q.push(idx);
    num[idx] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(dict[cur] == b){
            cout<<a<<" "<<b<<" "<<num[cur]<<endl;
            return;
        }
        for(int i=0;i<dict.size();i++){
            if(edges[cur][i]&&num[i]==210){
                num[i] = num[cur]+1;
                q.push(i);
          
            }
        }
    
    }


}