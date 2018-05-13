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

int N;
int ar[12];
string line;
int main(){
    getline(cin, line);
    N = stoi(line);

    loop(x,N){
        memset(ar, 0, sizeof(ar));
        getline(cin, line);
        stringstream ss(line);
        int n, i;
        i = 0;
        while(ss>>n){
            ar[i++] = n;
        }
        sort(ar, ar+i);
        int ans = ar[i/2];
        printf("Case %d: %d\n", x+1, ans);
    }
}