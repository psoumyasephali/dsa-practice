#include<iostream>
using namespace std;

void printBoundaryEl(vector<vector<int>>&mat){
    int r = mat.size();
    int c = mat[0].size();

    // single row
    if(r==1){
        for(int i=0; i<c; i++){
            cout<<mat[0][i]<<" ";
        }
        return;
    }
    // single col
    if(c==1){
        for(int i=0; i<r; i++){
            cout<<mat[i][0]<<" ";
        }
        return;
    }
    // top row 
    for(int col=0; col<c; col++){
        cout<<mat[0][col]<<" ";
    }
    // right col
    for(int row=1; row<r; row++){
        cout<<mat[row][c-1]<<" ";
    }
    // bottom row
    for(int col=c-2; col>=0; col--){
        cout<<mat[r-1][col]<<" ";
    }
    // left col
    for(int row=r-2; row>=1; row--){
        cout<<mat[row][0]<<" ";
    }   
    cout<<endl;
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
    printBoundaryEl(mat);
    return 0;
}