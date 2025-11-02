// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include<iostream>
#include <iomanip>
using namespace std;
/*
// Approach: 1 
// TC: O((n1+n1)log(n1+n2))
// SC: O(n1+n2)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> temp;
    temp.insert(temp.end(), nums1.begin(), nums1.end());
    temp.insert(temp.end(), nums2.begin(), nums2.end());
    sort(temp.begin(), temp.end());
    int n = temp.size();
    if(n%2 != 0) return (double) temp[n/2];
    else return ((double) temp[n/2-1] + temp[n/2])/2.0;
}
*/

// Approach: 2 (using BinarySearch)
// TC: O(log(min(n1,n2)))
// SC: O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    // Ensure nums1 is the smaller array
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    int begin = 0, end = n1;
    while(begin <= end){
        int i1 = (begin+end)/2;
        int i2 = (n1+n2+1)/2-i1;
        
        int min1 = (i1==n1) ? INT_MAX : nums1[i1];
        int max1 = (i1==0) ? INT_MIN : nums1[i1-1];
        int min2 = (i2==n2) ? INT_MAX : nums2[i2];
        int max2 = (i2==0) ? INT_MIN : nums2[i2-1];

        if(max1 <= min2 && max2 <= min1){
            if((n1 + n2) %2 == 0)
                return ((double)max(max1, max2) + min(min1, min2))/2.0;
            else
                return (double)max(max1, max2);
        }
        else if(max1 > min2) end = i1-1;
        else begin = i1+1;
    }
    return -1;
}


int main(){
    int n, m;
    cout<<"Enter n and m:  ";
    cin>>n>>m;
    vector<int>v1(n);
    cout<<"Insert elements for v1: "<<endl;
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    vector<int>v2(n);
    cout<<"Insert elements for v2: "<<endl;
    for(int i=0; i<n; i++){
        cin>>v2[i];
    }

    double res = findMedianSortedArrays(v1, v2);
    cout<<res<<endl;
    // cout<<fixed<<setprecision(2)<<res<<endl;  // #include <iomanip>
    return 0;
}