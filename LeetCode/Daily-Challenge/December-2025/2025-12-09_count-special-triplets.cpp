// https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-08

#include<iostream>
using namespace std;

// Approach 1: Using Two pass solution
// TC: O(2*n)
// SC: O(n)


int M = 1e9+7;
int specialTriplets(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp_left, mp_right;
    int res = 0;
    for(int &num : nums) mp_right[num]++;
    for(int &num : nums){
        mp_right[num]--;
        int l = mp_left[num*2];
        int r = mp_right[num*2];
        res = (res + (1LL*l*r)) % M;
        mp_left[num]++;
    }
    return res;
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
    int res = specialTriplets(vec);
    cout<<res<<endl;
    return 0;
}