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
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define INF 1000000000
#define loop(x,n) for(int x = 0;x < n; ++x)
#define clr(ar) memset(ar,0,sizeof(ar))
#define EPS 1.0E-3

int tc;
string line;

struct cont{
    int id, num, pt, mask;
    int pts[11];
    bool submitted = false;
    bool operator()(cont i, cont j){
        if(i.num>j.num)
            return true;
        else if(i.num==j.num&&i.pt<j.pt)
            return true;
        else if(i.num==j.num&&i.pt==j.pt&&i.id<j.id)
            return true;
        return false;
    }
} obj;

vector<cont> people;
void init(){
    people.clear();
    people.resize(110);
    for(int i=0;i<101;i++){
        people[i].id = i;
        people[i].num = 0;
        people[i].pt = 0;
        people[i].mask = 0;
        clr(people[i].pts);
        people[i].submitted = false;
    }
}

int main(){
    getline(cin, line); tc = stoi(line);
    getline(cin, line);
    bool first = true;
    while(tc--){
        init();
    while(getline(cin, line)&&line!=""){
        int a, b, c;
        char d;
        sscanf(line.c_str(), "%d %d %d %c", &a, &b, &c, &d);
        people[a].submitted = true;
        if(d=='I'&&!(people[a].mask&(1<<b))){
            people[a].pts[b] += 20;
        }
        if(d=='C'&&!(people[a].mask&(1<<b))){
            people[a].pts[b] += c;
            people[a].pt += people[a].pts[b];
            people[a].num += 1;
            people[a].mask |= (1<<b);
        }

    }
    sort(people.begin(), people.end(), obj);
    if(!first)
        cout<<endl;
    for(int i=0;i<people.size();i++){
        if(people[i].submitted){
            printf("%d %d %d\n", people[i].id, people[i].num, people[i].pt);
        }
    }
    first = false;
    }
    return 0;
}