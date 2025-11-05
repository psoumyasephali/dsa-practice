// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2025-11-03

#include<iostream>
using namespace std;

// Approach: 1 (using two pointer - two pass solution)
// TC: O(n)
// SC: O(1)
/*
int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size();
    int totalTime = 0;
    int i=0, j=0;
    while(i<n && j<n){
        int currTotal = 0, currMax = 0;
        while(j<n && colors[i] == colors[j]){
            currTotal += neededTime[j];
            currMax = max(currMax, neededTime[j]);
            j++;
        }
        totalTime += currTotal - currMax;
        i = j;
    }
    return totalTime;
}
*/
// Approach: 2 (optimal single pass solution)
// TC: O(n)
// SC: O(1)
int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size();
    int totalTime = 0, currMaxTime = 0;

    for(int i=0; i<n; i++){
        if(i>0 && colors[i] != colors[i-1]){
            currMaxTime = 0;
        }

        totalTime += min(currMaxTime, neededTime[i]);
        currMaxTime = max(currMaxTime, neededTime[i]);
    }
    return totalTime;
}
int main(){
    string colors;
    cin>>colors;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>vec(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    int res = minCost(colors, vec);
    cout<<res<<endl;
    return 0;
}