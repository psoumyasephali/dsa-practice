#include<iostream>
#include<map>
using namespace std;

//TC: O(n*n*logn)
vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    map<int, vector<int>> mp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mp[i-j].push_back(grid[i][j]);
        }
    }
    for(auto &it : mp){
        if(it.first >= 0){
            sort(it.second.rbegin(), it.second.rend());
        }else{
            sort(it.second.begin(), it.second.end());
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            grid[i][j] = mp[i-j].back();
            mp[i-j].pop_back();
        }
    }
    return grid;
}
int main(){
    int n, m;
    cout<<"Enter n: \n";
    cin>>n;
    vector<vector<int>> vec(n, vector<int>(n));
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>vec[i][j];
        }
    }
    sortMatrix(vec);
    cout<<"The resulted matrix is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}