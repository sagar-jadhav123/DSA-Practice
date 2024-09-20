#include<bits/stdc++.h>
using namespace std;



 int lengthOfLongestSubstring(string s) {
       vector<int> index(128, -1);
       int l = 0;
       int maxL = 0;

       for(int i=0;i<s.size();i++){
        if(index[s[i]] != -1){
            l = max(l,index[s[i]]+1);
        }
        index[s[i]] = i;
        maxL = max(maxL,i-l+1);
       }     
       return maxL;
    }

//  int lengthOfLongestSubstring(string s) {
//       string str = "";
//       int maxLen = 0;
//       int n = s.size();
      
//       int i =0;
//       while(i < n-1){
//          str = "";
//          str += s[i];

//          int j = i+1;

//          while(j < n){
//              if(str.find(s[j]) == string :: npos){
//                 str += s[j];
//              }
//              else{
//                 while(s[i] != s[j]){
//                     i++;
//                 }
//                 break;
//              }
//              j++;
//          } 
//          i++;
//         int len = str.size();
//         maxLen = max(maxLen,len);
//       }
//       return maxLen;
//  }

int main(){
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s)<<endl;
}