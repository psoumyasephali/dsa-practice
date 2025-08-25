#include<iostream>
using namespace std;

//TC: O(n*n)
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(i<j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<vector<int>> vec(n, vector<int>(n));
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>vec[i][j];
        }
    }
    rotate(vec);
    cout<<"Rotate matrix is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}