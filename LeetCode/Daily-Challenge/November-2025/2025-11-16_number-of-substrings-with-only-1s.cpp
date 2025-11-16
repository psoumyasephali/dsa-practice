// https://leetcode.com/problems/number-of-substrings-with-only-1s/?envType=daily-question&envId=2025-11-16
#include<iostream>
using namespace std;

static constexpr int mod = int(1E9) + 7;
int numSub(string s) {
    int n = s.size();
    long long ans = 0;
    int i=0;
    while (i < n) {
        if (s[i] == '0') {
            i++;
            continue;
        }
        long long cnt = 0;
        while (i < n && s[i] == '1') {
            cnt++;
            i++;
        }
        ans = (ans + cnt*(cnt+1)/2) % mod;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    int ans = numSub(s);
    cout<<ans<<endl;
    return 0;
}