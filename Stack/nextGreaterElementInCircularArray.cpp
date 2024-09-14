#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> &arr, int n){
        stack<long long> st;
        vector<long long> ans(n);

        for(int i = (2*n-1); i >=0 ; i--){
            while(!st.empty() && (arr[i%n] >= st.top())){
                st.pop();
            }
            if(st.empty() && i < n ){
                ans[i] = -1;
            }
            if(!st.empty() && i < n){
                ans[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        return ans;
}

int main(){
      vector<long long> v{6,8,0,1,3};

      vector<long long> ans = nextLargerElement(v,5);

      for(auto val : ans){
        cout<<val<<" ";
      }
}