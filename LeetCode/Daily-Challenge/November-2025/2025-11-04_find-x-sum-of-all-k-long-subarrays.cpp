// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/?envType=daily-question&envId=2025-11-04
#include<iostream>
using namespace std;

// Approach: (soring + hashtable)
// TC: O(n * klogk)
// SC: O(k)

vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> ans;
    for(int i=0; i<=n-k; i++){
        unordered_map<int, int> mp;
        for(int j=i; j<i+k; j++){
            mp[nums[j]]++;
        }
        vector<pair<int, int>> freq;
        for(const auto & p : mp){
            freq.emplace_back(p.second, p.first);
        }
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());
        int xsum = 0;
        for(int j=0; j<x && j<freq.size(); j++){
            xsum += freq[j].first * freq[j].second;
        }
        ans.push_back(xsum);
    }
    return ans;
}

int main(){
    int n, k, x;
    cout<<"Enter n, k, x: ";
    cin>>n>>k>>x;
    vector<int>vec(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    vector<int> res = findXSum(vec, k, x);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    return 0;
}