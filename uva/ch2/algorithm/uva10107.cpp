// What is the Median?

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

vector<int> v;

int getMedian(){
    sort(v.begin(), v.end());
    int size = v.size();
    if(size%2!=0)
        return v[size/2];
    else
        return (v[size/2-1]+v[size/2])/2;
}
int main(){
    string line;
    while(true){
        getline(cin, line);
        if(line.empty()) break;
        v.push_back(stoi(line));
        cout<<getMedian()<<endl;
    }
}