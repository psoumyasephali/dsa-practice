// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include<iostream>
using namespace std;

// Using Binary Search
// TC: O(logn)
int findBound(vector<int> &nums, int target, bool isFirst){
    int left = 0, right = nums.size() - 1;
    int res = -1;

    while(left <= right){

        int mid = left+(right-left)/2;
        if(nums[mid] == target){
            res = mid;
            if(isFirst)
                right = mid - 1; 
            else
                left = mid + 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid-1;
        }
    }
    return res;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int first = findBound(nums, target, true);
    int last = findBound(nums, target, false);
    return {first, last};
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
    int target;
    cout<<"Enter target: ";
    cin>>target;
    vector<int> res = searchRange(vec, target);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}