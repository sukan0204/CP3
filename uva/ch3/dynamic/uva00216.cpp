// Getting in line
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

double len(pi a, pi b){
    double dist = pow(a.first-b.first, 2.0)+pow(a.second-b.second, 2.0);
    dist = sqrt(dist)+16;
    return dist;
}
int N;
int x, y;
vector<pi> pv;

double dp[10][(1<<10)-1];
double dist[10][10];
string str[10][10];
int nextP[10][(1<<10)-1];

double solve(int pos, int mask){
    if(mask == (1<<N)-1){
        return dp[pos][mask]=0;
    }
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
    double minV = -1;
    double minI = -1;
    loop(a, N){
        if(a!=pos&&(mask&(1<<a))==0){
            if(minV==-1){
                minV = dist[pos][a] + solve(a, mask | (1<<a));
                minI = a;
            }
            else{
                double temp = dist[pos][a]+solve(a, mask | (1<<a));
                if(minV>temp){
                    minV = temp;
                    minI = a;
                }
            }
        }
    }
    nextP[pos][mask] = minI;
    return dp[pos][mask] = minV;
    
}

void answer(){
    loop(a, pv.size()){
        loop(b, pv.size()){
            dist[a][b] = len(pv[a], pv[b]);
        }
    }
    int minPos= N+10;
    double minV = -1;
    loop(a, N){
        if(minV == -1){
            minPos = a;
            minV = solve(a, (1<<a));
        }
        else{
            double temp = solve(a, (1<<a));
            if(minV>temp){
                minV = temp;
                minPos = a;
            }
        }
    }
    int mask = (1<<minPos);
    int currPos = minPos;
    while(mask != (1<<N)-1){
        int nextPPos = nextP[currPos][mask];
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", pv[currPos].first, pv[currPos].second, pv[nextPPos].first, pv[nextPPos].second, dist[currPos][nextPPos]);
        currPos = nextPPos;
        mask|=(1<<nextPPos);
    }
    printf("Number of feet of cable required is %.2f.\n", minV);
}
int main(){
    int i=1;
    while(true){
        pv.clear();
        memset(dist, -1, sizeof(dist));
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<(1<<N);j++){
                dp[i][j]=-1;
            }
        }
        if(N==0)break;
        loop(i, N){
            cin>>x>>y;
            pv.push_back(pi(x,y));
        }
        cout<<"**********************************************************"<<endl;
        printf("Network #%d\n", i++);
        answer();
    }
    return 0;
}