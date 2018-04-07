// easy
// horror dash

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int n;
    string nstr;
    getline(cin, nstr);
    n = stoi(nstr);
    for(int i=0;i<n;i++){
        string str;
        getline(cin, str);
        stringstream ss(str);
        string buf;
        int max = -1;
        while(ss >> buf){
            int a = stoi(buf);
            if(a>max) max=a;
        }
        printf("Case %d: %d\n", i+1, max);
    }
   
   return 0;
}