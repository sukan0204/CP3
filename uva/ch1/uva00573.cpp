// easy
// horror dash

#include <iostream>
#include <sstream>
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
void answer(vector<int> &v){
    int h = v[0];
    int u = v[1];
    int d = v[2];
    int f = v[3];
    int day = 1;
    double current = 0;
    current += u;
    if(current > h){
        cout<<"success on day 1"<<endl;
        return;
    }
    current -= d;
    if(current < 0){
        cout<<"failure on day 1"<<endl;
        return;
    }
    double prevC = u;
    while(true){
        day++;
        double climb = prevC - 0.01*u*f;
        if(climb>0){
            current += climb;
            prevC = climb;
        }
        if(current > h)
            break;
        current -= d;
        if(current < 0)
            break;
    }
    if(current > h){
        cout<<"success on day "<<day<<endl;
    }
    else{
        cout<<"failure on day "<<day<<endl;
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
        answer(v);
        
    }

   return 0;
}