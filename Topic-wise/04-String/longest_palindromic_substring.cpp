// https://leetcode.com/problems/longest-palindromic-substring/


#include<iostream>
using namespace std;

// Approach: 1 (using bruteforce)
//TC : O(n^3)
bool isPalindrome(string &s, int l, int r){
    while(l<r){
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}
string longestPalindrome(string s) {
    int n = s.size(), maxlen=1, start=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(isPalindrome(s, i, j)){
                int len = j-i+1;
                if(len > maxlen){
                    maxlen = len;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxlen);
}

// Approach:2 (Expand arround centre)
// TC : O(n^2)
/*string longestPalindrome(string s) {
    int n = s.size();
    int start=0, maxlen=1;

    auto expand = [&](int l, int r){
        while(l>=0 && r<n && s[l] == s[r]){
            if(r-l+1 > maxlen){
                maxlen = r-l+1;
                start = l;
            }
            l--; r++;
        }
    };
    for(int i=0; i<n; i++){
        expand(i, i); //odd length
        expand(i, i+1); //even length
    }
    return s.substr(start, maxlen);
}*/ 

// Approach: 3(Manacher's Algorithm)
// TC:O(n)
/*string longestPalindrome(string s) {
    // Step 1: Transform string
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int n = t.size();
    vector<int> P(n, 0); // palindrome radius
    int C = 0, R = 0;    // center and right boundary
    int maxLen = 0, centerIndex = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * C - i;

        if (i < R)
            P[i] = min(R - i, P[mirror]);

        // Expand around center i
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && 
                t[i + P[i] + 1] == t[i - P[i] - 1])
            P[i]++;

        // Update center if expanded beyond R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract substring (remove '#')
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}*/
int main(){
    string s;
    cin>>s;
    string res = longestPalindrome(s);
    cout<<res<<endl;
    return 0;
}