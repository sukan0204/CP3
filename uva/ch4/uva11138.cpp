// Nuts and Bolts

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

#define MAX_BOLTS 500
#define MAX_NUTS 500

/* global copy of the input data */
int nuts,bolts,V;
vector<vi> AdjList;
int fits[MAX_BOLTS][MAX_NUTS];
void read_input_data(void){
    int n,b;
    scanf("%d%d",&bolts,&nuts);
    V = nuts+bolts+2;
    AdjList.clear();
    AdjList.resize(V);

    for(b=0;b<bolts;b++){
        for(n=0;n<nuts;n++){
        scanf("%d",&fits[b][n]);
        if(fits[b][n])
        AdjList[n].push_back(nuts+b);
        AdjList[nuts+b].push_back(n);
        }
    }
}
/* data used to match nuts with bolts */
int bestmatched;

vi match, vis;
int Aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < (int)AdjList[l].size(); j++) {
        // return 1 if an augmenting path is found // return 0 otherwise
        int r = AdjList[l][j]; // edge weight not needed -> vector<vi> AdjList 
        if (match[r] == -1 || Aug(match[r])) {
        match[r] = l; return 1;
        }
    }
    return 0;
}

void match_bolt2(){
    bestmatched=0;
    int MCBM = 0;
    match.assign(V, -1);
    for(int l=0;l<nuts;l++){
        vis.assign(nuts,0);
        MCBM +=  Aug(l);
    }
    bestmatched = MCBM;
}
int main(){
    int cases,caseno;
    scanf("%d",&cases);
    for(caseno=1;caseno<=cases;caseno++){
        read_input_data();
        match_bolt2();
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",bestmatched);
        printf("can be fitted together\n");
    }
    return 0;
}