// ad hoc game (easy)
// hangman
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

bool toMatch[26] = {0};
bool matched[26] = {0};

int main() 
{
    int round;
    string a, b;
    cin>>round;
    while(round!=-1){
        cin>>a>>b;
        printf("Round %d\n", round);
        int matchCount = 0;
        for(char c: a){
            int i = c-'a';
            if(!toMatch[i]){
                toMatch[i] = true;
                matchCount++;
            }
        }
        int matchedCount = 0;
        int totalCount = 0;
        for(char c: b){
            int i = c-'a';
            totalCount++;
            if(toMatch[i]&&!matched[i]){
                matched[i] = true;
                matchedCount++;
                if(matchedCount == matchCount){
                    cout<<"You win."<<endl;
                    break;
                }
            }
            else{
                if(totalCount - matchedCount>=7){
                    cout<<"You lose."<<endl;
                    break;
                }
            }
            if(totalCount == b.length()){
                cout<<"You chickened out."<<endl;
            }
        }
        
        cin>>round;
        memset(toMatch, 0, sizeof(toMatch));
        memset(matched, 0, sizeof(matched));
    }

    return 0;
} 
