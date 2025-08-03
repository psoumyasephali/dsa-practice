/*
Filename: 2025-08-02_rearranging_fruits.cpp 
Level: Hard
Problem link: https://leetcode.com/problems/rearranging-fruits/

Approach: Greedy
TC: O(nlogn), SC: O(n)
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm> //for sort, min element
#include<cmath> //for abs
using namespace std;


long long minCost(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> freq;

    for(int x : basket1) freq[x]++;
    for(int x : basket2) freq[x]--;
    vector<int> extra;
    long long cost = 0;

    for(auto &x: freq){
        int val = x.first;
        int count = x.second;
        if(count %2 != 0)   return -1;
        for(int i=0; i<abs(count)/2; i++)
            extra.push_back(val);
    }
    
    if(extra.empty()) return 0;

    int global_min = min(*min_element(basket1.begin(), basket1.end()),
    *min_element(basket2.begin(), basket2.end()));

    sort(extra.begin(), extra.end());
    int n = extra.size()/2;
    for(int i=0; i<n; i++){
        cost += min(1LL*extra[i], 2LL*global_min);
    }
    return cost;
}
int main(){
    int n;
    cin>>n;
    vector<int> v1(n), v2(n);
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    for(int i=0; i<n; i++){
        cin>>v2[i];
    }
    long long cost = minCost(v1, v2);
    cout<<cost<<endl;
    return 0;
}