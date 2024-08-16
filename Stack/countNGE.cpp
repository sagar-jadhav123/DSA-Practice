#include<bits/stdc++.h>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> ans;
        for(int i=0;i<queries;i++){
            int index = indices[i];
            int check = arr[index];
            int count = 0;
            
            for(int j=index+1;j<arr.size();j++){
                if(arr[j] > check){
                    count++;
                }
            }
            ans.push_back(count);
            
        }
        return ans;
       
    }

int main(){
     vector<int> arr{3, 4, 2, 7, 5, 8, 10, 6};
     vector<int> index{0,5};
     vector<int> ans = count_NGE(8,arr,2,index);

     for(auto val:ans){
        cout<<val<<" ";
     }
}