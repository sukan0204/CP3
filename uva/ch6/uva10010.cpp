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

int tc;
int r, c;
string grid[55];
int n;
string word;

int dir1[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dir2[8] = {1, 0, -1, 0, 1, -1, 1, -1};

bool findAt(string w, int row, int col, int direction){
    if(w.length()==0) return true;
    if(row<0||row>=r) return false;
    if(col<0||col>=c) return false;
    if(tolower(w[0]) == tolower(grid[row][col]))
        return findAt(w.substr(1, w.length()-1), row+dir1[direction], col+dir2[direction], direction);
    else
        return false;
}

void findWord(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int d=0;d<8;d++){
                if(findAt(word, i, j, d)){
                    cout<<i+1<<" "<<j+1<<endl;
                    return;
                }
            }
        }
    }
}

int main(){
    cin>>tc;
    int otc = tc;
    while(tc--){
        if(tc!=otc-1) cout<<endl;
        cin>>r>>c;
        loop(x,r){
            cin>>grid[x];
        }
        cin>>n;
        while(n--){
            cin>>word;
            findWord();
        }
    }
}