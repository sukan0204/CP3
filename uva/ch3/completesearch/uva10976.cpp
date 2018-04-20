// Fractions Again

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

int k;
int x, y;
int count;
vector<pair<int, int>> answers;

void answer(){
    answers.clear();
    for(int i=k+1;i<=2*k;i++){
        x = k*i/(i-k);
        if(k*i%(i-k) == 0){
            x = k*i/(i-k);
            answers.push_back(pair<int,int>(x, i));
        }
    }
    cout<<answers.size()<<endl;
    for(auto s: answers)
        printf("1/%d = 1/%d + 1/%d\n", k, s.first, s.second);
}

int main(){
    while(cin>>k){
        answer();
    }

}