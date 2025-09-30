// https://leetcode.com/problems/find-triangular-sum-of-an-array/description/?envType=daily-question&envId=2025-09-30

//TC: O(n^2)
#include<iostream>
using namespace std;

int triangularSum(vector<int>& nums) {
    int n = nums.size();
    while(n > 1){
        for(int i=1; i<n; i++){
            nums[i-1] = (nums[i-1] + nums[i]) % 10;
        }
        n--;
    }
    return nums[0];
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
    int res = triangularSum(vec);
    cout<<res<<endl;
    return 0;
}