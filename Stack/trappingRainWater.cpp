#include<bits/stdc++.h>
using namespace std;
    int trap(vector<int>& arr) {
    int leftMax = 0, rightMax = 0, total = 0;
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= leftMax) {
                leftMax = arr[left];
            } else {
                total += leftMax - arr[left];
            }
            left++;
        } else {
            if (arr[right] >= rightMax) {
                rightMax = arr[right];
            } else {
                total += rightMax - arr[right];
            }
            right--;
        }
    }

    return total;
}


int main(){
      vector<int> v{1,1,5,2,7,6,1,4,2,3};
      cout<<trap(v)<<endl;

}