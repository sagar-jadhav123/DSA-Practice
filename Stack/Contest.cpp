#include<bits/stdc++.h>
using namespace std;

vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for(int i=1;i<height.size();i++){
            if(height[i-1] > threshold){
                ans.push_back(i);
            }
        }
        return ans;
    }

int main(){
     vector<int> v{10,1,10,1,10};
     vector<int> ans = stableMountains(v,3);
     for(auto val : ans){
        cout<<val<<" ";
     }
}