#include<iostream>
#include<numeric>
using namespace std;

bool isValid(vector<int>& arr, int k, int maxTime){
        int n = arr.size(), sum = 0, painter=1;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > maxTime){
                painter++;
                sum = arr[i];
            }
            if(painter > k)
                return false;
        }
        return true;
}

int minTime(vector<int>& arr, int k) {
    int n = arr.size();
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int res = 0;
    while(start <= end){
        int mid = start+(end-start)/2;
        if(isValid(arr, k, mid)){
            res = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return res;
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
    int res= minTime(arr, k);
    cout<<res<<endl;
    return 0;
}