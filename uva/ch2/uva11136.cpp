// hoax or what

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

int day;
int n,d;
long sum = 0;
int mn, mx;
int main(){
    multiset<int> s;
    while(true){
    sum=0;
    mn = mx = 0;
    s.clear();
    cin>>day;
    if(day == 0) break;
    while(day--){
        cin>>n;
        while(n--){
            cin>>d;
            s.insert(d);
        }
        mn = *s.begin();
        mx = *s.rbegin();
        sum += (mx-mn);
        s.erase(s.begin());
        s.erase(--s.end());
    }
    
    
    cout<<sum<<endl;
    }
    return 0;
}