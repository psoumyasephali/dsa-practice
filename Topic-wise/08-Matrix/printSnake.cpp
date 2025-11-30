#include<iostream>
using namespace std;

//Time Complexity : O(r*c)

// Approach : 1
// void printSnake(vector<vector<int>>&mat){
//     int r = mat.size();
//     int c = mat[0].size();

//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             if(i%2 == 0){
//                 cout<<mat[i][j]<<" ";
//             }
//             else{
//                 cout<<mat[i][c-j-1]<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

// Approach : 2
// void printSnake(vector<vector<int>>&mat){
//     int r = mat.size();
//     int c = mat[0].size();

//     for(int i=0; i<r; i++){
//         if(i%2 == 0){
//             for(int j=0; j<c; j++){
//                 cout<<mat[i][j]<<" ";
//             }
//         }
//         else{
//             for(int j=c-1; j>=0; j--){
//                 cout<<mat[i][j]<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int r, c;
//     cin>>r>>c;
//     vector<vector<int>>mat(r, vector<int>(c));
//     for(int i=0; i<r; i++){
//         for(int j=0; j<c; j++){
//             cin>>mat[i][j];
//         }
//     }
//     printSnake(mat);
//     return 0;
// }
//------------------------------------------Return function-----------------------------------
vector<vector<int>> printSnake(vector<vector<int>>&mat){
    int r = mat.size();
    int c = mat[0].size();

    vector<vector<int>>ans(r, vector<int>(c));
    for(int i=0; i<r; i++){
        if(i%2 == 0){
            for(int j=0; j<c; j++){
                ans[i][j] = mat[i][j];
            }
        }
        else{
            for(int j=0; j<c; j++){
                ans[i][j] = mat[i][c-j-1];
            }
        }
        cout<<endl;
    }
    return ans;
}
int main(){
    int r, c;
    cin>>r>>c;
    vector<vector<int>>mat(r, vector<int>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>result = printSnake(mat);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}