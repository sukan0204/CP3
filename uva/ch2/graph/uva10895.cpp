
// Matrix Transpose

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

int m, n;
int nz;
vector<int> temp;
int nzi;
int matrix[10010][10010] = {};
vector<int> va[10010];
int main(){
    while(cin>>m){
    cin>>n;
    for(int i=0;i<=n;i++) va[i].clear();
    for(int i=1;i<=m;i++){
        temp.clear();
        cin>>nz;
        for(int j=0;j<nz;j++){
            cin>>nzi;
            va[nzi].push_back(i);
            temp.push_back(nzi);
        }
        for(int j=0;j<nz;j++){
            cin>>nzi;
            matrix[i][temp[j]] = nzi;
        }
    }

    printf("%d %d\n", n, m);
    for(int i=1;i<=n;i++){
        int size = va[i].size();
        cout<<size;
        for(int j=0;j<size;j++){
            cout<<" "<<va[i][j];
        }
        cout<<endl;
        for(int j=0;j<size;j++){
            if(j!=0)
            cout<<" "<<matrix[va[i][j]][i];
            else
            cout<<matrix[va[i][j]][i];
        }
        cout<<endl;
    }
    }
   return 0;
}
