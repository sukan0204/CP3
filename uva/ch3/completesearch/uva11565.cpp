// Simple Equations

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

int T;
int a, b, c;
int x, y, z;
void answer(){
    // x + y + z = A
    // x*y*z = B;
    // x^2+y^2+z^2 = C
    vector<int> factors;
    for(int i=1;i<=sqrt(b);i++){
        if(b%i==0){
            factors.push_back(i);
            factors.push_back(b/i);
        }
    }
    sort(factors.begin(), factors.end());
    
    int yfloor = floor(sqrt(c/3));
    auto zit = factors.end()-1;
    auto xit = zit;
    y = yfloor;
    while(true){
        x = -(*xit);
        auto yit = xit;
        while((*xit)>=(*yit)){
            y = -(*yit);
            int zsqr = c-x*x-y*y;
            z = a-y-x;
            if(x>y) break;
            if(z*z==zsqr&&x*y*z==b&&x!=y&&y!=z&&x!=z){
                cout<<x<<" "<<y<<" "<<z<<endl;
                return;
            }
            if(yit == factors.begin()) break;
            yit--;
        }
        if(xit == factors.begin()) break;
        xit--;
    }
    while(true){
        z = *zit;
        auto yit = zit;
        while(*zit>=*yit){
            y = *yit;
            int xsqr = c-z*z-y*y;
            x = a-y-z;
            if(x>y) break;
            if(x*x==xsqr&&x*y*z==b&&x!=y&&y!=z&&x!=z){
                cout<<x<<" "<<y<<" "<<z<<endl;
                return;
            }
            if(yit == factors.begin()) break;

            yit--;
        }
        if(zit == factors.begin()) break;
        zit--;
    }
    cout<<"No solution."<<endl;
}

int main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        answer();
    }
    return 0;


}