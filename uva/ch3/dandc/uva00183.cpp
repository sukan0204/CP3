// Bit Maps

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

char ch;
int r, c;
string b;
char bit[210][210];

string BToD(int row, int col, int startR=0, int startC=0){
    if(row==0||col==0) return "";
    char cc = bit[startR][startC];
    bool diff = false;
    for(int i = startR; i<startR+row;i++){
        for(int j = startC; j<startC+col;j++){
            if(cc!=bit[i][j]){
                diff = true;
                break;
            }
        }
    }
    if(diff){
        int r1, r2, c1, c2;
        // upper left
        r1 = row/2;
        c1 = col/2;
        if(row%2!=0) r1 += 1;
        if(col%2!=0) c1 += 1;
        r2 = row-r1;
        c2 = col-c1;
        string s = "D";
        string s1 = BToD(r1, c1, startR, startC);
        string s2 = BToD(r1, c2, startR, startC + c1);
        string s3 = BToD(r2, c1, startR + r1, startC);
        string s4 = BToD(r2, c2, startR + r1, startC + c1);

        return s+s1+s2+s3+s4;
    }
    else{
        string s = "";
        return s+cc;
    }
}
int idx = 0;
void DToB(int row, int col, int startR=0, int startC=0){
// B   2   3
// DD10111
// 1 0 1 
// 1 1 1
    if(row==0||col==0) return;
    if(b[idx]=='D'){
        idx++;
       int r1, r2, c1, c2;
        // upper left
        r1 = row/2;
        c1 = col/2;
        if(row%2!=0) r1 += 1;
        if(col%2!=0) c1 += 1;
        r2 = row-r1;
        c2 = col-c1;
        DToB(r1, c1, startR, startC);
        DToB(r1, c2, startR, startC + c1);
        DToB(r2, c1, startR + r1, startC);
        DToB(r2, c2, startR + r1, startC + c1);        
    }
    else{
        for(int i = startR; i<startR+row;i++){
            for(int j = startC; j<startC+col;j++){
                bit[i][j] = b[idx];
            }
        }
        idx ++;
    }
    
}

string line;
int main(){
    getline(cin, line);
    while(true){
        if(line[0]=='#') break;
        sscanf(line.c_str(), "%c %d %d", &ch, &r, &c);
        b = "";
        int rc = r*c;
        while(rc){
            getline(cin, line);
            if(line[0]=='#'||line[1]==' ')
                break;
            b += line;
        }

        string ans="";
        if(ch=='B'){
            //001000011011
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                bit[i][j] = b[j + c*i];
            }
        } 
            ans = BToD(r, c);
        }
        else {
            idx = 0;
            DToB(r, c);
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    ans=ans+bit[i][j];
                }
            }
        }

        ch = ch == 'B'?'D':'B';
        printf("%c%4d%4d\n", ch, r, c);
        for(int i=0;i<ans.length();i+=50){
            string subs = ans.substr(i, min(50, (int)ans.length()-i));
            cout<<subs<<endl;
        }
    }
 
    return 0;
}