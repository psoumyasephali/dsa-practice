// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16
//using stack
//TC: O(nlog(max(num)))


#include<iostream>
#include<vector>
#include<stack>
#include<numeric>   // for std::gcd and std::lcm
#include<algorithm> // for reverse
using namespace std;
// g++ -std=c++17 2025-09-16_replace-non-coprime-numbers-in-array.cpp 


// Manual GCD implementation
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Manual LCM implementation
int lcm(int a, int b) {
    return abs(a / gcd(a, b) * b);
}

vector<int> replaceNonCoprimes(vector<int>& nums) {
    stack<int> st;
    for(int num : nums){
        while(!st.empty() && gcd(st.top(), num) > 1){ 
            num = lcm(st.top(), num);
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