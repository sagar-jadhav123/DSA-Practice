#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    int maxArea = 0;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            int height = arr[st.top()];
            st.pop();
            int width = st.empty()?i:i-st.top()-1;
            maxArea = max(maxArea,width*height);
        }
        st.push(i);
    }

    while(!st.empty()){
        int height = arr[st.top()];
        st.pop();
        int width = st.empty()? n : n - st.top()-1;
        maxArea = max(maxArea,height*width);
    }
    return maxArea;
}

int main(){
    vector<int> arr{2,1,5,6,2,3};
    cout<<largestRectangleArea(arr)<<endl;
}

// Brute Approach
// int largestRectangleArea(vector<int>& arr){
//       int n = arr.size();
//       vector<int> pse(n,-1);
//       vector<int> nse(n,n);
//       int maxArea = 0;
//       stack<int> st;

//       for(int i=0;i<n;i++){
//         while(!st.empty() && arr[st.top()] >= arr[i]){
//             st.pop();
//         }
//         if(!st.empty()){
//             pse[i] = st.top();
//         }
//         st.push(i);
//       }

//       for(int i = n-1; i >= 0; i--){
//         while(!st.empty() && arr[st.top()] >= arr[i]){
//             st.pop();
//         }
//         if(!st.empty()){
//             nse[i] = st.top();
//         }
//         st.push(i);
//       }

//       for(int i=0;i<n;i++){
//         maxArea = max(maxArea,arr[i]*(nse[i]-pse[i]-1));
//       }

//       return maxArea;


// }