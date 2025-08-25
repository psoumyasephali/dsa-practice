#include<iostream>
#include<map>
using namespace std;

//TC : O(n*m)
vector<vector<int>> diagonalSort(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    map<int, vector<int>> mp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mp[i-j].push_back(mat[i][j]);
        }
    }
    for(auto &it : mp){
        sort(it.second.begin(), it.second.end());
    }
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            mat[i][j] = mp[i-j].back();
            mp[i-j].pop_back();
        }
    }
    return mat;
}

int main(){
    int n, m;
    cout<<"Enter n, m: \n";
    cin>>n>>m;
    vector<vector<int>> vec(n, vector<int>(m));
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>vec[i][j];
        }
    }
    diagonalSort(vec);
    cout<<"The resulted matrix is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}