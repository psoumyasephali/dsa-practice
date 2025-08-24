#include<iostream>
using namespace std;

//Using sliding window(TC: O(n))
int longestSubarray(vector<int>& nums) {
    int i=0,j=0, n=nums.size();
    int zeros=0, maxlen=0;
    while(j<n){
        if(nums[j]==0) zeros++;
        while(zeros > 1){
            if(nums[i] == 0){
                zeros--;
            }
            i++;
        }
        maxlen = max(maxlen, j-i);
        j++;
    }
    return maxlen;
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
    int res = longestSubarray(vec);
    cout<<res<<endl;
    return 0;
}

