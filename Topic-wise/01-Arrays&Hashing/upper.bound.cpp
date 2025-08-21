#include<iostream>
using namespace std;

// vector<int> v = {1, 3, 3, 5, 7};
// auto it = upper_bound(v.begin(), v.end(), 3);
// cout << *it;   // prints 5 (first > 3)


int upper_bound(vector<int>& arr, int val){
    int low = 0, high = arr.size()-1;
    int ans  = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] > val){ //strictly greater
            ans = arr[mid];
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }
    int val;
    cin>>val;
    cout<<upper_bound(vec, val)<<endl;
    return 0;
}