/*

E 
D E 
C D E 
B C D E 
A B C D E 

*/


#include<iostream>
using namespace std;

void pattern6(int n){
    for(int i=0; i<n; i++){
        for(char ch = ('A'+n-1)-i; ch<=('A'+n-1); ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n;
    cin>>n;
    pattern6(n);
    return 0;
}