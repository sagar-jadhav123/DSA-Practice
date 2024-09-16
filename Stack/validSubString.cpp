#include<bits/stdc++.h>
using namespace std;

int findMaxLen(string s) {
       int maxLen = 0;
       int open = 0;
       int close = 0;

       for(int i=0;i<s.size();i++){
        if(s[i] == '(') open++;
        else close++;

        if(open == close){
            maxLen = max(maxLen,2*close);
        }else if(close > open){
            open = close = 0;
        }
       }

       open = close = 0;

       for(int i = s.size()-1;i>=0;i--){
        if(s[i] == '(') open++;
        else close++;

        if(open == close){
            maxLen = max(maxLen,2*open);
        }
        else if(open > close){
            open = close = 0;
        }
       }

       return maxLen;
    }

int main(){
     string s = "()((()()";
     cout<<findMaxLen(s)<<endl;
}