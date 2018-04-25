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


int M, N;
char lands[30][30];
string line;
int x, y;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

int floodfill(int r, int c, char c1, char c2){
    if(r<0 || r>=M) return 0;
    if(c<0) c = N-1;
    if(c>=N) c = 0;
    if(lands[r][c] == c2) return 0;
    int ans = 1;
    lands[r][c] = c2;
    for(int d = 0; d<4;d++){
        ans += floodfill(r+dr[d], c+dc[d], c1, c2);
    }
    return ans;
}

int main(){
    while(getline(cin, line)){
        stringstream ss(line);
        ss>>M>>N;
        loop(i, M){
            getline(cin, line);
            loop(j, N){
                lands[i][j]=line[j];
            }
        }
        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss>>x>>y;
        char c1 = lands[x][y];
        char c2=0;
        loop(i, M)loop(j,N){
            if(lands[i][j]!=c1){
                c2 = lands[i][j];
                break;
            }
        }
        if(c2==0) {
            c2 = c1=='a'?'b':'a';
        }
        floodfill(x,y,c1,c2);
      //  cout<<"ff:"<<floodfill(x,y, c1, c2)<<endl;
        int ans = 0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(lands[i][j]!=c2)
                ans = max(ans, floodfill(i,j, c1, c2));
            }
        }
        cout<<ans<<endl;
        getline(cin, line);
    }
}