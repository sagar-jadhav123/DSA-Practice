#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string S, int K){
    string ans = "";
    int n = S.size();
    if(n == K) return "0";

    for(auto ch : S){
      while(!ans.empty() && K > 0 && ans.back() > ch){
          ans.pop_back();
          K--;
      }
      ans.push_back(ch);
    }
        while(K > 0){
            ans.pop_back();
            K--;
        }
        while(ans.size() != 0 && ans[0] == '0'){
            ans.erase(ans.begin());
        }
        return ans.empty() ? "0": ans; 
}
int main(){
    string s = "1002991";
    int key = 3;
    cout<<removeKdigits(s,key)<<endl;
}