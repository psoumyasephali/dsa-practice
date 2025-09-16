// https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=daily-question&envId=2025-09-15
#include<iostream>
#include<sstream>
#include<unordered_set>
using namespace std;

//TC: O(n^2)
int canBeTypedWords(string text, string brokenLetters) {
    stringstream ss(text);
    string word;
    unordered_set<char> broken;
    for(char ch : brokenLetters){
        broken.insert(ch);
    }
    int count = 0;
    while(ss >> word){
        bool valid = true;
        for(char ch : word){
            if(broken.find(ch) != broken.end()){
                valid = false;
                break;
            }
        }
        if(valid)
            count++;
    }
    return count;
}

int main(){
    string text, brokenLetters;
    getline(cin, text);
    getline(cin, brokenLetters);

    int res = canBeTypedWords(text, brokenLetters);
    cout<<res<<endl;
    return 0;
}
//------------------------------ Java ------------------------------------------
/*
public int canBeTypedWords(String text, String brokenLetters) {
    Set<Character> broken = new HashSet<>();
    for(char c : brokenLetters.toCharArray()){
        broken.add(c);
    }
    String []words = text.split(" ");
    int count = 0;
    for(String word : words){
        boolean valid = true;
        for(char c : word.toCharArray()){
            if(broken.contains(c)){
                valid = false;
                break;
            }
        }
        if(valid)
            count++;
    }
    return count;
}
*/
//------------------------------------Python--------------------------------------
/*
 def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = set(brokenLetters)
        count = 0
        for word in text.split():
            if not any(c in broken for c in word):
                count += 1
        return count
        */