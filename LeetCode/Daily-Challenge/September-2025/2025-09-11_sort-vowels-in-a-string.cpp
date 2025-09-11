#include<iostream>
using namespace std;

/*
//Approach 1: (using sorting)
//TC : O(nlogn)
bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
string sortVowels(string s) {
    vector<int> temp;
    for(char ch : s){
        if(isVowel(ch)){
            temp.push_back(ch);
        }
    }
    sort(temp.begin(), temp.end());
    int idx=0;
    for(int i=0; i<s.size(); i++){
        if(isVowel(s[i])){
            s[i] = temp[idx];
            idx++;
        }
    }
    return s;
}
*/

//Approach 2: (Using counting sort)
//TC:O(n)
bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
string sortVowels(string s) {
    unordered_map<char, int> count;
    for(char ch : s){
        if(isVowel(ch)){
            count[ch]++;
        }
    }
    string sortedVowel = "AEIOUaeiou";
    string ans;
    int j=0;
    for(int i=0; i<s.size(); i++){
        if(!isVowel(s[i])){
            ans += s[i];
        }
        else{
            //skip to the character which is having remaining count
            while(count[sortedVowel[j]] == 0){
                j++;
            }
            ans += sortedVowel[j];
            count[sortedVowel[j]]--;
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<sortVowels(s)<<endl;
    return 0;
}