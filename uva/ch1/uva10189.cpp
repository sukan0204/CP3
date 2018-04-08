// ad hoc game (easy)
// Minesweeper
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

string mines[101];

int main() 
{
    int m, n;
    cin>>n>>m;
    int round = 1;
    while(m!=0&&n!=0){
        string line;
        for(int i=0;i<n;i++){
            cin>>line;
            mines[i] = line;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mines[i][j]!='*'){
                    int count = 0;
                    if(i>0&&mines[i-1][j]=='*')
                        count++;
                    if(i>0&&j>0&&mines[i-1][j-1]=='*')
                        count++;
                    if(i>0&&j<m-1&&mines[i-1][j+1]=='*')
                        count++;
                    if(j>0&&mines[i][j-1]=='*')
                        count++;
                    if(j<m-1&&mines[i][j+1]=='*')
                        count++;
                    if(i<n-1&&j>0&&mines[i+1][j-1]=='*')
                        count++;
                    if(i<n-1&&mines[i+1][j]=='*')
                        count++;
                    if(i<n-1&&j<m-1&&mines[i+1][j+1]=='*')
                        count++;
                    mines[i][j] = count + '0';                    
                }
            }
        }
        if(round != 1){
            cout<<endl;
        }
        printf("Field #%d:\n", round);
        for(int i=0;i<n;i++){
            cout<<mines[i]<<endl;
        }
        round++;
        cin>>n>>m;
    }

    return 0;
} 
