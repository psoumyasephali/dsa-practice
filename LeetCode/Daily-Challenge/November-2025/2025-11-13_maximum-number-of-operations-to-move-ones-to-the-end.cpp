// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13

#include<iostream>
using namespace std;

// TC: O(n)
int maxOperations(string s) {
    int n = s.length();
    int i=0, res=0, count1seen = 0;
    while(i<n){
        if(s[i] == '0'){
            res += count1seen;
            while(i<n && s[i] == '0') i++; // moved till first '1' occurence
        }else{
            count1seen++;
            i++;
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    int res = maxOperations(s);
    cout<<res<<endl;
    return 0;
}