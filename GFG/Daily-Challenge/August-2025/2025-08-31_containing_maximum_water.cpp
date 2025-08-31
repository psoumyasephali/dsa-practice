#include<iostream>
using namespace std;

// Using two-pointer method
// TC: O(n)
int maxWater(vector<int> &arr) {
    int n = arr.size();
    int maxWater = 0; 
    int left=0, right=n-1;
    while(left < right){
        int width = right - left;
        int height = min(arr[left], arr[right]);
        maxWater = max(maxWater, width*height);
        if(arr[left] < arr[right]) left++;
        else right--;
    }
    return maxWater;
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
    int res = maxWater(vec);
    cout<<res<<endl;
    return 0;
}