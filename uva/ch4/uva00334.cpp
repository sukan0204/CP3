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

int tc=1;
int nc, nm;
set<string> events;
map<string, int> eventIds;
map<int, string> revIds;
vector<vector<string>> edges;
vector<vi> realEdges;
int key=0;

void constructGraph();
void solve();

int main(){
    while(true){
        cin>>nc;
        if(nc==0)break;
        key=0;
        events.clear();eventIds.clear();
        revIds.clear();edges.clear();
        while(nc--){
            int ne;
            cin>>ne;
            vector<string> v;
            while(ne--){
                string a;
                cin>>a;
                events.insert(a);
                eventIds[a]=key++;
                revIds[eventIds[a]] = a;
                v.push_back(a);
            }
            edges.push_back(v);
        }
        cin>>nm;
        while(nm--){
            vector<string> message;
            string s1, s2;
            cin>>s1>>s2;
            message.push_back(s1);
            message.push_back(s2);
            edges.push_back(message);
        }
        constructGraph();
        solve();
    }

}

vector<vi> adjMat;

void constructGraph(){
    realEdges.clear();
    realEdges.resize(key);
    adjMat.clear();
    adjMat.resize(events.size(), vector<int>(events.size(), 0));
    for(auto v: edges){
        for(int i=0;i<(int)(v.size())-1;i++){
            string s1 = v[i];
            string s2 = v[i+1];
            int id1 = eventIds[s1];
            int id2 = eventIds[s2];
            realEdges[id1].push_back(id2);
            adjMat[id1][id2] = 1;
        }
    }
}

void solve(){
    for(int k=0;k<events.size();k++){
        for(int i=0;i<events.size();i++){
            for(int j=0;j<events.size();j++){
                adjMat[i][j] |= (adjMat[i][k] & adjMat[k][j]);
            }
        }
    }
    vector<pair<string, string>> sol;
    int cnt = 0;
    for(int i=0;i<(int)(events.size())-1;i++){
        for(int j=i+1;j<events.size();j++){
            if(adjMat[i][j]==0&&adjMat[j][i]==0){
                cnt++;
                sol.push_back(make_pair(revIds[i], revIds[j]));
            }
        }
    }
    if(cnt != 0){
    printf("Case %d, %d concurrent events:\n", tc++, cnt);
    for(int i=0;i<sol.size();i++){
        printf("(%s,%s) ", sol[i].first.c_str(), sol[i].second.c_str());
        if(i==1) break;
    }
    cout<<endl;
    }
    else{
        printf("Case %d, no concurrent events.\n", tc++);

    }


}
