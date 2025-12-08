// https://leetcode.com/problems/count-square-sum-triples/?envType=daily-question&envId=2025-12-08

#include<iostream>
using namespace std;

// Approach : Enumeration
// TC: O(n*n)
// SC: O(1)

int countTriples(int n) {
    int res = 0;
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            int c = int(sqrt(a*a+b*b+1.0));
            if(c<=n && c*c==a*a+b*b){
                res++;
            }
        }
    }
    return res;
}


int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int res = countTriples(n);
    cout<<res<<endl;
    return 0;
}