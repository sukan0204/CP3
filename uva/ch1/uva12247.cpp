// ad hoc Card
// jollo 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> getnumber(string line){
    stringstream ss(line);
    string buf;
    vector<int> v;
    while(ss >> buf){
        v.push_back(stoi(buf));
    }
    return v;
}
int numGreater(vector<int> &g, int i){
    int count = 0;
    for(int n: g){
        if(i>n) count++;
    }
    return count;
}
int findNext(vector<int> v, int i){
    while(find(v.begin(), v.end(), i) != v.end() && i<=52){
        i++;
    }
    if(i>52) return -1;
    return i;
}
int answer(vector<int> &v){
    vector<int> g(v.begin(), v.begin()+3);
    vector<int> b(v.begin()+3,v.end());
    sort(g.begin(), g.end());
    int XGreater = numGreater(g, b[0]);

    int YGreater = numGreater(g, b[1]);
    // 1. Fail Case
    if((XGreater<=1&&YGreater<=2)||(XGreater<=2&&YGreater<=1)){
        return -1;
    }
    // either X or Y is 3
    else if(XGreater==3 || YGreater==3){
        // 3,3, ? always win
        if(XGreater==3&&YGreater==3){
            return findNext(v, 1);
        }
        else{
            // 3, 1, 3
            int smaller = (XGreater<YGreater)?XGreater:YGreater;
            if(smaller <= 1){
                return findNext(v, g[2]+1);
            }
            else{
                return findNext(v, g[1]+1);
            }

        }
    }
    // 2, 2, 2
    else{
        return findNext(v, g[1]+1);
    }
}
int main()
{
    string line;
    while(getline(cin, line)){
        vector<int> v = getnumber(line);
        if(v[0] == 0){
            return 0;
        }
        cout<<answer(v)<<endl;
        
    }

   return 0;
}