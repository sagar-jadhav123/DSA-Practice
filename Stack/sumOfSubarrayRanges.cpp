#include<bits/stdc++.h>
using namespace std;

    long long sumMiniSubArray(vector<int> arr){

       long long sumMini = 0;
       int n = arr.size();
       stack<int> st;
       vector<int> left(n);
       vector<int> right(n);

       for (int i = 0; i < n; i++)
       {
          while (!st.empty() && arr[st.top()] > arr[i])
          {
            st.pop();
          }

          left[i] = (st.empty()) ? i+1 : i - st.top();
          st.push(i);
          
       }
       while(!st.empty()) st.pop();

       for (int i = n-1; i >= 0; i--)
       {
          while (!st.empty() && arr[st.top()] >= arr[i])
          {
            st.pop();
          }

          right[i] = (st.empty()) ? n-i :  st.top() - i;
          st.push(i);
          
       }

       for(int i=0;i<n;i++){
         sumMini += (long long)right[i]*left[i]*arr[i];

       }
       return sumMini;

    }

      long long sumMaxiSubArray(vector<int> arr){

       long long sumMaxi = 0;
       int n = arr.size();
       stack<int> st;
       vector<int> left(n);
       vector<int> right(n);

       for (int i = 0; i < n; i++)
       {
          while (!st.empty() && arr[st.top()] < arr[i])
          {
            st.pop();
          }

          left[i] = (st.empty()) ? i+1 : i - st.top();
          st.push(i);
          
       }
       while(!st.empty()) st.pop();
       for (int i = n-1; i >= 0; i--)
       {
          while (!st.empty() && arr[st.top()] <= arr[i])
          {
            st.pop();
          }

          right[i] = (st.empty()) ? n-i :  st.top() - i;
          st.push(i);
          
       }

       for(int i=0;i<n;i++){
        sumMaxi += (long long)left[i]*right[i]*arr[i];
       }
       return sumMaxi;

    }

    long long subArrayRanges(vector<int>& nums) {
      return sumMaxiSubArray(nums) - sumMiniSubArray(nums);
}
int main(){
       vector<int> v{4,-2,-3,4,1};
       cout<<subArrayRanges(v)<<endl;
}