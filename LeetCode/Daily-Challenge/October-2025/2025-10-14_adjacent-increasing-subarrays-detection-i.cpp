// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14

#include<iostream>
using namespace std;

/*
// Bruteforce solution
//TC : O(n*n)
bool isIncreasing(vector<int> &nums, int s, int e){
    for(int i=s+1; i<e; i++){
        if(nums[i] <= nums[i-1])
            return false;
    }
    return true;
}
bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    for(int start=0; start+2*k <= n; start++){
        int first = isIncreasing(nums, start, start+k);
        int second = isIncreasing(nums, start+k, start+2*k);
        if(first && second) return true;
    }
    return false;
}
*/
// Efficient solution
// TC : O(n)
bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt=1, precnt=0, ans=0;
    for(int i=1; i<n; i++){
        if(nums[i] > nums[i-1]){
            cnt++;
        }
        else{
            precnt = cnt;
            cnt = 1;
        }
        ans = max(ans, min(precnt, cnt));
        ans = max(ans, cnt/2);
    }
    return ans >= k;
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
    int k; cin>>k;
    int res = hasIncreasingSubarrays(vec, k);
    cout<<res<<endl;
    return 0;
}