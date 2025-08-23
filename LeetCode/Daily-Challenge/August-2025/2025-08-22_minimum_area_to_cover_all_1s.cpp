#include<iostream>
using namespace std;

//TC: O(m*n)
int minimumArea(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int minRow = m;
    int maxRow = -1;
    int minCol = n;
    int maxCol = -1;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }
    if(maxRow == -1) return 0; //no '1' found

    return (maxRow-minRow+1)*(maxCol-minCol+1);
}

int main(){
    int row, col;
    cin>>row>>col;
    vector<vector<int>> vec(row, vector<int> (col));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>vec[i][j];
        }
    }

    int res = minimumArea(vec);
    cout<<res<<endl;
    return 0; 
}