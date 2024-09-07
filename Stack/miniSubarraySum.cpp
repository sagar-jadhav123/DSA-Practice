#include<bits/stdc++.h>
using namespace std;
 
 int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<int> st;

    long long M = 1000000007;
   
    // for Previous Lesser Element PLE
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        left[i] = (st.empty()) ? i+1 : i - st.top();
        st.push(i);
    }
    // Next Smaller Element NSE

    while (!st.empty()) st.pop();
    

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        right[i] = (st.empty()) ? n-i : st.top() - i;
        st.push(i);
    } 
    long long  result = 0;
    
    for(int i=0;i<n;i++){

       long long contribution = (right[i] * left[i] * 1LL)%M;
        contribution = (contribution*arr[i])%M;
          result = (result + contribution)%M;

    }
        return result;

    } 

int main(){
    vector<int> arr{3,1,2,4};
    cout<<sumSubarrayMins(arr)<<endl;
}