
#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    int n1 = matrix.size();
    if (n1 == 0) return 0;  // Handle empty matrix
    int n2 = matrix[0].size();
    int maxArea = 0;

    // Width calculation
    vector<vector<int>> width(n1, vector<int>(n2, 0));
    for (int i = 0; i < n1; i++) {
        for (int j = n2-1; j >= 0 ; j--) {
            if (matrix[i][j] == '1') {
                width[i][j] = 1;
                if (j < n2-1 ) {
                    width[i][j] += width[i][j+1];
                }
            }else{
               width[i][j] == 0;
            }
        }
    }

cout << "Width matrix:" << endl;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << width[i][j] << " ";
        }
        cout << endl;
    }

//    int count = 1;
//    for(int j = 0; j < n2; j++){
//       stack<int> st;
//       for(int i=0;i<n1;i++){
//          if(!st.empty() && width[i][j] == st.top()){
//             count++;
//             st.pop();
//             st.push(width[i][j]);
//          }else{
//              if(!st.empty()){
//                if(!st.empty()) st.pop();
//              }
//              st.push(width[i][j]);
//              count = 1;
//          }
//          maxArea = max(maxArea,width[i][j]*count);
//       }
//    }

//   return maxArea;
return 0;
}

int main() {
    vector<vector<char>> matrix{
        {'1', '1', '0', '1'},
        {'1', '1', '0', '1',},
        {'1', '1', '1', '1'},
    };

    cout<<maximalRectangle(matrix)<<endl;;

    return 0;
}


