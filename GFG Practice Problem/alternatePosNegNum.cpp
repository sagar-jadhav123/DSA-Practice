#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr) {
        vector<int> p;
        vector<int> n;

        for(int i=0;i<arr.size();i++){
            if(arr[i] >= 0){
                p.push_back(arr[i]);
            }else{
                n.push_back(arr[i]);
            }
        }
        int pos = 0, neg = 0;
        int i = 0;
        while(pos < p.size() && neg < n.size()){
            arr[i++] = p[pos++];
            arr[i++] = n[neg++];
        }
        
        while(pos < p.size()){
            arr[i++] = p[pos++];
        }
        
         while(neg < n.size()){
            arr[i++] = n[neg++];
        }
        
        for(auto val : arr){
            cout<<val<<" ";
        }
}


int main(){
    vector<int> arr{9,-4, -2, -1, 5};
    rearrange(arr);

}