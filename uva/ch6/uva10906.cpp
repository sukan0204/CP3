// Strange Integration

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

/*
< expr > → < expr > + < term >
< expr > → < term >
< term > → < term > ∗ < factor >
< term > → < factor >
< factor > → (< expr >)
*/

int T;
int n;
vector<string> sv;
void solve(int i);

int main(){
    string line;
    getline(cin, line);
    T = stoi(line);
    loop(x, T){
        sv.clear();
        getline(cin, line); 
        n = stoi(line);
        loop(y, n){
            getline(cin, line);
            sv.push_back(line);
        }
        solve(x+1);
    }
}

#define valType pair<string, bool>

map<string, valType> expr;

void solve(int a){
    string s = "";
    expr.clear();
    for(int i=0;i<sv.size();i++){
        stringstream ss(sv[i]);
        string s, assign, first, op, second;
        ss>>s>>assign>>first>>op>>second;
        string valString = "";
        bool isPlus = op[0]=='+';
        if(expr.find(first)==expr.end()){
            valString += first;
        }
        else{
            if(expr[first].second == true && !isPlus)
            valString += "("+expr[first].first+")";
            else
            valString += expr[first].first;
        }
        valString += op[0];
        if(expr.find(second)==expr.end()){
            valString += second;
        }
        else{
            if(!isPlus || (isPlus && expr[second].second == true))
            valString += "("+expr[second].first+")";
            else
            valString += expr[second].first;
        }
        expr[s] = make_pair(valString, isPlus);
        if(i == sv.size()-1)
            printf("Expression #%d: %s\n", a, valString.c_str());
    }
}