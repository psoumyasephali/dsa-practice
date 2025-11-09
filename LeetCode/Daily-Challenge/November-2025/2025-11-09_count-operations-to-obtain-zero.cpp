// https://leetcode.com/problems/count-operations-to-obtain-zero/description/?envType=daily-question&envId=2025-11-09
#include<iostream>
using namespace std;

// Approach: 1 (Euclidian Algorithm)
// TC: O(logmax(num1, num2))
int countOperations(int num1, int num2) {
    int cnt = 0;
    while(num1 && num2){
        cnt += num1/num2;
        num1 %= num2;
        swap(num1, num2);
    }
    return cnt;
}


// int countOperations(int num1, int num2) {
//     int cnt = 0;
//     if(num1 == 0 || num2 == 0) return cnt;
//     if(num1 == num2) return cnt+1;
//     while(num1 > 0 && num2 > 0){
//         if(num1 > num2){
//             num1 -= num2;
//             cnt++;
//         }
//         else if(num2 > num1){
//             num2 -= num1;
//             cnt++;
//         }
//         else {
//             return cnt+=1;
//         }
//     }
//     return cnt;
// }

int main(){
    int num1, num2;
    cout<<"Enter num1, num2: ";
    cin>>num1>>num2;
    
    int res = countOperations(num1, num2);
    cout<<res<<endl;
    return 0;
}