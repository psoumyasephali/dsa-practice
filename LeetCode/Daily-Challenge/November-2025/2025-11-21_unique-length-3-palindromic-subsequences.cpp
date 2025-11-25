// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-11-20

#include<iostream>
#include<unordered_set>
using namespace std;

int countPalindromicSubsequence(string s) {
    vector<int> first(26, -1);
    vector<int> last(26, -1);
    int ans = 0;

    for(int i=0; i<s.size(); i++){
        int curr = s[i] - 'a';
        if(first[curr] == -1){
            first[curr] = i;
        }
        last[curr] = i;
    }
    for(int i=0; i<26; i++){
        if(first[i] == -1) continue;

        unordered_set<char> between;
        for(int j=first[i]+1; j<last[i]; j++){
            between.insert(s[j]);
        }
        ans += between.size();
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int ans = countPalindromicSubsequence(s);
    cout<<ans<<endl;
    return 0;
}