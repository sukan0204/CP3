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
< expression > := < component > | < component > + < expression >
< component > := < f actor > | < f actor > * < component >
< f actor > := < positiveinteger > | (< expression >)
*/

int N;

int error = -1;

int checkFactor(string line);
int checkComponent(string line);
int checkExpression(string line);
void solve(string line);

int main(){
    string line;
    getline(cin, line);
    N = stoi(line);
    while(N--){
        getline(cin, line);
        solve(line);
    }
}

int checkFactor(string line){
    if(line.length()==0) return error;
    if(line[0]=='('&&line[line.length()-1]==')'){
        string subs = line.substr(1, line.length()-2);
        return checkExpression(subs);
    }
    for(auto c: line){
        if(c<'0'||c>'9'){
            return error;
        }
    }
    return stoi(line);
}
int checkComponent(string line){
    if(line.length()==0) return error;
    int idx = line.find('*');
    while(idx!=string::npos){
    int lparenCount = count(line.begin(), line.begin()+idx, '(');
    int rparenCount = count(line.begin(), line.begin()+idx, ')');
    if(lparenCount==rparenCount) break;
    idx = line.find('*', idx+1); 
    }

    if(idx == string::npos) return checkFactor(line);

    string first = line.substr(0, idx);
    string second = line.substr(idx+1, line.length()-idx);
    int firstValue = checkFactor(first);
    int secondValue = checkComponent(second);
    if(firstValue==error||secondValue==error) return error;
    return firstValue*secondValue;
}

int checkExpression(string line){
    if(line.length()==0) return error;
    int idx = line.find('+');
    while(idx!=string::npos){
    int lparenCount = count(line.begin(), line.begin()+idx, '(');
    int rparenCount = count(line.begin(), line.begin()+idx, ')');
    if(lparenCount==rparenCount) break;
    idx = line.find('+', idx+1); 
    }

    if(idx == string::npos) return checkComponent(line);

    string first = line.substr(0, idx);
    string second = line.substr(idx+1, line.length()-idx);
    int firstValue = checkComponent(first);
    int secondValue = checkExpression(second);
    if(firstValue==error||secondValue==error) return error;
    return firstValue+secondValue;
}
void solve(string line){
    int ans = checkExpression(line);
    if(ans == -1) cout<<"ERROR"<<endl;
    else cout<<ans<<endl;
}