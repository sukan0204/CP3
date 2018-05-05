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
typedef pair<int,int> ii;

#define loop(x,n) for(int x = 0;x < n; ++x)

int n, k;
int T[5];
int floors[100][5];
string line;

void constructGraph();
int solve();
int main(){
    while(getline(cin, line)){
        stringstream s1(line);
        s1>>n>>k;
        memset(T, 0, sizeof(T));
        memset(floors, 0, sizeof(floors));
        getline(cin, line);
        stringstream s2(line);
        loop(x, n){
            s2>>T[x];
        }
        loop(x, n){
            getline(cin, line);
            stringstream s3(line);
            int i;
            while(s3>>i){
                floors[i][x] = 1;
            }
        }
        constructGraph();
        int ans = solve();
        if(ans==INT_MAX){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
            cout<<ans<<endl;
    }
}
// vertex (floor, elevator)
// edge seconds
int twoDTo1(int floor, int elevator){
    return elevator*100+floor;
}
ii oneDToTwo(int num){
    int elevator = num/100;
    int floor = num%100;
    return ii(floor, elevator);
}

int edges[510][510];
void connect(int a, int b, int d){
    edges[a][b] = d;
    edges[b][a] = d;
}
void constructGraph(){
    memset(edges, 0, sizeof(edges));
    for(int j=0;j<n;j++){
        vi sameElevator;
        sameElevator.clear();
        for(int i=0;i<100;i++){
            if(floors[i][j]){
                sameElevator.push_back(twoDTo1(i,j));
            }
        }
        for(int a=0;a<sameElevator.size();a++){
            for(int b=a+1;b<sameElevator.size();b++){
                
                connect(sameElevator[a], sameElevator[b], T[j]*abs(sameElevator[a]-sameElevator[b]));
            }
        }
    }
    vi sameFloor;

    for(int i=0;i<100;i++){
        sameFloor.clear();

        for(int j=0;j<n;j++){
            if(floors[i][j]){
                sameFloor.push_back(twoDTo1(i,j));
            }
        }
        for(int a=0;a<sameFloor.size();a++){
            for(int b=a+1;b<sameFloor.size();b++){
                connect(sameFloor[a], sameFloor[b], 60);
            }
        }
    }
}

vector<int> dist;
priority_queue<ii, vector<ii>, greater<ii>> pq;
int solve(){
    dist.clear();
    dist.resize(100*n, INT_MAX);
    for(int i=0;i<n;i++){
        int a = twoDTo1(0, i);
        if(floors[0,i]){
            dist[a] = 0;
        }
        pq.push(ii(0, a));
    }
    while(!pq.empty()){
        ii front = pq.top(); 
        pq.pop();
        int d = front.first, u = front.second;
        if(d>dist[u]) continue;
        for(int j=0;j<100*n;j++){
            if(edges[u][j]){
                if(dist[u]+edges[u][j]<dist[j]){
                    dist[j] = dist[u]+edges[u][j];
                    pq.push(ii(dist[j],j));
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if(floors[k][i]){
            if(ans>dist[twoDTo1(k, i)])
                ans = dist[twoDTo1(k, i)];
        }
    }
    return ans;
}