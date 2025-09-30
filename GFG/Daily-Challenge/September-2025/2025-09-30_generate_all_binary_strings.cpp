#include<iostream>
using namespace std;
/*
// Approach : 1 (using bit manipulation)
//TC: O(n * 2^n)
//Sc : O(n)
vector<string> binstr(int n) {
    vector<string> res;
    for(int i=0; i< (1 << n); i++){ //2^n times
        string s;
        for(int j = n-1; j>=0; j--){ // n times
            s += ((i>>j) & 1) ? '1' : '0';
        }
        res.push_back(s);
    }
    return res;
}
*/
// Approach : 2 (using recursion)
//TC: O(n * 2^n)
//Sc : O(n)
void binstrRec(string &s, int i, vector<string> &res){
        int n = s.size();
        
        if(i == n){
            res.push_back(s);
            return;
        }
        s[i] = '0';
        binstrRec(s, i+1, res);
        
        s[i] = '1';
        binstrRec(s, i+1, res);
    }
vector<string> binstr(int n) {
    string s(n, '0');
    vector<string> res;
    binstrRec(s, 0, res);
    return res;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<string>vec = binstr(n);
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<endl;
    return 0;
}
