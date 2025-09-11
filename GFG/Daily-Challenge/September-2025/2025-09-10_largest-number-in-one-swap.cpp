#include<iostream>
using namespace std;

//Approach 1: bruteforce and backtrack
//TC : O(n^3) , gives TLE

// string largestSwap(string &s) {
//     int n = s.size();
//     string ans = s;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){ //O(n^2)
//             swap(s[i], s[j]);
//             ans = max(ans, s); //O(n)
//             //backtrack
//             swap(s[i], s[j]);
//         }
//     }
//     return ans;
// }

//Approach 2: using Greedy
//TC: O(n)
string largestSwap(string &s) {
    int n = s.size();
    int maxDigit = '0', maxIdx = -1, l=-1, r=-1;
    for(int i=n-1; i>=0; i--){
        if(s[i] > maxDigit){
            maxDigit = s[i];
            maxIdx = i;
        }
        else if(s[i] < maxDigit){
            l = i;
            r = maxIdx;
        }
    }
    if(l == -1) return s;
    swap(s[l], s[r]);
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<largestSwap(s)<<endl;
    return 0;
}