// Stack problem
#include<bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& op) {
      stack<int> st;
      int sum = 0;
      for(int i=0;i<op.size();i++){
        if(op[i] == "+"){
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            int temp = top1 + top2;
            st.push(top1);
            st.push(temp);
        }else if(op[i] == "C"){
            st.pop();
        }else if(op[i] == "D"){
            st.push(2*st.top());
        }else{
            int num = stoi(op[i]);
            st.push(num);
        }
      }  
      while(!st.empty()){
        int num = st.top();
        st.pop();
        sum += num;
      }
      return sum;
    }
int main(){
   vector<string> ops = {"5","2","C","D","+"};
   cout<<calPoints(ops)<<endl;
}