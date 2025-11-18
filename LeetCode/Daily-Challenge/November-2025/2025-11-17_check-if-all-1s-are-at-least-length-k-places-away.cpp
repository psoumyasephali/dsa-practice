// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17

#include<iostream>
using namespace std;

// TC: O(n)
bool kLengthApart(vector<int>& nums, int k) {
    int n = nums.size();
    int i=-1;
    bool flag = true;
    for(int j=0; j<n; j++){
        if(nums[j] == 1){
            if(i == -1){
                i = j;
                continue;
            }
            if(j-i >= k+1){
                i = j;
            } 
            else flag = false;
        }
    }
    return flag == true;
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
    int k;
    cout<<"Enter k: ";
    cin>>k;
    int res = kLengthApart(vec, k);
    cout<<res<<endl;
    return 0;
}