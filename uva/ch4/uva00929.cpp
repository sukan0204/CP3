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

int T;
int N, M;
int maze[1000][1000];

int dijkstra();

int main(){
    cin>>T;
    while(T--){
    cin>>N>>M;
   // printf("N: %d M: %d\n", N, M);
    loop(x,N){
        loop(y, M){
            cin>>maze[x][y];
        }
    }
    cout<<dijkstra()<<endl;
    }
    return 0;
}

int twodTo1d(int x, int y){
    return x*M+y;
}

ii onedTo2d(int z){
    int y = z%M;
    int x = z/M;
    return ii(x,y);
}

priority_queue<ii, vector<ii>, greater<ii>> pq; 
vi dist;
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};
int dijkstra(){
    pq.push(ii(maze[0][0], twodTo1d(0,0)));
    dist.clear();
    dist.resize(N*M, INT_MAX);
    dist[0] = maze[0][0];
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if(d>dist[u]) continue;
        int x = onedTo2d(u).first;
        int y = onedTo2d(u).second;
        for(int i=0;i<4;i++){
            int newX = x+X[i];
            int newY = y+Y[i];
            int newZ = twodTo1d(newX, newY);
         //   cout<<newZ<<endl;
            if(newX>=0&&newX<N&&newY>=0&&newY<M){
                if(dist[u] + maze[newX][newY]<dist[newZ]){
                 //   printf("x: %d y: %d\n", newX, newY);
                    dist[newZ] = dist[u] + maze[newX][newY]; 
                   // printf("Z: %d dist: %d\n", newZ, dist[newZ]);
                    pq.push(ii(dist[newZ], newZ));
                }
            }
        }
    }
    int finalZ = twodTo1d(N-1, M-1);
    return dist[finalZ];
}