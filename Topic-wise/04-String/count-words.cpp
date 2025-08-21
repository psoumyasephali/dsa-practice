#include<iostream>
#include<sstream>
using namespace std;

/*
// using stringstream class
int countWords(string sentence){
    int count = 0;
    string word;
    stringstream ss(sentence);
    while(ss >> word){
        count++;
    }
    return count;
}

int main(){
    string s;
    getline(cin, s);
    cout<<countWords(s)<<endl;
    return 0;
}
*/
//manual parsing with loops
int countWords(string sentence){
    int count=0;
    bool flag=false;
    for(int i=0; sentence[i] != '\0'; i++){
        if(sentence[i] == ' '){
            if(flag){
                count++;
                flag=false;
            }
        }else{
            flag=true;
        }
    }
    if(flag){
        count++;
    }
    return count;
}
int main(){
    string s;
    getline(cin, s);
    cout<<countWords(s)<<endl;
    return 0;
}