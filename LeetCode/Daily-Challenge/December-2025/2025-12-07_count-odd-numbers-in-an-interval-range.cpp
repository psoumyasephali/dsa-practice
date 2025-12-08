// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/?envType=daily-question&envId=2025-12-07

#include<iostream>
using namespace std;

// Approach 1: Bruteforce
// TC: O(high-low)

// int countOdds(int low, int high) {
//     int cnt=0;
//     for(int i=low; i<=high; i++){
//         if(i%2 == 1) cnt++;
//     }
//     return cnt;
// }

 
//--------------------------------------------------------------------------------
// Approach 2: using math trick
// TC: O(1)
int countOdds(int low, int high) {
    return (high+1)/2 - (low/2);
}

int main(){
    int high, low;
    cout<<"Enter high && low: ";
    cin>>high>>low;
    
    int res = countOdds(low, high);
    cout<<res<<endl;
    return 0;
}