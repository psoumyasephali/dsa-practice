#include<iostream>
#include<map>
using namespace std;

//TC : O(n*m)
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    map<int, vector<int>> mp;
    vector<int> result;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mp[i+j].push_back(mat[i][j]);
        }
    }
    bool flip = true;
    for(auto &it : mp){
        if(flip){
            reverse(it.second.begin(), it.second.end());
        }
        for(int &num : it.second){
            result.push_back(num);
        }
        flip = !flip;
    }
    return result;
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
    vector<int>res = findDiagonalOrder(vec);
    cout<<"The diagonal order traversal is: "<<endl;
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}