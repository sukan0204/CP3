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

int k;
int s;
map<int, int> m;
int temp;

int main(){
    scanf("%d", &k);
    while(k--){
        int maxL = 0;
        m.clear();
        scanf("%d", &s);
        int idx = 0;
        int ldx = 0;
        while(s--){
            scanf("%d", &temp);
          //  cout<<ldx<<endl;
            if(m.find(temp)!=m.end()&&m[temp]>ldx) ldx = m[temp];
            m[temp] = ++idx;
            maxL = max(maxL, idx-ldx);
         }
        cout<<maxL<<endl;
    }
}