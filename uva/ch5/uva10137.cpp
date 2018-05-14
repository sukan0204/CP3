// The Trip

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
typedef vector<ll> vi;
typedef pair<int,int> pi;
#define INF 100000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

int student;
vector<double> dol;

void solve(){
    double total = 0;
    for(auto dollar: dol){
        total+=dollar;
    }
    double average = total/student;
    double answer = 0, answer2=0;;
    for(auto dollar: dol){
        if(average>dollar){
            int temp = (int)((average-dollar)*100);
            answer += temp/100.0;
        }
        if(average<dollar){
            int temp = (int)((dollar-average)*100);
            answer2 += temp/100.0;
        }
    }
    answer = max(answer, answer2);
    printf("$%.02lf\n", answer);
}


int main(){
    while(scanf("%d", &student)&&student!=0){
        dol.clear();
        loop(x, student){
            double dollar;
            scanf("%lf", &dollar);
            dol.push_back(dollar);
        }
        solve();
    }

    
}

