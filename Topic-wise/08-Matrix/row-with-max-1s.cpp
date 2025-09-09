#include<iostream>
using namespace std;

// // Bruteforce Approach
// // TC:O(n*m)
// int rowWithMax1s(vector<vector<int>> &arr) {
//     int n = arr.size();
//     int m = arr[0].size();
//     int res, maxCnt1 = 0;
//     for(int i=0; i<n; i++){
//         int cnt1 = 0;
//         for(int j=0; j<m; j++){
//             if(arr[i][j] == 1) 
//                 cnt1++;
//         }
//         if(cnt1 > maxCnt1){
//             maxCnt1 = cnt1;
//             res = i;
//         }
//     }
//     return res;
// }

// Efficient Approach
// TC:O(n+m)
int rowWithMax1s(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    int i = 0, j = m-1, res = -1;
    while(i<n && j>=0){
        if(arr[i][j] == 1){
            res = i;
            j--;
        }
        else{
            i++;
        }
    }
    return res;
}

int main(){
    int n, m;
    cout<<"Enter n, m: ";
    cin>>n>>m;
    vector<vector<int>>vec(n, vector<int>(m));
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>vec[i][j];
        }
    }
    int res = rowWithMax1s(vec);
    cout<<res<<endl;
    return 0;
}
