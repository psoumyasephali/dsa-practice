#include<iostream>
using namespace std;

//using greedy
//TC: O(n)
int minJumps(vector<int>& arr) {
    int n = arr.size();
    if(arr[0] == 0) return -1;
    int maxReach = 0, currReach = 0, jump=0;
    for(int i=0; i<n; i++){
        maxReach = max(maxReach, i+arr[i]);
        if(maxReach >= n-1) return jump+1;
        if(i == currReach){
            if(maxReach == i) return -1;
            else{
                jump++;
                currReach = maxReach;
            }
        }
    }
    return -1;
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
    int res = minJumps(vec);
    cout<<res<<endl;
    return 0;
}