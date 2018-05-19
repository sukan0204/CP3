// Cows and Cars

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

int ncows, ncars, nshow;

int main(){

// ncows/n*ncars/(n-1-nshow) + ncars/n*(ncars-1/n-1-nshow)
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        ss>>ncows>>ncars>>nshow;
        int n = ncows+ncars;
        double prob = 1.0*ncows/n*(1.0*ncars/(n-1-nshow));
        prob += 1.0*ncars/n*(1.0*(ncars-1)/(n-1-nshow));
        printf("%.5f\n", prob);
    }
}