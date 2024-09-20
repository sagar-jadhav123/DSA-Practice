#include<bits/stdc++.h>
using namespace std;

    string longestCommonPrefix(vector<string> arr){
            int minSize = INT_MAX;
            string str = "";
            

            for(auto val : arr){
                int len = val.size();
                minSize = min(minSize,len);
            }
            
            for(int i=0;i<minSize;i++){
                char ch = arr[0][i];
                for(int j = 1; j < arr.size();j++){
                     if(arr[j][i] != ch){
                        return str.empty()? "-1" : str;
                     }
                }
                str += ch;
            }
        
            return (str.size() == 0)? "-1" : str ;
    }

int main(){
    vector<string> v{"geeksforgeeks", "geeks"};
    string ans = longestCommonPrefix(v);
    cout<<ans<<endl;
}