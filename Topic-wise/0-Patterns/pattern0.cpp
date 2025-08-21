 /* 

5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5 

*/
#include<iostream>
using namespace std;

void pattern0(int n){
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            int top = i;
            int bottom = j;
            int right = (2*n-2)-j;
            int left = (2*n-2)-i;
            cout<<(n-min(min(top, bottom), min(right, left)))<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n;
    cin>>n;
    pattern0(n);
    return 0;
}