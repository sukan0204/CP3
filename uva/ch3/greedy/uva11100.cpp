//The Trip


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

struct bag{
    int num;
    int dim;
    bag(int _dim, int _num)
    {
        dim = _dim;
        num = _num;

    }
};

class bagcomparison
{
    public:
    bool operator()(bag& one, bag& two){
        return one.num<two.num;
    }
};

int n;
int bags[10010];
map<int, int> m;
priority_queue<bag, vector<bag>, bagcomparison> bv;
void answer(){
    m.clear();
    bv = priority_queue<bag, vector<bag>, bagcomparison>();
    loop(x, n){
        if(m.find(bags[x]) != m.end()){
            m[bags[x]]++;
        }
        else{
            m[bags[x]]=1;
        }
    }

    for(auto const &i:m){
        bv.push(bag(i.first, i.second));
    }
    int max = bv.top().num;
    cout<<max<<endl;
    int divi = max;
    int arr[10000];

    loop(x, max){
        int k = n/divi;
        if(n%divi!=0) k++;
        divi--;
        n -= k;
        bool first = true;
        vector<bag> temp;
        for(int i=0;i<k;i++){
            if(bv.empty()){
                cout<<"wrong"<<endl;
            }
            bag t = bv.top();
            bv.pop();
            temp.push_back(bag(t.dim, t.num-1));
            
            arr[i] = t.dim;
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i].num>0)
                bv.push(temp[i]);
        }
        sort(arr, arr+k);
        for(int i=0;i<k;i++){
            if(!first) cout<<" ";
            cout<<arr[i];
            first = false;
        }
        cout<<endl;
    }

    
}

int main(){
    bool firstcase = true;
    while(true){
        cin>>n;
        if(n==0) break;
        loop(x, n){
            cin>>bags[x];
        }
        if(!firstcase)
            cout<<endl;
        answer();
        firstcase = false;
    }
 
    return 0;
}