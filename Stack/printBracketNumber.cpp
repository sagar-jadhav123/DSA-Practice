#include<bits/stdc++.h>
using namespace std;

vector<int> bracketNumbers(string str) {
        int count = 0;
        vector<int> ans;
        stack<pair<char,int>> st;

        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                count++;
                st.push({'(',count});
                ans.push_back(count);
            }
            else if(str[i] == ')'){
                ans.push_back(st.top().second);
                st.pop();
            }
        }

        return ans;
}


int main(){
    string str = "(aa(bdc))p(dee)";
    vector<int> ans  =  bracketNumbers(str);

    for(auto val : ans){
        cout<<val<<" ";
    }
}