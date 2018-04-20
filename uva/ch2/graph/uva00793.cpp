
// Network Connections

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

int T, n;
int a, b;
int * uf;
char c;
string line;

void init(int n){
    uf = new int[n+1];
    for(int i=0;i<=n;i++)
        uf[i] = i;
}

int find(int i){
    return uf[i]==i?i:find(uf[i]);
}

void connect(int a, int b){
    int ap = find(a);
    int bp = find(b);
    if(ap!=bp) uf[bp] = ap;
}

int main(){
   getline(cin, line);
   T = stoi(line);
   getline(cin, line);
   for(int i=0;i<T;i++){
       if(i!=0) cout<<endl;
       getline(cin, line);
       
       n = stoi(line);
       init(n);
       int suc, unsuc;
       suc = unsuc = 0;
       while(getline(cin, line)){
           if(line.empty()) break;
           sscanf(line.c_str(), "%c %d %d", &c, &a, &b);
           if(c=='c'){
                connect(a, b);
           }
           else {
               if(find(a) == find(b)) suc +=1;
               else unsuc += 1;
           }
       }
       printf("%d,%d\n", suc, unsuc);

   }
   return 0;
}
