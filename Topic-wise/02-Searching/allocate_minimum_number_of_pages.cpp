#include<iostream>
#include<numeric>
using namespace std;

// Using Binary Search
// TC: O(n*log(sum(arr)-max(arr)))
bool isValid(vector<int> &arr, int n, int k, int max){
    int count = 1;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > max){
            count++;
            sum = arr[i];
        }
        if(count > k) return false;
    }
    return true;
}
int findPages(vector<int> &arr, int k) {
    int n = arr.size();
    if(n<k) return -1;
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(isValid(arr, n, k, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int res= findPages(arr, k);
    cout<<res<<endl;
    return 0;
}