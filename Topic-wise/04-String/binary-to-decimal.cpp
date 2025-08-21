#include<iostream>
using namespace std;

int binary2Decimal(string s){
    int sum = 0, p = 1;
    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == '1'){
            sum += p;
        }
        p*=2;
    }
    return sum;
}
int main(){
    string s;
    cin>>s;
    cout<<binary2Decimal(s)<<endl;
    return 0;
}