/*
Filename: 2025-08-01_pascals_triangle.cpp 
Level: Easy
Problem link: https://leetcode.com/problems/pascals-triangle/

Approach:
1. Dynamic Programming (Bottom-Up)
2. TC: O(n^2), SC: O(n^2)
3. Built row by row using previous row values
*/


#include<iostream>
#include<vector>
using namespace std;

// Approach:1 
vector<vector<int>> generate(int numRows){
    vector<vector<int>> triangle(numRows);
    
    for(int i=0; i<numRows; i++){
        triangle[i].resize(i+1);
        triangle[i][0] = triangle[i][i] = 1;

        for(int j=1; j<i; j++){
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    return triangle;
}


// Approach:2 (Alternative Style)
vector<vector<int>> generate2(int numRows){
    vector<vector<int>> triangle;
    for(int i=0; i<numRows; i++){
        vector<int> row(i+1, 1);

        for(int j=1; j<i; j++){
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> res = generate(n);
    for(const auto& row : res){
        for (int val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}