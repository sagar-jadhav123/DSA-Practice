#include<bits/stdc++.h>
using namespace std;


// Brute Force
/*int largestRectangleArea(vector<int>& arr) {
        int maxArea = 0;
        int maxi = INT_MIN;
        int n = arr.size();

        for(int i=0;i<n;i++){
            maxi = arr[i];
            for(int j = i+1; j < n; j++){
                if(arr[j] >= arr[i]){
                    maxi += arr[i];
                }
                else break;
            }

            for(int j = i-1; j >= n; j--){
                if(arr[j] >= arr[i]){
                    maxi += arr[i];
                }
                else break;
            }

            maxArea = max(maxArea,maxi);
        }

        return maxArea;
        
}*/


int largestRectangleArea(vector<int>& arr) {
      stack<int> st;
      int n = arr.size();
      vector<int> pse(n,-1);
      vector<int> nse(n,n);
      int maxArea = INT_MIN;

    // Previous Smaller Element

      for(int i=0;i<n;i++){
          while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
          }

          if(!st.empty()){
            pse[i] = st.top();
          }
          
          st.push(i);
      }

    // Next Saller Element

    while(!st.empty()) st.pop();

    for(int i = n-1;i >= 0;i--){
          while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
          }

          if(!st.empty()){
            nse[i] = st.top();
          }
          

          st.push(i);
      } 

      for(int i=0;i<n;i++){
         maxArea = max(maxArea,arr[i]*(nse[i] - pse[i] - 1));
      }       
      return maxArea;
}


int main(){
   vector<int> v{2,1,5,6,2,3};
   cout<<largestRectangleArea(v)<<endl;
}