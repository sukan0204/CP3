// Sum It Up

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
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int t,n;
int x[15];
vector<string> answers; 

void answer(int mask = 0, int sum=0, int index=0){
    if(sum>t) return;
    if(sum == t){
        string ans = "";
        bool first = true;
        loop(i, n){
            if(CHECK_BIT(mask, i)){
                if(!first) 
                    ans += "+";
                ans += to_string(x[i]);
                first = false;
            }
        }
        if(answers.empty() || find(answers.begin(), answers.end(),ans) == answers.end())
            answers.push_back(ans);
        return;
    }
    if(index>=n) return;
    mask = (mask | (1<<index));
    answer(mask, sum + x[index], index+1);
    mask = (mask & ~(1<<index));
    answer(mask, sum, index+1);
}
int main(){
    while(cin>>t){
        cin>>n;
        if(t==0 && n==0) return 0;
        loop(i,n){
            cin>>x[i];
        }
        answers.clear();
        answer();
        printf("Sums of %d:\n", t);
        if(answers.empty())
            cout<<"NONE"<<endl;
        else{
            for(auto s: answers)
                cout<<s<<endl;
        }
    }
    return 0;
}