// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16
//using stack
//TC: O(nlog(max(num)))


#include<iostream>
#include<vector>
#include<stack>
#include<numeric>   // for std::gcd and std::lcm
#include<algorithm> // for reverse
using namespace std;


vector<int> replaceNonCoprimes(vector<int>& nums) {
    stack<int> st;
    for(int num : nums){
        while(!st.empty() && std::gcd(st.top(), num) > 1){
            num = std::lcm(st.top(), num);
            st.pop();
        }
        st.push(num);
    }
    vector<int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}


int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    vector<int> res = replaceNonCoprimes(vec);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}