#include<bits/stdc++.h>
using namespace std;


int longestOnes(vector<int>& nums, int key) {
          int maxLen = 0;
          int n = nums.size();
          int left = 0;
          int zeros = 0;
          
          for(int i=0;i<n;i++){
             
                if(nums[i] == 0){
                   zeros++;
                }
                if(zeros > key){
                   zeros -= 1;
                   while(nums[left] != 0) left++;
                   left++; 
                }
                maxLen = max(maxLen,i-left+1);
          }
         return maxLen;
    }

int main(){
    vector<int> v{1,0,0,0};
    cout<<longestOnes(v,2)<<endl; 
}