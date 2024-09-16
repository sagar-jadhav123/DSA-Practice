#include<bits/stdc++.h>
using namespace std;

    string reverseEqn (string s)
        {
            stack<string> st;
            string str = "";
            int num = 0;
            
            for(int i=0;i<s.size();i++){
                if(isdigit(s[i])){
                 num = num*10 + (s[i] - '0');   
                }
                else{
                  st.push(to_string(num));
                  st.push(string(1,s[i]));
                  num = 0;
                }
            }
            
            st.push(to_string(num));
            
            while(!st.empty()){
                str = str + st.top();
                st.pop();
            }
            
            return str;
        }

int main(){
     string  str = "20-3+5*2";
     cout<<reverseEqn(str)<<endl;
}