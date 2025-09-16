#include<iostream>
using namespace std;

// for non-negative integers, sliding window works
// for all integers, we use prefix sum and hash map

/*
// Approach: 1(Bruteforce)
// TC: O(n^2)
int longestSubarray(vector<int> &arr, int k){
    int n = arr.size();
    int maxlen = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == k){
                maxlen = max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}

// Approach: 2(sliding window) //for non-negative integer
//TC: O(n)
int longestSubarray(vector<int> &arr, int k){
    int n = arr.size();
    int i=0, j=0, sum=0, maxlen=0;
    while(j<n){
        sum += arr[j];
        if(sum>k && i<=j){
            sum -= arr[i];
            i++;
        }
        if(sum == k){
            maxlen = max(maxlen, j-i+1);
        }
        j++;
    }
    return maxlen;
}
/*/
// Approach 3:(using prefix sum and hash map)
// TC:O(n)

int longestSubarray(vector<int>&arr, int k){
    int n = arr.size();
    int maxlen=0, prefixSum = 0;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        prefixSum += arr[i];
        if(prefixSum == k){
            maxlen = i+1;
        }
        else if(mp.find(prefixSum - k) != mp.end()){
            maxlen = max(maxlen, i-mp[prefixSum-k]);
        }
        if(mp.find(prefixSum) == mp.end()){
            mp[prefixSum] = i;
        }
    }
    return maxlen;
}


int main(){
    int n, k;
    cout<<"Enter n, k: ";
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int res = longestSubarray(arr, k);
    cout<<res<<endl;
    return 0;
}