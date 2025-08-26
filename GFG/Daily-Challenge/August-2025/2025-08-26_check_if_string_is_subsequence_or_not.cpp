#include <iostream>
using namespace std;

// TC: O(s2.size())
bool isSubSeq(const string& s1, const string& s2){
    int m = s1.length(), n = s2.length();
  
    if (m > n) return false;
  
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
  
    return i == m;
}

int main(){
    string s1 = "gksrek";
    string s2 = "geeksforgeeks";
    isSubSeq(s1, s2) ? cout << "true\n" : cout << "false\n";
    return 0;
}