#include<iostream>
using namespace std;

int myAtoi(string s) {
    int i=0, n = s.size();  
    long long ans = 0;
    bool neg = false;

    //skip leading spaces
    while(i<n && s[i] == ' ') i++;

    //handle sign
    if(i<n && (s[i] == '+' || s[i] == '-')){
        neg = (s[i] == '-');
        i++;
    }
    // parse digits
    while(i<n && isdigit(s[i])){
        int dig = s[i] - '0';
        // check overflow before multiplying
        if(ans > (INT_MAX - dig) / 10)
            return neg ? INT_MIN : INT_MAX;

        ans = ans*10+dig;
        i++;         
    }
    if(neg) ans = -ans;
    return (int)ans;
}

int main(){
    string s;
    cin>>s;
    int res = myAtoi(s);
    cout<<res<<endl;
    return 0;
}