#include<bits/stdc++.h>
using namespace std;

        // Best Solution

    int findZeroes(int arr[], int n, int m) {
        int maxLen = 0;
        int l = 0;
        int zero = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                    zero++;
            }
            if(zero > m){
               if(arr[l] == 0){
                   zero -= 1;
               }
               l++;
            }
            else if(zero <= m){
                maxLen = max(maxLen,i - l + 1);
            }
            
        }
        return maxLen;
} 

int main(){
     int arr[] = {1, 0, 1};
     int m = 1;
     cout<<findZeroes(arr,3,m)<<endl;
}


// int findZeroes(int arr[], int n, int m) {
//         int maxLen = 0;

//         for(int i=0;i<n;i++){
//             int zero = 0;
//             for(int j = i; j<n; j++){
//                 if(arr[j] == 0){
//                     zero++;
//                 }
//                 if(zero <= m){
//                     maxLen = max(maxLen,j-i+1);
//                 }
//                 else break;
//             }
//         }
//         return maxLen;
// } 

// // Better Approach Sliding Window

// int findZeroes(int arr[], int n, int m) {
//         int maxLen = 0;
//         int l = 0;
//         int zero = 0;
//         for(int i=0;i<n;i++){
//             if(arr[i] == 0){
//                     zero++;
//             }
//             if(zero > m){
//                 while(arr[l] != 0) l++;
//                 zero -= 1;
//                 l++;
//             }
            
//             maxLen = max(maxLen,i - l + 1);
//         }
//         return maxLen;
