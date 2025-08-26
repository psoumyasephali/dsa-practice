#include<iostream>
using namespace std;

//TC: O(n)
int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int n = dimensions.size();
    int max_diag = 0, max_area=0;
    for(auto& rect : dimensions){
        int l = rect[0], w = rect[1];
        int diag = l*l+w*w;
        int area = l*w;

        if(diag > max_diag){
            max_diag = diag;
            max_area = area;
        }
        else if(diag == max_diag){
            max_area = max(max_area, area);
        }
    }
    return max_area;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<vector<int>>vec(n, vector<int>(2));
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>vec[i][j];
        }
    }
    int res = areaOfMaxDiagonal(vec);
    cout<<res<<endl;
    return 0;
}
