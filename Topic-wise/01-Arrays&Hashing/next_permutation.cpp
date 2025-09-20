#include<iostream>
using namespace std;


void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 1;
    while (i > 0 && nums[i-1] >= nums[i]) {
        i--;
    }
    
    if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    int j = nums.size() - 1;
    while (j >= i && nums[j] <= nums[i-1]) {
        j--;
    }
    
    swap(nums[i-1], nums[j]);
    reverse(nums.begin() + i, nums.end());        
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i]; //[1 5 8 4 7 6 5 3 1]
    }
    nextPermutation(vec);
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}