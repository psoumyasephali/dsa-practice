#include<iostream>
using namespace std;

//Approach: 1 (Bruteforce)
//TC : O(n^2)

// vector<int> nextGreater(vector<int> &arr) {
//     int n = arr.size();
//     vector<int> res(n, -1);
//     for(int i=0; i<n; i++){
//         for(int j=1; j<n; j++){
//             if(arr[i] < arr[(i+j)%n]){
//                 res[i] = arr[(i+j)%n];
//                 break;
//             }
//         }
//     }
//     return res;
// }

// Approach: 2 (Using Stack)
//TC: O(n)
vector<int> nextGreater(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> res(n, -1);
    for(int i=2*n-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i%n]){
            st.pop();
        }
        if(i<n && !st.empty()){
            res[i] = st.top();
        }
        st.push(arr[i%n]);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    vector<int> res = nextGreater(vec);
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
