// Exact Sum

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

#define loop(x,n) for(int x = 0;x < n; ++x)

int books[10001];
int n, m;
int i, j;
int tempn;
bool binarysearch(int a, int b, int toFind){
    while(b >= a){
        int middle = (a + b) / 2;
        if(books[middle] == toFind){
            tempn = middle;
            return true;
        }
        if(books[middle] < toFind){
            a = middle + 1;
        }
        if(books[middle] > toFind){
            b = middle - 1;
        }
    }
    return false;
}
void answer(){
    tempn = n;
    sort(books, books+n);
    int tempi = -1;
    int tempj = -1;
    loop(x, n){
        tempi = books[x];
        tempj = m - books[x];
        if(binarysearch(x+1, tempn, tempj)){
            i = tempi;
            j = tempj;
        }
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n", i, j);
}

int main(){

    while(cin>>n){
        loop(x, n){
            cin>>books[x]; 
        }
        cin>>m;
        answer();
    }
 
    return 0;
}