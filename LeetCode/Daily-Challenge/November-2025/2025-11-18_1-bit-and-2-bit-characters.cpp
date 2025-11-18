// https://leetcode.com/problems/1-bit-and-2-bit-characters/submissions/1833036776/?envType=daily-question&envId=2025-11-18


#include<iostream>
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size();
    int i=0;
    while(i<n-1){
        if(bits[i] == 1) i+= 2;
        else i+=1;
    }
    return i==n-1;
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
    int res = isOneBitCharacter(vec);
    cout<<res<<endl;
    return 0;
}