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


int main(){
    string line;
    while(true){
        getline(cin, line);
        if(line=="#") break;
        if(next_permutation(line.begin(), line.end())){
            cout<<line<<endl;
        }
        else{
            cout<<"No Successor"<<endl;
        }
    }
}