// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/?envType=daily-question&envId=2025-12-08

#include<iostream>
using namespace std;
 
// Brain Teaser problem
// TC: O(n)
// SC: O(1)

int M = 1e9+7;
int countPermutations(vector<int>& complexity) {
    int n = complexity.size();
    long long res = 1;
    for(int i=1; i<n; i++){
        if(complexity[i] <= complexity[0]) return 0;
        res = (res*i)%M;
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
    int res = countPermutations(vec);
    cout<<res<<endl;
    return 0;
}