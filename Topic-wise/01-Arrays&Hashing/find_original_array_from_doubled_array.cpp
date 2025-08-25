// https://leetcode.com/problems/find-original-array-from-doubled-array/description/

// TC: O(nlogn), SC: O(n)

#include<iostream>
using namespace std;
/*
// Approach: 1
vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    if(n % 2 != 0) return {};

    unordered_map<int, int> mp;
    for(auto &val : changed){
        mp[val]++;
    }
    sort(changed.begin(), changed.end());

    vector<int> res;
    for(auto &val : changed){
        if(mp[val] == 0) continue;
        if(mp.find(2*val) != mp.end() && mp[2*val] > 0){
            if(val == 0){
                if(mp[2*val] >= 2){
                    mp[val] -= 2;
                    res.push_back(val);
                }
            }
            else{
                mp[val]--;
                mp[2*val]--;
                res.push_back(val);
            }
        }
        else{
            return {};
        }
    }
    return res.size()==n/2 ? res : vector<int>{};
}
*/
// Optimized version of Approach: 1
vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    if(n % 2 != 0) return {};

    unordered_map<int, int> mp;
    for(auto &val : changed){
        mp[val]++;
    }
    sort(changed.begin(), changed.end());
    vector<int> res;
    for(auto &val : changed){
        if(mp[val] == 0) continue;
        if(mp.find(2*val) == mp.end() || mp[2*val] == 0){
            return {};
        }
        res.push_back(val);
        mp[val]--;
        mp[2*val]--;
    }
    return res;
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
    vector<int> res = findOriginalArray(vec);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}

