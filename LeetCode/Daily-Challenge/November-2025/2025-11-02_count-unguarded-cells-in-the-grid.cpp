// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02

#include<iostream>
using namespace std;
/*
// Approach: 1 (Iterative Simulation)
// TC : O(m*n)
// SC : O(m*n)

const int unguarded = 0;
const int guarded = 1;
const int Guard = 2;
const int Wall = 3;

void markGuarded(int row, int col, vector<vector<int>>&grid){
    int m = grid.size(), n = grid[0].size();
    // Traverse upwards
    for(int r=row-1; r>=0; r--){
        if(grid[r][col] == Guard || grid[r][col] == Wall) break;
        grid[r][col] = guarded;
    }
    // Traverse downwards 
    for(int r=row+1; r<m; r++){
        if(grid[r][col] == Guard || grid[r][col] == Wall) break;
        grid[r][col] = guarded;
    }
    // Traverse leftwards
    for(int c=col-1; c>=0; c--){
        if(grid[row][c] == Guard || grid[row][c] == Wall) break;
        grid[row][c] = guarded;
    }
    // Traverse rightwards
    for(int c=col+1; c<n; c++){
        if(grid[row][c] == Guard || grid[row][c] == Wall) break;
        grid[row][c] = guarded;
    }
}
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>>grid(m, vector<int>(n, unguarded));
    for(const auto &guard : guards){
        grid[guard[0]][guard[1]] = Guard;
    }
    for(const auto &wall : walls){
        grid[wall[0]][wall[1]] = Wall;
    }
    for(const auto &guard : guards){
        markGuarded(guard[0], guard[1], grid);
    }
    int cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == unguarded) cnt++;
        }
    }
    return cnt;
}
*/
// Approach: 2 (Recursive way)
// TC : O(m*n)
// SC : O(m*n)

const int unguarded = 0;
const int guarded = 1;
const int Guard = 2;
const int Wall = 3;

void recursive(int row, int col, vector<vector<int>>&grid, char direction){
    int m = grid.size(), n = grid[0].size();
    if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==Guard ||
        grid[row][col]==Wall){
                return;
    }
    grid[row][col] = guarded;
    if(direction == 'U') recursive(row-1, col, grid, 'U'); // Up
    if(direction == 'D') recursive(row+1, col, grid, 'D'); // Down
    if(direction == 'L') recursive(row, col-1, grid, 'L'); // Left
    if(direction == 'R') recursive(row, col+1, grid, 'R'); // Right
}
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>>grid(m, vector<int>(n, unguarded));
    for(const auto &guard : guards){
        grid[guard[0]][guard[1]] = Guard;
    }
    for(const auto &wall : walls){
        grid[wall[0]][wall[1]] = Wall;
    }
    for(const auto &guard : guards){
        recursive(guard[0]-1, guard[1], grid, 'U');
        recursive(guard[0]+1, guard[1], grid, 'D');
        recursive(guard[0], guard[1]-1, grid, 'L');
        recursive(guard[0], guard[1]+1, grid, 'R');
    }
    int cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == unguarded) cnt++;
        }
    }
    return cnt;
}

int main(){
    // int m = 4, n = 6;
    // vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    // vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    int m = 3, n = 3;
    vector<vector<int>> guards = {{1,1}};
    vector<vector<int>> walls = {{0,1},{1,0},{2,1},{1,2}};
    int ans = countUnguarded(m, n, guards, walls);
    cout<<ans<<endl;
    return 0;
}