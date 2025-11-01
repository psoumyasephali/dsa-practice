// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23
#include<iostream>
using namespace std;

bool hasSameDigits(string s) {
    while(s.size() > 2){
        string temp = "";
        for(int i=0; i<s.size()-1; i++){
            int sum = ((s[i]-'0')+(s[i+1]-'0'))%10;
            temp += (sum+'0');
        }
        s = temp;
    }
    return s[0]==s[1];
}


int main(){
    string s;
    cin>>s;
    bool res = hasSameDigits(s);
    if(res == true) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}