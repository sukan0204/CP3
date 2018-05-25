// Immediate Decodability

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
#define INF 1000000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))

vector<string> vs;
int t=1;
bool solve();
int main(){
    string line;
    while(getline(cin, line)){
        if(line.length()==1&&line[0]=='9'){
            if(solve()){
                printf("Set %d is immediately decodable\n", t);
            }
            else{
            printf("Set %d is not immediately decodable\n", t); 
            }
            vs.clear();
            t++;
        }
        else
        vs.push_back(line);
    }
}

struct Node {
    Node * zero;
    Node * one;
    char c;
    bool exist;
    Node(){
        zero=NULL;
        one=NULL;
        exist=false;
    }
};

bool solve(){
    Node* tree = new Node();
    ///head->exist = false;
    for(auto str: vs){
        Node * current = tree;
        for(int i=0;i<str.length();i++){
            if(str[i]=='0'){
                if(current->zero==NULL){
                    current->zero = new Node();
                }else{
                    if(current->zero->exist||i==str.length()-1) return false;
                }
                current = current->zero;
            }else{
                if(current->one==NULL){
                    current->one = new Node();
                }else{
                    if(current->one->exist||i==str.length()-1) return false;
                }
                current = current->one;
            }
            current->exist = i==str.length()-1;
        }
    }
    return true;
}