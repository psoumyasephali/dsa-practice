// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
//using stack
//TC: O(n), SC: O(n)


#include<iostream>
#include<stack>
using namespace std;


int evaluatePostfix(vector<string>& arr) {
    stack<int> st;
    for(auto &s : arr){
        if(s=="+" || s=="-" || s=="*" || s=="/" || s=="^"){
            int b = (int)st.top(); st.pop();
            int a = (int)st.top(); st.pop();
            int res = 0;
            if(s == "+") res = a+b;
            else if(s == "-") res = a-b;
            else if(s == "*") res = a*b;
            else if(s == "/"){
                if(a*b < 0 && a%b!=0) res = a/b-1;
                else res = a/b;
            } 
            else res = pow(a,b);
            
            st.push(res);
        }
        else{
            st.push(stoi(s));
        }
    }
    return st.top();
}


int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<string>vec(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    int res = evaluatePostfix(vec);
    cout<<res<<endl;
    return 0;
}