#include<bits/stdc++.h>
using namespace std;

// Brute Force 

// bool containsNearbyDuplicate(vector<int>& nums, int k) {
//      for(int i=0;i<nums.size();i++){
//          int curr = nums[i];
//           for(int j = i+1; j < nums.size(); j++){
//             if(nums[j] == curr){
//                 if(abs(j-i) == k) return true;
//             }
//           }
//      }  
//      return false;  
// }

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(abs(i - m[nums[i]]) <= k){
                  if(m[nums[i]] <= k) return true;
            }
            m[nums[i]] = i; 
        }
        return false;
}



int main(){
    vector<int> v{1,2,3,1,2,3};
    cout<<containsNearbyDuplicate(v,2)<<endl;
}