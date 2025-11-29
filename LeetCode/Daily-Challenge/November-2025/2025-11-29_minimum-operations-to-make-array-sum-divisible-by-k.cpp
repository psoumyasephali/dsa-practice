// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-27

#include<iostream>
#include<numeric>
using namespace std;


int minOperations(vector<int>& nums, int k) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int rem = total % k;
    if(rem == 0) return 0;
    int sum = 0;
    for(int num : nums){
        sum += num;
        if(sum >= rem)
            return rem;
    }
    return total;
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
    long long result = minOperations(nums, k);
    cout<<"Result: ";
    cout<<result<<endl;
    return 0;
}