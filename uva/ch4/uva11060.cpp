// Beverages

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

int N, M;
string line;
map<string, int> bevs;
map<int, string> revBev;
bool edges[101][101];
int degrees[101];

class mycomparison
{
public:
  bool operator() (const int& lhs, const int&rhs) const
  {
    return (lhs>rhs);
  }
};

priority_queue<int, vector<int>, mycomparison> ts;

string bfs(){
    string ans = "";
    int cnt = 0;
    loop(x, N){
        if(degrees[x]==0){
            ts.push(x);
        }
    }
    while(!ts.empty()){
        int v = ts.top();
        ts.pop();
        ans += " "+revBev[v];
        cnt++;
        loop(x, N){
            if(edges[v][x]){
                degrees[x]--;
                if(degrees[x]==0)
                    ts.push(x);
            }
        }
    }
    return ans;
}
int main(){
    int caseNum = 1;
    while(getline(cin, line)){
        revBev.clear();
        bevs.clear();
        memset(edges, 0, sizeof(edges));
        memset(degrees, 0, sizeof(degrees));
        N = stoi(line);
        loop(x, N){
            getline(cin, line);
            bevs[line] = x;
            revBev[x] = line;
        }
        getline(cin, line);
        M = stoi(line);
        loop(x, M){
            getline(cin, line);
            stringstream ss(line);
            string first, second;
            ss>>first>>second;
            if(!edges[bevs[first]][bevs[second]]){
                edges[bevs[first]][bevs[second]] = 1;
                degrees[bevs[second]]++;
            }
        }
        string ans = bfs();

        printf("Case #%d: Dilbert should drink beverages in this order:%s.\n\n", caseNum, ans.c_str());
        caseNum++;
        getline(cin, line);
    }
}