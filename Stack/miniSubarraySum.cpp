#include<bits/stdc++.h>
using namespace std;
 int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        long long M = 1000000007;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               int mini = INT_MAX;
               for(int k = 0; k<=j;k++){
                mini = min(mini,arr[k]);
               }
               sum = (sum%M + mini%M)%M;

            }

        }
        return sum;
    }

int main(){
    vector<int> arr{3,1,2,4};
    cout<<sumSubarrayMins(arr)<<endl;
}