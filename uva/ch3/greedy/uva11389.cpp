//the trip


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

string line;
int morning[110];
int evening[110];
int n, d, r;
void answer(){
    sort(morning, morning + n);
    sort(evening, evening + n);
    int sum = 0;
    for(int i=0;i<n;i++){
        int both = morning[i] + evening[n-i-1];
        if(both>d)
            sum += both-d;
    }
    cout<<sum*r<<endl;
}
int main(){
    
    while(true){
        getline(cin, line);
        sscanf(line.c_str(), "%d %d %d", &n, &d, &r);
        if(n==0) break;
        getline(cin, line);
        stringstream ss(line);
        loop(x, n){
            ss>>morning[x];
        }
        getline(cin, line);
        ss = stringstream(line);

        loop(x, n){
            ss>>evening[x];

        }
        answer();
    }
 
    return 0;
}