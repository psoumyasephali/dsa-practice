// https://leetcode.com/problems/count-number-of-trapezoids-i/?envType=daily-question&envId=2025-12-02

#include<iostream>
#include<map>
using namespace std;


// Approach 1: 
// TC: O(n)
// SC: O(n)

int countTrapezoids(vector<vector<int>>& points) {
    unordered_map<int, int> mp;
    const int mod = 1e9+7;
    long long ans = 0, sum = 0;

    for(auto point : points){
        mp[point[1]]++;
    }
    
    for(auto &p : mp){
        int x = p.second;
        long long edge = (long long)x*(x-1)/2;
        ans += edge * sum;
        sum += edge;
    }
    return ans % mod;
}

// int countTrapezoids(vector<vector<int>>& points) {
//     map<int, int> mp;
//     const int mod = 1e9+7;
//     long long ans = 0, sumEdges = 0;

//     for(auto &p : points){
//         mp[p[1]]++;
//     }
    
//     for(auto &p : mp){
//         int cnt = p.second;
//         long long edges = (1LL * cnt * (cnt - 1) / 2) % mod;
//         ans = (ans + (edges * sumEdges) % mod) % mod;
//         sumEdges = (sumEdges + edges) % mod;
//     }
//     return ans % mod;
// }

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<vector<int>>vec(n, vector<int>(2));
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>vec[i][j];
        }
    }
    int res = countTrapezoids(vec);
    cout<<res<<endl;
    return 0;
}