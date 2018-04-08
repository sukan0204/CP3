// bit the most potent corner
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


int weights[1<<15];
int potency[1<<15];

#define toggleBit(S, j) (S ^ (1 << j))


int main() 
{
    string line;
    while(true){
        getline(cin, line);
        if(line.empty()) break;
        int N = stoi(line);
        int bitN = N;
        N = (1<<N);
        for(int i=0;i<N;i++){
            getline(cin, line);
            weights[i] = stoi(line);
        }
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int b=0;b<bitN;b++){
                int neighbor = toggleBit(i, b);
                sum += weights[neighbor];
            }
            potency[i] = sum;
        }
        int answer = -1;
        for(int i=0;i<N;i++){

            for(int b =0;b<bitN;b++){
                int neighbor = toggleBit(i, b);
                answer = max(potency[i]+potency[neighbor], answer);
            }
        }
        printf("%d\n", answer);
  
    }

    return 0;
} 
