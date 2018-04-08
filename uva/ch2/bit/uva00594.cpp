// ad hoc convert to different endian
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

void answer(int original){
    int b1, b2, b3, b4;
    b1 = (original & 0xff);
    b2 = (original & 0xff00);
    b3 = (original & 0xff0000);
    b4 = (original & 0xff000000);
    b1 = (original<<24)&0xff000000;
    b2 = (original<<8)&0xff0000;
    b3 = (original>>8)&0xff00;
    b4 = (b4>>24)&0xff;
    int result = (b1|b2|b3|b4);
    //printf("%x %x %x %x %x\n", original, b1, b2, b3, b4);
    printf("%d converts to %d\n", original, result);
}

int main() 
{
    string line;
    while(true){
        getline(cin, line);
        if(line.empty()) break;
        int original = stoi(line);
        answer(original);
    }

    return 0;
} 
