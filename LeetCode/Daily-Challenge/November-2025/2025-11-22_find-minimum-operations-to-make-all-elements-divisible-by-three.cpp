// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/?envType=daily-question&envId=2025-11-20

#include<iostream>
using namespace std;

// TC: O(n)
int minimumOperations(vector<int>& nums) {
    int ans = 0;
    for(int num : nums){
        int rem = num % 3;
        ans += min(rem, 3-rem);
    }
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
    int res = minimumOperations(vec);
    cout<<res<<endl;
    return 0;
}