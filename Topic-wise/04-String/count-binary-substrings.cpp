// https://leetcode.com/problems/count-binary-substrings/submissions/1830081917/

#include<iostream>
using namespace std;

int countBinarySubstrings(string s) {
    int n = s.length();
    vector<int> group;
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]) cnt++;
        else{
            group.push_back(cnt);
            cnt=1;
        }
    }
    group.push_back(cnt);
    int ans = 0;
    for(int i=0; i<group.size()-1; i++){
        ans += min(group[i], group[i+1]);
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int ans = countBinarySubstrings(s);
    cout<<ans<<endl;
    return 0;
}