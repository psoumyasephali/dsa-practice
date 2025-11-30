// https://leetcode.com/problems/make-sum-divisible-by-p/editorial/?envType=daily-question&envId=2025-11-27

#include<iostream>
#include<numeric>
using namespace std;

// // Approach 1: Bruteforce (TLE)
// // TC: O(n^2)
// int minSubarray(vector<int>& nums, int p) {
//     int n = nums.size();
//     long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
//     if(totalSum % p == 0) return 0;
//     int minlen = n;
//     for(int i=0; i<n; i++){
//         long long subSum = 0;
//         for(int j=i; j<n; j++){
//             subSum += nums[j];
//             long long remainingSum = totalSum - subSum;
//             if(remainingSum % p == 0){
//                 minlen = min(minlen, j-i+1);
//             }
//         }
//     }
//     return minlen==n ? -1 : minlen;
// }

//--------------------------------------------------------
// Approach 2: Prefix Sum Modulo
// TC: O(n)
// SC: O(n)
int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    int totalSum = 0;
    for(int num : nums){
        totalSum = (totalSum + num) % p;
    }
    int target = totalSum % p;
    if(target == 0) return 0;
    unordered_map<int, int> modMap;
    modMap[0] = -1;
    int currSum = 0, minlen = n;
    for(int i=0; i<n; i++){
        currSum = (currSum + nums[i]) % p;
        // Calculate what we need to remove 
        int needed = (currSum - target + p) % p;
        // If we have seen the needed remainder, we can consider this subarray
        if(modMap.find(needed) != modMap.end()){
                minlen = min(minlen, i - modMap[needed]);
        }
        // Store the current remainder and index
        modMap[currSum] = i;
    }
    return minlen==n ? -1 : minlen;
}


int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int p; 
    cout<<"Enter p: ";
    cin>>p;
    long long result = minSubarray(nums, p);
    cout<<"Result: ";
    cout<<result<<endl;
    return 0;
}