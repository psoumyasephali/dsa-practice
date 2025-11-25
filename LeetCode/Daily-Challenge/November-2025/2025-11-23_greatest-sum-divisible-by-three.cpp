// https://leetcode.com/problems/greatest-sum-divisible-by-three/description/?envType=daily-question&envId=2025-11-23
#include<iostream>
using namespace std;

// Approach: Greedy
// TC: O(nlogn)

int maxSumDivThree(vector<int>& nums) {
    vector<int> rem1, rem2;
    int sum = 0;
    for(int num : nums){
        sum += num;
        if(num % 3 == 1) rem1.push_back(num);
        if(num % 3 == 2) rem2.push_back(num);
    }
    if(sum%3 == 0) return sum;

    sort(rem1.begin(), rem1.end());
    sort(rem2.begin(), rem2.end());

    int ans = 0;
    if(sum % 3 == 1){
        int remove1 = rem1.size()>=1 ? rem1[0] : INT_MAX;
        int remove2 = rem2.size()>=2 ? rem2[0] + rem2[1] : INT_MAX;
        ans = sum - min(remove1, remove2);
    }
    else{ //sum%3 == 2
        int remove1 = rem2.size()>=1 ? rem2[0] : INT_MAX;
        int remove2 = rem1.size()>=2 ? rem1[0] + rem1[1] : INT_MAX;
        ans = sum - min(remove1, remove2); 
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
    int res = maxSumDivThree(vec);
    cout<<res<<endl;
    return 0;
}