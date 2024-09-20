#include<bits/stdc++.h>
using namespace std;

 int findFinalValue(vector<int>& nums, int original) {

        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(s.find(original) != s.end()){
               original *= 2;
            }
            else return original;
        }
        return original;
        
}

int main(){
     vector<int> v{5,3,6,1,12};
     cout<<findFinalValue(v,3)<<endl;
}