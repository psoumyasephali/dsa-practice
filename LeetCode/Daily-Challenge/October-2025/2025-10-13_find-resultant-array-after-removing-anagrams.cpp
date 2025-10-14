// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/?envType=daily-question&envId=2025-10-13

#include<iostream>
using namespace std;

//TC : O(n*len)
bool isAnagram(string &a, string &b){ // O(len)
    if(a.size() != b.size()) return false;
    vector<int> freq(26, 0);
    for(int i=0; i<a.size(); i++){
        freq[a[i] - 'a']++;
        freq[b[i] - 'a']--;
    }
    for(int i=0; i<26; i++){
        if(freq[i] != 0)
            return false;
    }
    return true;
}
vector<string> removeAnagrams(vector<string>& words) {
    int n = words.size();
    vector<string> res;
    res.push_back(words[0]);
    for(int i=1; i<n; i++){ // O(n)
        if(!(isAnagram(res.back(), words[i])))
            res.push_back(words[i]);
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter number of words: ";
    cin>>n;
    vector<string>words(n);
    cout<<"Enter the words: "<<endl;
    for(int i=0; i<n; i++){
        cin>>words[i];
    }
    vector<string> result = removeAnagrams(words);
    cout<<"\nResultant words after removing anagrams: "<<endl;
    for(auto &w : result){
        cout<<w<<" ";
    }
    cout<<endl;
    return 0;
}
