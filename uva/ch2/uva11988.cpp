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


string line;
void beiju(){
    int start = 0;
    bool swit = true;
    int length = 0;
    char lastseen = '[';
    string answer = "";
    for(int i=0;i<line.length();i++){
        if(line[i] == '[' || line[i] == ']'){
            if(swit){
                swit = false;
                if(length){
                    string sub = line.substr(start, length);
                    if(lastseen == '[') answer = sub+answer;
                    else answer = answer+sub;
                }
                length = 0;
            }
            lastseen = line[i];
            swit = false;
        }
        else{
            if(!swit){
                swit=true;
                start = i;
            }
            length++;
            if(i == line.length()-1){
                if(length){
                string sub = line.substr(start, length);
                if(lastseen == '[') answer = sub+answer;
                else answer = answer+sub;
                }
            }
        }
    }

    cout<<answer<<endl;
}
int main(){

    while(true){
        getline(cin, line);
        if(line.empty()) break;
        beiju();
    }
}