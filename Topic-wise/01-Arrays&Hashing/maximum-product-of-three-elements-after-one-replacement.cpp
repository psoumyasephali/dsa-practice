// https://leetcode.com/contest/weekly-contest-474/problems/maximum-product-of-three-elements-after-one-replacement/description/

#include<iostream>
using namespace std;
/*
// Approach : 1 (Memory Limited Exceeded)
// TC : O(n2logn)
long long maxProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); // nlogn
    long long ans = LLONG_MIN;

    auto productOfThree = [&](vector<int> &arr){
        int n = arr.size();
        long long p1 = 1LL*arr[n-1]*arr[n-2]*arr[n-3];
        long long p2 = 1LL*arr[0]*arr[1]*arr[n-1];
        return max(p1, p2);
    };
    vector<int> candidates= {-100000, 100000};
    for(int i=0; i<n; i++){
        for(int val : candidates){
            vector<int> temp = nums; // O(n^2)
            temp[i] = val;
            sort(temp.begin(), temp.end());
            ans = max(ans, productOfThree(temp));
        }
    }
    return ans;
}
*/
// Approach : 2 (optimized)
// TC : O(nlogn)
using ll = long long;
long long maxProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    ll ans = (ll)nums[n-1]*nums[n-2]*100000;
    ans = max(ans, (ll)nums[0]*nums[n-1]*-100000);
    ans = max(ans, (ll)nums[0]*nums[1]*100000);
    return ans;
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
    long long res = maxProduct(vec);
    cout<<res<<endl;
    return 0;
}