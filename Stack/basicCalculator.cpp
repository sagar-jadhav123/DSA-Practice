#include<bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int result = 0;
    int num = 0;
    int sign = 1;  // 1 for positive, -1 for negative
    
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        
        if (isdigit(c)) {
            // Build the number for multi-digit numbers
            num = num * 10 + (c - '0');
        } 
        else if (c == '+') {
            // Add the last number to the result with the last sign
            result += sign * num;
            num = 0;  // Reset the number
            sign = 1;  // Set sign for the next number
        } 
        else if (c == '-') {
            // Add the last number to the result with the last sign
            result += sign * num;
            num = 0;
            sign = -1;  // Set sign for the next number
        } 
        else if (c == '(') {
            // Push the current result and the sign onto the stack
            st.push(result);
            st.push(sign);
            // Reset result and sign for the new sub-expression
            result = 0;
            sign = 1;
        } 
        else if (c == ')') {
            // Add the current number to the result
            result += sign * num;
            num = 0;
            // Pop the sign and apply it to the result
            result *= st.top();  // This is the sign before the parenthesis
            st.pop();
            // Add the previous result before the parenthesis
            result += st.top();  
            st.pop();
        }
    }
    
    // Add the last number to the result
    result += sign * num;
    
    return result;
}

int main() {
    string s = " 2-1 + 2 ";
    cout << calculate(s) << endl;
    return 0;
}
