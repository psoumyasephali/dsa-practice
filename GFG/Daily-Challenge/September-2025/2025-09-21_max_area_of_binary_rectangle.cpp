#include<iostream>
using namespace std;

int MAH(vector<int> &arr){
    int n = arr.size();
    vector<int> left, right;
    stack<pair<int, int>>st;
    int pseudoindex = -1;
    //NSL(Nearest smaller to left)
    for(int i=0; i<n; i++){
        if(st.size()==0){
            left.push_back(pseudoindex);
        }
        else if(st.top().first < arr[i]){
            left.push_back(st.top().second);
        }
        else{
            while(st.size() > 0 && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.size() == 0){
                left.push_back(pseudoindex);
            }else{
                left.push_back(st.top().second);
            }
        }
        st.push({arr[i], i});
    }
    //clear the stack
    while(!st.empty()){
        st.pop();
    }
    pseudoindex = n;
    //NSR(Nearest smaller to right)
    for(int i=n-1; i>=0; i--){
        if(st.size()==0){
            right.push_back(pseudoindex);
        }
        else if(st.top().first < arr[i]){
            right.push_back(st.top().second);
        }
        else{
            while(st.size() > 0 && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.size() == 0){
                right.push_back(pseudoindex);
            }else{
                right.push_back(st.top().second);
            }
        }
        st.push({arr[i], i});
    }
    reverse(right.begin(), right.end());
    
    int maxArea = 0;
    for(int i=0; i<n; i++){
        int width = right[i] - left[i] - 1;
        int area = width * arr[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int maxArea(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> v(m, 0);
    int ans = 0;
    for(int j=0; j<m; j++){
        v[j] = mat[0][j];
    }
    ans = MAH(v);
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                v[j] = 0;
            }else{
                v[j] += mat[i][j];
            }
        }
        ans = max(ans, MAH(v));
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }
    int ans = maxArea(v);
    cout<<ans<<endl;
    return 0;
}