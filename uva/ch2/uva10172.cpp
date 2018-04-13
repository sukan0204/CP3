// Anagrams by stack

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
int n, s, q;
int temp;
vector<queue<int>> platB;
stack<int> cargo;

void getAnswer(){
    int min = 0;
    int station = 0;
    for(;;){
        while(!cargo.empty()&&platB[station].size()<=q){
            if(cargo.top() == station+1){
                cargo.pop();
                min += 1;
            }
            else if(platB[station].size()<q){
                platB[station].push(cargo.top());
                cargo.pop();
                min += 1;
            }
            else
                break;
        }       
        while(cargo.size()<s&&!platB[station].empty()){
            int getBox = platB[station].front();
            cargo.push(getBox);
            platB[station].pop();
            min += 1;
        }
        bool allEmpty = true;
        for(int i=0;i<n;i++){
            if(!platB[i].empty())
                allEmpty = false;
        }
        if(cargo.empty() && allEmpty)
            break;
        station = (station+1)%n;
        min += 2;
    }
    cout<<min<<endl;
}

int main(){
    scanf("%d", &k);
    while(k--){
        scanf("%d %d %d", &n, &s, &q);
        platB.clear();
        cargo = stack<int>();
        for(int i=0;i<n;i++){
            int cargoN;
            scanf("%d", &cargoN);
            queue<int> qu;
            while(cargoN--){
                scanf("%d", &temp);
                
                qu.push(temp);
            }
            platB.push_back(qu);
        }
        getAnswer();
    }
}