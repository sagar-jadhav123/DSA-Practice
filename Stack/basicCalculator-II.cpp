#include<bits/stdc++.h>
using namespace std;


int calculate(string s){
     int result = 0;
     int num = 0;
     int sign = '+';
     int last_num = 0;

     for(int i=0;i<s.size();i++){
         char ch = s[i];

         if(isdigit(ch)){
            num = num*10 + (ch - '0');
         }

         if(!isdigit(ch) && ch != ' ' || i == s.size()-1){
            if(sign == '+' || sign == '-'){
               result += last_num;
               last_num = sign == '+' ? num : -num;
            }
            else if(sign == '*'){
                last_num *= num;
            }
            else if(sign == '/'){
                last_num /= num;
            }
            sign = ch;
            num = 0;
         }
     }

     result += last_num;

     return result;
}





















// Brute Force Approach
// int calculate(string s) {
//       int result = 0;
//       int num = 0;
//       stack<int> st;
//       char sign = '+';

//       for(int i = 0; i< s.size(); i++){
//         char ch = s[i];

//         if(isdigit(ch)){
//             num = num*10 + (ch - '0');
//         }
//         else if(!isdigit(ch) && ch != ' ' || i == s.size()-1){
//             if(sign == '+'){
//                 st.push(num);
//             }
//             else if(sign == '-'){
//                 st.push(-num);
//             }
//             else if(sign == '*'){
//                 int top = st.top();
//                 st.pop();
//                 st.push(top*num);
//             }
//             else if(sign == '/'){
//                 int top = st.top();
//                 st.pop();
//                 st.push(top/num);
//             }
//             sign = ch;
//             num = 0;
//         }
        
//       }
//       while(!st.empty()){
//            result += st.top();
//            st.pop();
//       }  
      
//       return result;
// }

int main(){
    string  str =" 3+5 / 2 ";
    cout<<calculate(str)<<endl;;
}