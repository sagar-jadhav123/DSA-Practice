#include<bits/stdc++.h>
using namespace std;

int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
    // PSE Previous Smaller Element
        for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        left[i] = (st.empty()) ? 0 : arr[st.top()];
        st.push(i);
    }

    // Next Smaller Element NSE

    while (!st.empty()) st.pop();
    

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        right[i] = (st.empty()) ? 0 : arr[st.top()];
        st.push(i);
    } 

    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi,abs(right[i] - left[i]));
    }
    return maxi;
    }


int main(){
     vector<int> v{32,57,21,22};
    //  vector<int> v{2, 4, 8, 7, 7, 9, 3};
     cout<<findMaxDiff(v)<<endl;
}