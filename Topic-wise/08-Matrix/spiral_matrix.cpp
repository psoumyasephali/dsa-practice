#include<iostream>
using namespace std;

//TC: O(m*n)
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int sr=0; //start row
    int er=m-1; //end row
    int sc=0;//start col
    int ec=n-1; //end col

    vector<int>res;
    while(sr<=er && sc<=ec){
        // start row
        for(int col=sc; col<=ec; col++){
            res.push_back(matrix[sr][col]);
        }
        // end column
        for(int row=sr+1; row<=er; row++){
            res.push_back(matrix[row][ec]);
        }
        // end row
        for(int col=ec-1; col>=sc; col--){
            if(sr==er) break;
            res.push_back(matrix[er][col]);
        }
        // start column
        for(int row=er-1; row>=sr+1; row--){
            if(sc==ec) break;
            res.push_back(matrix[row][sc]);
        }
        sr++;sc++;er--;ec--;
    }
    return res;
}

int main(){
    int m, n;
    cout<<"Enter m, n: \n";
    cin>>m>>n;
    vector<vector<int>> vec(m, vector<int>(n));
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>vec[i][j];
        }
    }
    vector<int>res = spiralOrder(vec);
    cout<<"The diagonal order traversal is: "<<endl;
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}