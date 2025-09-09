#include<iostream>
using namespace std;

// https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/
int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int n = nums.size();
    int maxCnt = 0;
    for(int i=0; i<n; i++){
        if(nums[i]%2 == 0 && nums[i] <= threshold){
            int cnt = 1;
            int prev = nums[i]%2;

            for(int j=i+1; j<n; j++){
                if(nums[j] > threshold || nums[j]%2 == prev){
                    break;
                }
                cnt++;
                prev = nums[j]%2;
            }
            maxCnt = max(maxCnt, cnt);
        }
    }
    return maxCnt;
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
    int threshold;
    cin>>threshold;
    int res = longestAlternatingSubarray(vec, threshold);
    cout<<res<<endl;
    return 0;
}
