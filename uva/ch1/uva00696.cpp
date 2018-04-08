// ad hoc chess
//  how many knights
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

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}  

int main() 
{

     char sor[100];
     int x, y;
     do{
        gets(sor);
        sscanf(sor, "%d %d", &x, &y);
        if(x==0&&y==0) break;
        int answer;
        if(x==0||y==0)
            answer = 0;
        else if(x>=3&&y>=3)
            answer = ((x*y)+1)/2;
        else if(x==1||y==1){
            answer = (x>y)?x:y;
        }
        else{
            int all = x*y;
            answer = ((all%8)>4?4:(all%8))+4*(all/8);
        }
        printf("%d knights may be placed on a %d row %d column board.\n", answer, x, y);
     }while(true);

    return 0;
} 
