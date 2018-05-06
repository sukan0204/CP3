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

#define loop(x,n) for(int x = 0;x < n; ++x)

int N;
int energy[30][30];
int edges[30][30];

void solve(char x, char y);

int main(){
    while(true){
        scanf("%d", &N);
        if(N==0) break;
        memset(energy, 0, sizeof(energy));
        memset(edges, 0, sizeof(edges));
        loop(x,N){
            char a, b, c, d;
            int e;
            scanf(" %c %c %c %c %d", &a, &b, &c, &d, &e);
            int v1 = c-'A';
            int v2 = d-'A';
            int t = a=='Y'?-1:1;
            if(t*edges[v1][v2]==-1) t = 2;
            if(b=='U'){
                edges[v1][v2] = t;
                energy[v1][v2] = e;
            }
            else{
                edges[v1][v2] = t; edges[v2][v1] = t;
                energy[v1][v2] = e; energy[v2][v1] = e;
            }
        }
        char me, prof;
        scanf(" %c %c", &me, &prof);
        solve(me, prof);
    }
}

int inf = 1000000;
int AdjMat1[30][30];
int AdjMat2[30][30];
void solve(char a, char b){
    loop(x, 30){
        loop(y,30){
        AdjMat1[x][y] = inf;
        AdjMat2[x][y] = inf;
        if(edges[x][y]==1){
            AdjMat2[x][y] = energy[x][y];
        }
        if(edges[x][y]==-1){
            AdjMat1[x][y] = energy[x][y];
        }
        if(edges[x][y]==2){
            AdjMat2[x][y] = energy[x][y];
            AdjMat1[x][y] = energy[x][y];

        }
    }}
    loop(x, 30){
        AdjMat1[x][x]=0;
        AdjMat2[x][x]=0;
    }
    // floyd warshall
    for(int k=0;k<30;k++){
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                int can1 = AdjMat1[i][k] + AdjMat1[k][j];
                int can2 = AdjMat2[i][k] + AdjMat2[k][j];
                AdjMat1[i][j] = min(AdjMat1[i][j], can1);
                AdjMat2[i][j] = min(AdjMat2[i][j], can2);
            }
        }
    }
    int start = a-'A'; int end = b-'A';
    int ans = inf;
    char ch = 'A';
    vector<char> all;
    for(int i=0;i<30;i++){
        if(AdjMat1[start][i]!=inf&&AdjMat2[end][i]!=inf){
            int can = AdjMat1[start][i]+AdjMat2[end][i];
            if(ans>can){
                all.clear();
                ans = can;
                ch = 'A'+i;
                all.push_back(ch);
            }
            else if(ans == can){
                ch = 'A'+i;
                all.push_back('A'+i);
            }
        }
    }
    if(ans == inf){
        printf("You will never meet.\n");
    }
    else{
        sort(all.begin(), all.end());
        cout<<ans;
        for(auto c:all){
            cout<<" "<<c;
        }
        cout<<endl;
    }
}