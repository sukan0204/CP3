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

stack<char> st;
vector<string> answers;

void answer(string line1, string line2, int ni = 0, int no = 0, string sofar = "", string io = ""){
    if(ni == line1.length() && no == line1.length() && sofar == line2){
        answers.push_back(io);
        return;
    }
    else if(ni == line1.length() && no == line1.length()) return;
 
    if(line2.substr(0, sofar.size()) != sofar) {
        return;
    }

    string io1 = io+'i';
    string io2 = io+'o';

    if(ni < line1.length()){
        st.push(line1[ni]);
        answer(line1, line2, ni+1, no, sofar, io1);
        st.pop();
    }
    if(!st.empty()){
        char c = st.top();
        sofar = sofar + c;
        st.pop();
        answer(line1, line2, ni, no+1, sofar, io2);
        st.push(c);
    }
}


bool isAnagram(string line1, string line2){
    sort(line1.begin(), line1.end());
    sort(line2.begin(), line2.end());
    return line1 == line2;
}

string line1, line2;
int main(){
    while(true){
        getline(cin, line1);
        if(line1.empty()) break;
        getline(cin, line2);
        answers.clear();
        if(isAnagram(line1, line2)){
            answer(line1, line2);
            cout<<'['<<endl;
            for(string& s: answers){
                for(int i=0;i<s.length()-1;i++){
                    cout<<s[i]<<" ";
                }
                cout<<s[s.length()-1]<<endl;
            }
            cout<<']'<<endl;

        }
        else {
            cout<<"[\n]"<<endl;
        }

    }
}