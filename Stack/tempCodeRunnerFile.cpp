#include<bits/stdc++.h>
using namespace std;

int findZeroes(int arr[], int n, int m) {
        int maxLen = 0;

        for(int i=0;i<n;i++){
            int zero = 0;
            for(int j = i