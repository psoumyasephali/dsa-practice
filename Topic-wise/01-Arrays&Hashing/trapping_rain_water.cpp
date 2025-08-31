#include<iostream>
using namespace std;

/*
//TC: O(n^2)
int trap(vector<int>& height) {
    int n = height.size();
    int totalWater = 0;
    for(int i=1; i<n-1; i++){
        int lmax = height[i];
        for(int j=0; j<i; j++){
            lmax = max(lmax, height[j]);
        }
        int rmax = height[i];
        for(int j=i+1; j<n; j++){
            rmax = max(rmax, height[j]);
        }
        int waterLevel = min(lmax, rmax);
        totalWater += (waterLevel - height[i]);
    }
    return totalWater;
}
*/

/*
//TC: O(n)
//SC: O(n)
 int trap(vector<int>& height) {
    int n = height.size();
    int totalWater = 0;
    vector<int> lmax(n), rmax(n);

    lmax[0] = height[0];
    for(int i=1; i<n; i++){
        lmax[i] = max(lmax[i-1], height[i]);
    }

    rmax[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--){
        rmax[i] = max(rmax[i+1], height[i]);
    }
    for(int i=1; i<n-1; i++){
        int waterLevel = min(lmax[i], rmax[i]);
        totalWater += (waterLevel - height[i]);
    }
    return totalWater;
}
*/
//TC: O(n)
//SC: O(1)
int trap(vector<int> &height){
    int n = height.size();
    int l = 0, r = n-1;
    int lmax = height[0];
    int rmax = height[n-1];
    int maxWater = 0;
    while(l < r){
        if(lmax < rmax){
            l++;
            lmax = max(lmax, height[l]);
            maxWater += max(0, lmax-height[l]);
        }
        else{
            r--;
            rmax = max(rmax, height[r]);
            maxWater += max(0, rmax-height[r]);
        }
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
    int res = trap(vec);
    cout<<res<<endl;
    return 0;
}