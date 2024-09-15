#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans,int key) {
            if (index >= nums.size()) {
                if(output.size() == key){
                ans.push_back(output);
                }
                return;
            }
            
            // exclude
            solve(nums, output, index + 1, ans,key);
            // include
            int element = nums[index];
            output.push_back(element);
            solve(nums, output, index + 1, ans,key);
    }
    int maxValue(vector<int>& nums, int k) {
        int maxValue = INT_MIN;
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        int key = 2*k;
        solve(nums, output, index, ans, key);
        for(int i=0;i<ans.size();i++){
            vector<int> temp = ans[i];
            vector<int> temp2;
            if(temp.size() > 2){
            for(int i=0;i<temp.size();i+=2){
                int a = temp[i] | temp[i+1];
                temp2.push_back(a);
            }
            }else{
                 for(auto val : temp){
                    temp2.push_back(val);
                 }
            }
            int b = 0;
            for(auto val : temp2){
                b ^= val;
            }
            maxValue = max(maxValue,b);
        }
        return maxValue;
    }

    int main(){
        vector<int> v{4,2,5,6,7};
        cout<<maxValue(v,2)<<endl;
    }