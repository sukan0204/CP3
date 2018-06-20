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

string line;

int main(){
    int tc;
    getline(cin, line); tc = stoi(line);
    map<string, int> s;
    bool first = true;
    getline(cin, line);

    while(tc--){
        s.clear();
        int n = 0;
        while(getline(cin, line)&&!line.empty()){
            n++;
            if(s.find(line)==s.end()) s[line] = 1;
            else { s[line] += 1; }
        }
        if(!first) cout<<endl;
        for (std::map<string,int>::iterator it=s.begin(); it!=s.end(); ++it){
            printf("%s %.4f\n", (it->first).c_str(), it->second*100.0/n);
        }
        first = false;
    }
    return 0;
}