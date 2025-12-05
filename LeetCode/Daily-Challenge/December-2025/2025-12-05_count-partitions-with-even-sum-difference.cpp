// https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/?envType=daily-question&envId=2025-12-05

#include<iostream>
#include<numeric>
using namespace std;

// Approach 1: Two pass solution
// TC: O(2*n)
// SC: O(1)
// int countPartitions(vector<int>& nums) {
//     int n = nums.size();
//     int totalSum = accumulate(nums.begin(), nums.end(), 0);
//     int left = 0, right = totalSum;
//     int count = 0;
//     for(int i=0; i<n-1; i++){
//         left += nums[i];
//         right -= nums[i];
//         if((left - right)%2 == 0) count++;
//     }
//     return count;
// }

//------------------------------------------------------------------
// Approach 2: One pass solution
// TC: O(n)
// SC: O(1)
int countPartitions(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    return totalSum % 2 == 0 ? n-1 : 0;
}


int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>vec(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    int res = countPartitions(vec);
    cout<<res<<endl;
    return 0;
}