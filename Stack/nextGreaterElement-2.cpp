// Next Greater ELement in Circular Array

#include<bits/stdc++.h>
using namespace std;

    vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            stack<int> st;
            vector<int> ans(n,-1);
            for(int i=2*n-1;i>=0;i--){
                int current = nums[i%n];
                while(!st.empty() && st.top() <= current){
                    st.pop();
                }
                if(i<n && !st.empty()){
                    ans[i] = st.top();
                }
                st.push(current);
            }
            return ans;
    }

int main(){
     vector<int> v{1,2,3,4,3};
     vector<int> ans = nextGreaterElements(v);
     for(auto val : ans){
        cout<<val<<" ";
     }
}
