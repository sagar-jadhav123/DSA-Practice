#include<bits/stdc++.h>
using namespace std;

string reverseWords(string str) {
        string temp = "";
        string ans = "";
        for(int i=0;i<str.size();i++){
            if(str[i] != '.'){
                temp += str[i];
            }
            else{
               ans = '.' + temp + ans;
               temp = "";
            }
        }
        ans = temp + ans;
        return ans;
    }

int main(){
    string s = "pqr.";
    cout<<reverseWords(s)<<endl;

}