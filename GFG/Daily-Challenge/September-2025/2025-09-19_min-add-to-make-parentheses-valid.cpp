#include<iostream>
using namespace std;

// // Approach :1
// // TC: O(n)
// int minParentheses(string& s) {
//     int balance =0, add=0;
//     for(char &ch : s){
//         if(ch == '('){
//             balance++;
//         }
//         else{
//             if(balance > 0) balance--;
//             else add++;
//         }
//     }
//     return balance+add;
// }

// Approach: 2 (using stack)
// TC: O(n), SC: O(n)

int minParentheses(string& s) {
    stack<char> st;
    for(char &ch : s){
        if(!st.empty() && ch == ')' && st.top() == '(') 
            st.pop();
        else
            st.push(ch);
    }
    return st.size();
}

int main(){
    string s;
    cin>>s;
    int res = minParentheses(s);
    cout<<res<<endl;
    return 0;
}