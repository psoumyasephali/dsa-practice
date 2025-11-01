// https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

#include<iostream>
using namespace std;

// Approach:1 (using static comparator)
//TC : O(nlogn)
//SC : O(n)

static bool comparator(const pair<int, int>&a, const pair<int, int>&b){
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}
vector<int> topKFreq(vector<int> &arr, int k) {
    unordered_map<int, int>mp; 
    for(int &a : arr){  //O(n)
        mp[a]++;
    }
    vector<pair<int, int>>vec;
    for(auto &x : mp){  //O(m)
        vec.push_back({x.first, x.second});
    }
    sort(vec.begin(), vec.end(), comparator);   //O(mlogm)
    vector<int> ans;
    for(int i=0; i<k && (int)vec.size(); i++){  //O(k)
        ans.push_back(vec[i].first);
    }
    return ans;
}

/*
//Approach:2 (Using a lambda)
vector<int> topKFreq(vector<int> &arr, int k) {
    unordered_map<int, int>mp;
    for(int &a : arr){
        mp[a]++;
    }
    vector<pair<int, int>>vec;
    for(auto &x : mp){
        vec.push_back({x.first, x.second});
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int>&a, const pair<int, int>&b){
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
});
    vector<int> ans;
    for(int i=0; i<k && (int)vec.size(); i++){
        ans.push_back(vec[i].first);
    }
    return ans;
}

// Approach:3 (using minHeap(priority queue))
// TC : O(n+mlogk)
// Sc : O(n) //for hashmap and heap
vector<int> topKFreq(vector<int> &arr, int k) {
    unordered_map<int, int>mp;
    for(int &a : arr){
        mp[a]++;
    }
    // Define a minHeap, smallest frequency on top
    priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, //{frequency, number}
            greater<pair<int, int>>
            >minHeap;               //Smaller frequency = higher priority
        
    // Keep only top k frequencies
    for(auto &x : mp){
        minHeap.push({x.second, x.first});
        if((int)minHeap.size() > k){
            minHeap.pop();      //remove smaller frequency
        }
    }

    vector<int> ans;
    while(!minHeap.empty()){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    reverse(ans.begin(), ans.end());    //higher freq first
    return ans;
}
*/

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
    vector<int> res = topKFreq(vec, k);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    return 0;
}