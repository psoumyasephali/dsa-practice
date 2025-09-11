#include<iostream>
#include<cctype>
using namespace std;

bool isPalindrome(string s) {
    int start = 0, end = s.size()-1;
    while(start <= end){
    while(start<end && !isalnum(s[start])){
        start++;
    }
    while((start<end && !isalnum(s[end]))){
        end--;
    }
    if(tolower(s[start]) != tolower(s[end])) 
        return false;
    start++, end--;
    } 
    return true;
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    cout<<isPalindrome(s)<<endl;
    return 0;
}