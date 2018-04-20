// CD

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

int N, T;
int t;
vector<int> tracks;
int maxSum;
vector<int> maxTracks;
vector<int> tempTracks;


int findMax(int index, vector<int> tempTracks, int sum = 0){
    if(index>=tracks.size())
        return sum;
    if(sum == N)
        return sum;
    if(sum + tracks[index]>N) 
        return findMax(index+1, tempTracks, sum);
    tempTracks.push_back(tracks[index]);
    int sum1 = findMax(index + 1, tempTracks, sum + tracks[index]);
   if(maxSum < sum1){
        maxSum = sum1;
        maxTracks = tempTracks;
    }
    tempTracks.pop_back();
    int sum2 = findMax(index + 1, tempTracks, sum);
    if(maxSum < sum2){
        maxSum = sum2;
        maxTracks = tempTracks;
    }
    return max(sum1, sum2);
}
void answer(){
    maxSum = -1;
    tempTracks.clear();
    findMax(0, tempTracks);
    for(auto i: maxTracks){
        cout<<i<<" ";
    }
    cout<<"sum:"<<maxSum<<endl;
}
int main(){
    while(cin>>N){
        cin>>T;
        tracks.clear();
        while(T--){
            cin>>t;
            tracks.push_back(t);

        }
        answer();
    }

}