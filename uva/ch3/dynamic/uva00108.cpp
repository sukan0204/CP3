// maximum sum

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

int N;
int ar[101][101];
void answer(){

}
int main(){
    cin>>N;
    int temp;
    loop(x,N){
        loop(y,N){
            cin>>temp;
            ar[x][y] = temp;
            if(x>0) ar[x][y]+=ar[x-1][y];
            if(y>0) ar[x][y]+=ar[x][y-1];
            if(x>0&&y>0) ar[x][y]-=ar[x-1][y-1];
        }
    }
    int maxSum = -128;
    loop(startX, N){
        loop(startY, N){
            for(int i=startX;i<N;i++){
                for(int j=startY;j<N;j++){
                    int sum = ar[i][j];
                    if(startX>0)
                    sum -= ar[startX-1][j];
                    if(startY>0)
                    sum -= ar[i][startY-1];
                    if(startX>0&&startY>0){
                        sum+=ar[startX-1][startY-1];
                    }
                    maxSum = max(sum, maxSum);
                }
            }
        }
    }
    cout<<maxSum<<endl;
    return 0;
}