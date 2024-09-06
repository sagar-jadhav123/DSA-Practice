#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &arr){
   stack<int> st;
   int n = arr.size();
   for(int i=0;i<n;i++){
    bool flag = false;
    while(!st.empty() && (arr[i] < 0 && st.top() > 0)){
        if(abs(arr[i]) == st.top()){
            st.pop();
            flag = true;
            break;
        }
        else if(abs(arr[i]) > st.top()){
            st.pop();
        }
        else{
            flag = true;
            break;
        }
    }
    if(!flag){
        st.push(arr[i]);
    }
   }
   vector<int> ans;
   while(!st.empty()){
      ans.push_back(st.top());
      st.pop();
   }
   reverse(ans.begin(),ans.end());
   return ans;
    
}
int main(){
    vector<int> v{-2,-1,1,2};
    vector<int> ans = asteroidCollision(v);
    for(auto val : ans){
        cout<<val<<" ";
    }
}