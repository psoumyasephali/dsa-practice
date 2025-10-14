// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/?envType=daily-question&envId=2025-10-06

#include<iostream>
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> res;
    int m = potions.size();
    sort(potions.begin(), potions.end());
    for(int spell : spells){
        long long minPotion = (success+spell-1) / spell;
        int idx = lower_bound(potions.begin(),potions.end(),minPotion) - potions.begin();
        res.push_back(m-idx);
    }
    return res;
}


int main(){
    int n, m;
    long long success;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    vector<int>spells(n), potions(m);
    cout<<"Insert elements for spells: "<<endl;
    for(int i=0; i<n; i++){
        cin>>spells[i];
    }
    cout<<"Insert elements for potions: "<<endl;
    for(int i=0; i<m; i++){
        cin>>potions[i];
    }
    cout<<"Enter success: ";
    cin>>success;
    vector<int>res = successfulPairs(spells, potions, success);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}