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

int N;
string line;
string a, b;
vi digits;

void solve(){
    digits.clear();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int larger = max(a.length(), b.length());
    loop(x, larger){
        int adigit, bdigit; adigit = bdigit = 0;
        if(x<a.length()) adigit = a[a.length()-1-x]-'0';
        if(x<b.length()) bdigit = b[b.length()-1-x]-'0';
        digits.push_back(adigit+bdigit);
    }
    int toAdd = 0;
    for(int i=0;i<digits.size();i++){
        if(digits[i]>=10){
            if(i+1<digits.size())
                digits[i+1]+=digits[i]/10;
            else
                toAdd = digits[i]/10;
            digits[i]=digits[i]%10;

        }

    }
    if(toAdd)
    digits.push_back(toAdd);
    bool zero = true;
    for(int i=0;i<digits.size();i++){
        if(digits[i]!=0) zero = false;
        if(!zero)   cout<<digits[i];
    }
    cout<<endl;
}

int main(){
    getline(cin, line);
    N = stoi(line);
    while(N--){
        getline(cin, line);
        stringstream ss(line);
        ss>>a>>b;

        solve();
    }
}