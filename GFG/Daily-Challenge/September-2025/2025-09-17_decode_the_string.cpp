// https://www.geeksforgeeks.org/problems/decode-the-string2444/1
//Approach : using stack
//TC: O(n+k); where n = length of string, k = length of expanded output string

#include<iostream>
using namespace std;

string decodedString(string &s) {
    stack<char> st;
    string res="";
    for(char ch : s){
        if(ch != ']'){
            st.push(ch);
        }
        else{
            // Get the substring inside bracket
            string substr = "";
            while(!st.empty() && st.top() != '['){
                substr = st.top() + substr;
                st.pop();
            }
            // Pop the opening '['
            if(!st.empty() && st.top() == '[') st.pop();
            
            //Now extraxt the number
            string numStr = "";
            while(!st.empty() && isdigit(st.top())){
                numStr = st.top() + numStr;
                st.pop();
            }
            int repeat = stoi(numStr);
            // repeat the substring and push_back
            string expanded = "";
            for(int i=0; i<repeat; i++)
                expanded += substr;
            for(char ch : expanded)
                st.push(ch);
        }
    }
    // Collect result
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    return res;
}


int main(){
    string s;
    cin>>s;
    string res = decodedString(s);
    cout<<res<<endl;
    return 0;
}