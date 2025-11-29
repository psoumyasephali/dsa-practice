// https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

#include<iostream>
using namespace std;

// Naive Approach: 
// Time complexity : (nlogn)

int setBits(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int countSetBits(int n) {
    int res = 0;
    for(int i=1; i<=n; i++){
        res += setBits(i);
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int result = countSetBits(n);
    cout<<result<<endl;
    return 0;
}