/*

  *  
 ***
*****  
 ***
  *  

*/

#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

void pattern3(int n){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin>>n;
    pattern3(n);
    return 0;
}