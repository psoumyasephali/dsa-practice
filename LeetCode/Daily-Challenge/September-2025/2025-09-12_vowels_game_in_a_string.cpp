#include<iostream>
using namespace std;


bool isVowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
bool doesAliceWin(string s) {
    int cnt = 0;
    for(char &ch : s){
        if(isVowel(ch))
            cnt++;
    }
    if(cnt > 0) return true;
    return false;
}

int main(){
    string s;
    cin>>s;
    cout<<doesAliceWin(s)<<endl;
    return 0;
}