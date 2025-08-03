/*
Filename: 2025-08-03_maximum_fruits_harvested_after_atmost_ksteps.cpp
Level: Hard
Problem link: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/


Approach: 
Binary search + prefix sum
TC: O(n+klogn), SC: O(n)
*/


#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k){
    int n = fruits.size();
    vector<int> prefixSum(n), indices(n);

    //Build prefix sum and extract indices
    for(int i=0; i<n; i++){
        indices[i] = fruits[i][0];
        prefixSum[i] = fruits[i][1] + (i>0 ? prefixSum[i-1] : 0);
    }

    int maxFruits = 0;
    for(int d=0; d<=k/2; d++){
        int remain = k-2*d;
        //case 1: move left d, then right
        int i = startPos - d;
        int j = startPos + remain;

        int left = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
        int right = upper_bound(indices.begin(), indices.end(), j) - indices.begin()-1;
        
        if(left <= right){
            int total = prefixSum[right] - (left>0 ? prefixSum[left-1] : 0);
            maxFruits = max(maxFruits, total);
        }
        //case 2: move right d, then left(k-2d)
        i = startPos - remain;
        j = startPos + d;

        int left2 = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
        int right2 = upper_bound(indices.begin(), indices.end(), j) - indices.begin()-1;
        
        if(left2 <= right2){
            int total = prefixSum[right2] - (left2>0 ? prefixSum[left2-1] : 0);
            maxFruits = max(maxFruits, total);
        }
    }
    return maxFruits;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n, vector<int> (2));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>vec[i][j];
        }
    }
    int startPos, k;
    cin>>startPos>>k;

    int maxFruits = maxTotalFruits(vec, startPos, k);
    cout<<maxFruits<<endl;
    
    return 0;
}