// Extend to Palindrome

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

int sym[200010];
string line;

void findSymmetry(){
    clr(sym);
    string rev = line;
    reverse(rev.begin(), rev.end());
    string concat = rev + line;
    int len = 0;
    sym[0] = 0;
    int i = 1;
    int M = concat.length();
    while(i < M){
        if(concat[i] == concat[len]){
            len++;
            sym[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = sym[len-1];
            }
            else{
                sym[i] = 0;
                i++;
            }
        }
    }
    size_t symLen = sym[M-1];
    symLen = min(symLen, line.length());
    string pre = line.substr(0, line.length()-symLen);
    string suf = line.substr(line.length()-symLen, symLen);
    string revpre = pre;
    reverse(revpre.begin(), revpre.end());
    cout<<pre<<suf<<revpre<<endl;

}


int main(){
    while(cin>>line){
        findSymmetry();
    }
}