// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/?envType=daily-question&envId=2025-11-27

#include<iostream>
using namespace std;

long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefSum(n);
    prefSum[0] = nums[0];
    for(int i=1; i<n; i++){
        prefSum[i] = prefSum[i-1] + nums[i];
    }
    long long result = LLONG_MIN;
    for(int start=0; start<k; start++){
        long long currSum = 0;
        int i = start;
        while(i<n && i+k-1<n){
            int j = i+k-1;
            long long subSum = prefSum[j] - ((i>0) ? prefSum[i-1] : 0);
            currSum = max(subSum, currSum + subSum);
            result = max(result, currSum);
            i+=k;
        }
    }
    return result;
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
    int k; 
    cout<<"Enter k: ";
    cin>>k;
    long long result = maxSubarraySum(nums, k);
    cout<<"Result: ";
    cout<<result<<endl;
    return 0;
}