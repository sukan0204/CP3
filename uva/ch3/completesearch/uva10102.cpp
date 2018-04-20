// The path in the colored field 

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

#define loop(x,n) for(int x = 0;x < n; ++x)

int M;
string* sar;

int main(){
    vector<pair<int, int>> v1, v2;
    while(cin>>M){
        sar = new string[M];
        v1.clear();
        v2.clear();
        loop(x, M){
            cin>>sar[x];
            loop(y,M){
                if(sar[x][y]=='3')
                    v1.push_back(pair<int, int>(x,y));
                if(sar[x][y]=='1')
                    v2.push_back(pair<int, int>(x,y));
            }
        }
        int ans = -1;
        
        for(auto one:v2){
            int count = 2*M+1;
            for(auto three:v1){
                count = min(count, abs(one.first-three.first)+abs(one.second-three.second));
            }
            ans = max(ans, count);
        }
        cout<<ans<<endl;
    }
    return 0;


}