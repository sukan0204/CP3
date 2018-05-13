// Digit Counting

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
#define INF 100000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

#define SIZE 10000
void compute(int i);
void compute2(int i);
void solve(int a);

int a;
vector<vi> num;
vector<vi> answer;
int main(){
    num.resize(SIZE);
    answer.resize(SIZE);
    int k;
    scanf("%d", &k);
    while(k--){
    for(int i=1;i<SIZE;i++){
        num[i].assign(10, 0);
        answer[i].assign(10, 0);
        compute(i);
        compute2(i);
    }

    scanf("%d", &a);
    solve(a);
    
    }
}

void compute(int i){
    int ti = i;
    while(ti){
        int rem = ti%10;
        num[i][rem]+=1;
        ti/=10;
    }
}

void compute2(int i){
    if(i==1){
        for(int j=0;j<10;j++)
            answer[i][j] = num[i][j];
    } 
    else
    for(int j=0;j<10;j++){
        answer[i][j] = answer[i-1][j]+num[i][j];
    }
}

void solve(int a){
    for(int i=0;i<9;i++){
        printf("%d ", answer[a][i]);
    }
    printf("%d\n", answer[a][9]);
}