// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

#include<iostream>
using namespace std;

vector<int> calculateSpan(vector<int>& arr) {
    int n = arr.size();
    stack<pair<int, int>> st;
    vector<int> vec;
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top().first <= arr[i]){
                st.pop();
            }
        if(st.empty()){
            vec.push_back(-1);
        }
        else{
            vec.push_back(st.top().second);
        }
        st.push({arr[i], i});
    }
    for(int i=0; i<n; i++){
        vec[i] = i - vec[i];
    }
    return vec;
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
    vector<int> res = calculateSpan(vec);
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    return 0;
}