// Kindergarten Counting Game
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
#include <regex>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define INF 1000000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

int main(){
    string line;
    while(getline(cin, line)){
        smatch m;
        for(int i=0;i<line.length();i++){
            if((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z'))
                continue;
            else
                line[i]=' ';
        }
        regex e("\\b([^ ]*[a-zA-Z]+[^ ]*)\\b");
        int count = 0;
        while(regex_search(line, m, e)){
            line = m.suffix().str();
            count++;
        }
        cout<<count<<endl;
    }
}