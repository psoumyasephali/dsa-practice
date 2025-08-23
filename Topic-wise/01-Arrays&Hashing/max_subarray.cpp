#include<iostream>
using namespace std;

//Kadane's algorithm: O(n)
int maxSubArray(vector<int>& nums) {
    bool allneg = true;
    int largest = INT_MIN;
    for(int num : nums){
        if(num > 0){
            allneg = false;
        }
        largest = max(largest, num);
    }
    if(allneg) return largest;
    int cs = 0, ans = 0;
    for(int num : nums){
        cs += num;
        if(cs < 0){
            cs = 0;
        }
        ans = max(ans, cs);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    cout<<maxSubArray(vec)<<endl;
    return 0;
}