#include<iostream>
#include<sstream>
using namespace std;

int countTokens(string sentence, char delimiter) {
    int count = 0;
    string token;
    stringstream ss(sentence);

    while (getline(ss, token, delimiter)) {
        if (!token.empty()) count++;  // avoid counting empty tokens
        cout<<token<<endl;
    }
    return count;
}

int main() {
    // string s = "dog|cat|lion|tiger";
    string s = "apple,banana,cherry";
    // string s = "apple;banana;cherry;grape";
    stringstream ss(s);
    char delimiter;
    cin>>delimiter;
    cout << countTokens(s, delimiter) << endl; 
}
