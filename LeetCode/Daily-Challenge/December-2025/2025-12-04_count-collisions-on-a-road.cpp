// https://leetcode.com/problems/count-collisions-on-a-road/submissions/1847118605/?envType=daily-question&envId=2025-12-04

#include<iostream>
using namespace std;

// Approach 1: Counting
// TC: O(n)
// SC: O(1)

int countCollisions(string directions) {
    int n = directions.size();
    int collisions = 0;
    int i=0, j=n-1;
    while(i<n && directions[i] == 'L') i++;
    
    while(j>=0 && directions[j] == 'R') j--;
    
    while(i<=j){
        if(directions[i] != 'S'){
            collisions++;
        }
        i++;
    }
    return collisions;
}

int main(){
    string s;
    cin>>s;
    int result = countCollisions(s);
    cout<<result<<endl;
    return 0;
}