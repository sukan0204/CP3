// ad hoc palindrome
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

map<char, char> reverseMap;

void init(){
    reverseMap['A'] = 'A';
    reverseMap['E'] = '3';
    reverseMap['H'] = 'H';
    reverseMap['I'] = 'I';
    reverseMap['J'] = 'L';
    reverseMap['L'] = 'J';
    reverseMap['M'] = 'M';
    reverseMap['O'] = 'O';
    reverseMap['S'] = '2';
    reverseMap['T'] = 'T';
    reverseMap['U'] = 'U';
    reverseMap['V'] = 'V';
    reverseMap['W'] = 'W';
    reverseMap['X'] = 'X';
    reverseMap['Y'] = 'Y';
    reverseMap['Z'] = 'Z';
    reverseMap['1'] = '1';
    reverseMap['2'] = 'S';
    reverseMap['3'] = 'E';
    reverseMap['5'] = 'Z';
    reverseMap['8'] = '8';
}

bool checkPalindrome(string &s, int i=0){
    if(i == s.length()/2)
        return true;
    if(s[i] == s[s.length()-1-i])
        return checkPalindrome(s, i+1);
    else
        return false;
}

bool checkMirrored(string &s, int i=0){
    if(i == s.length()/2 && reverseMap[s[i]]==s[s.length()-1-i])
        return true;
    if(reverseMap[s[i]] == s[s.length()-1-i])
        return checkMirrored(s, i+1);
    return false;
}

int main() 
{
    init();
    string line;
    while(getline(cin, line)){
        if(line.empty()) break;
        for (auto & c: line) c = toupper(c);
        bool isPalindrome = checkPalindrome(line);
        bool isMirrored = checkMirrored(line);
        if(!isPalindrome && !isMirrored)
            printf("%s -- is not a palindrome.\n\n", line.c_str());
        else if(isPalindrome && !isMirrored)
            printf("%s -- is a regular palindrome.\n\n", line.c_str());
        else if(!isPalindrome && isMirrored)
            printf("%s -- is a mirrored string.\n\n", line.c_str());
        else
            printf("%s -- is a mirrored palindrome.\n\n", line.c_str());
    }

    return 0;
} 
