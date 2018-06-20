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
#define EPS 1.0E-3

string line;

int nums[30];
vector<char> v;

int main(){
    int tc=1;
    while(getline(cin, line)&&line!="end"){
        v.clear();
        for(char c: line){
            int index = -1; 
            for(int i=0;i<v.size();i++){
                if(v[i]>=c&&(index==-1||v[index]>=v[i])){
                    index = i;
                }
            }
            if(index==-1){
                v.push_back(c);
            } else{
                v[index] = c;
            }
           // cout<<index<<" "<<c<<endl;

        }
        printf("Case %d: %lu\n",tc++, v.size());
    }
    return 0;
}