#include<iostream>
using namespace std;

// Sort an array of 0s, 1s and 2s - Dutch National Flag Problem

// Approach: 1 
//TC : O(n)
void sortColors1(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(3, 0);
    for(int num : nums){
        freq[num]++;
    }
    int idx = 0;
    for(int i=0; i<3; i++){
        while(freq[i]--){
            nums[idx++]=i;
        }
    }
}


// Approach: 2(Inplace sort, using 3 pointers), one pass solution
//TC : O(n)
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(nums[mid] == 0){
            swap(nums[low++], nums[mid++]);
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high--]);
        }
    }
}

int main(){
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    sortColors(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}