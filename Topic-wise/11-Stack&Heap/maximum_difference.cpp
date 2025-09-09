#include<iostream>
#include<stack>
using namespace std;

int findMaxDiff(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> ls(n), rs(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && (st.top() >= arr[i])){
            st.pop();
        }
        if(st.empty()){
            ls[i] = 0;
        }else{
            ls[i] = st.top();
        }
        st.push(arr[i]);
    }
    st = stack<int>();
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && (st.top() >= arr[i])){
            st.pop();
        }
        if(st.empty()){
            rs[i] = 0;
        }
        else{
            rs[i] = st.top();
        }
        st.push(arr[i]);
    }
    int res = 0;
    for(int i=0; i<n; i++){
        int diff = abs(ls[i] - rs[i]);
        res = max(res, diff);
    }
    return res;
    
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>vec(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    int res = findMaxDiff(vec);
    cout<<res<<endl;
    return 0;
}