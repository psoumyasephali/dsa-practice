// https://leetcode.com/problems/binary-prefix-divisible-by-5/submissions/1838985941/?envType=daily-question&envId=2025-11-25

#include<iostream>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> res;
    int x = 0;
    for(int num : nums){
        x = (x * 2 + num) % 5;  
        res.push_back(x == 0);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int>vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    vector<bool> res = prefixesDivBy5(vec);
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}