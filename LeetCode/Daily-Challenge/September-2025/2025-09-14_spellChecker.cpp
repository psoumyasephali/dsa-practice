// https://leetcode.com/problems/vowel-spellchecker/description/?envType=daily-question&envId=2025-09-14
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

unordered_set<string> exactWords;
unordered_map<string, string> caseMap;
unordered_map<string, string> vowelMap;

string toLower(const string &s){
    string res = s;
    for(char &ch : res){
        ch = tolower(ch);
    }
    return res;
}
string maskVowels(const string &s){
    string res = s;
    for(char &ch : res){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            ch = '*';
        }
    }
    return res;
}
string checkForMatch(string &query){
    if(exactWords.count(query)){
        return query;
    }
    //case error match
    string lowerQuery = toLower(query);
    if(caseMap.count(lowerQuery)){
        return caseMap[lowerQuery];
    }
    string maskedQuery = maskVowels(lowerQuery);
    if(vowelMap.count(maskedQuery)){
        return vowelMap[maskedQuery];
    }
    return "";
}
vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    for(auto &word : wordlist){
        exactWords.insert(word);
        string lowerWord = toLower(word);
        if(caseMap.find(lowerWord) == caseMap.end()){
            caseMap[lowerWord] = word;
        }
        string maskedWord = maskVowels(lowerWord);
        if(vowelMap.find(maskedWord) == vowelMap.end()){
            vowelMap[maskedWord] = word;
        }
    }
    vector<string> result;
    for(string query : queries){
        result.push_back(checkForMatch(query));
    }
    return result;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<string> wordlist(n);
    vector<string> queries(m);
    for(int i=0; i<n; i++){
        cin>>wordlist[i];
    }
    for(int j=0; j<m; j++){
        cin>>queries[j];
    }
    vector<string> res = spellchecker(wordlist, queries);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}