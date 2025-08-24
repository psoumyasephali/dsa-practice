#include<iostream>
using namespace std;

/*
//Approach: 1(Linear Search) Gives TLE
//TC = O(n*max(arr))
bool check(vector<int>& arr, int k, int m, int days){
    int bouquets = 0, count = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= days){
            count++;
        }
        else{
            bouquets += count/k;
            count = 0;
        }
    }
    bouquets += count/k;
    return bouquets >= m;
}
int minDaysBloom(vector<int>& arr, int k, int m) {
    int maxdays = *max_element(arr.begin(), arr.end());

    for(int d=1; d<=maxdays; d++){
        if(check(arr, k, m, d)){
            return d;
        }
    }
    return -1;
}
*/
//Approach: 2(using binary search)TC:O(n*log(max(arr)))
bool check(vector<int>& arr, int k, int m, int days){
    int bouquets = 0, count = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= days){
            count++;
        }
        else{
            bouquets += count/k;
            count = 0;
        }
    }
    bouquets += count/k;
    return bouquets >= m;
}
int minDaysBloom(vector<int>& arr, int k, int m) {
    int start=0, end=*max_element(arr.begin(), arr.end());
    int res = -1;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(check(arr, k, m, mid)){
            res = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return res;
}


// // Approach: 3 (use sort)TC:O(nlogn)
// int minDaysBloom(vector<int>& arr, int k, int m) {
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     int day = m*k;
//     if(n < day) return -1;
//     return arr[day-1];
// }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int m; cin>>m;
    int k; cin>>k;
    cout<<minDaysBloom(arr, k, m)<<endl;
    return 0;
}