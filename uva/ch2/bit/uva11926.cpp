// multitasking
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

bool noConflict;
bool times[1000100];

bool check(int start, int end){
    if(!noConflict) return false;
    for(int i=start; i<end;i++){
        if(times[i]){ 
            noConflict = false;
            return false;
        }
        times[i] = true;
    }

    return true;
    
}

int main() 
{
    int n, m;
    int start, end, interval;
    while(true){
        scanf("%d %d", &n, &m);
        if(n==0 && m==0) break;
        noConflict = true;
        memset(times, false, sizeof(times));
        while(n--){
            int start, end;
            scanf("%d %d", &start, &end);
            check(start, end);
        }
        while(m--){
            scanf("%d %d %d", &start, &end, &interval);
            while(start<=1000000 && noConflict){
                check(start, end);
                start+= interval;
                end+= interval;
                end = min(end, 1000000);
            }
        }
        if(noConflict) printf("NO CONFLICT\n");
        else printf("CONFLICT\n");
    }

    return 0;
} 
