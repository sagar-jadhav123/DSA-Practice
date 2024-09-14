#include<bits/stdc++.h>
using namespace std;

 vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            bool flag = false;
            if(!st.empty() && ((st.top()>=0 && arr[i] < 0) || (st.top() < 0 && arr[i] >= 0))){
                st.pop();
                flag = true;
            }
            if(!flag) st.push(arr[i]);
        }

        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
}

int main(){
    vector<int> v{2,1,-4,3,-5,2,6,-3};
    
    vector<int> ans = makeBeautiful(v);

    for(auto val : ans){
        cout<<val<<" ";
    }

}