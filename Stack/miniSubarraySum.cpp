#include<bits/stdc++.h>
using namespace std;
 int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
            int n = arr.size();
            long long M = 1000000007;
            for(int i=0;i<n;i++){
                int mini = INT_MAX;
                for(int j=i;j<n;j++){
                    mini = min(mini,arr[j]);
                    sum += mini;
                }
            }
            return sum;
        
    }

int main(){
    vector<int> arr{3,1,2,4};
    cout<<sumSubarrayMins(arr)<<endl;
}