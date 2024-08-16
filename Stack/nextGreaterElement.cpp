#include<bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans;
        stack<long long> st;
        for(int i = n-1;i>=0;i--){
                while(!st.empty() && st.top() <= arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans.push_back(st.top());
                }else{
                    ans.push_back(-1);
                }
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
      vector<long long> v{1,3,2,4};
      vector<long long> ans = nextLargerElement(v,4);
      for(auto val : ans){
        cout<<val<<" ";
      }
}