// https://leetcode.com/problems/smallest-integer-divisible-by-k/?envType=daily-question&envId=2025-11-25

#include<iostream>
using namespace std;

int smallestRepunitDivByK(int k) {
    int rem = 0;
    for(int i=1; i<=k; i++){
        rem = (rem*10+1)%k;
        if(rem == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    int k;
    cin>>k;
    int ans = smallestRepunitDivByK(k);
    cout<<ans<<endl;
    return 0;
}