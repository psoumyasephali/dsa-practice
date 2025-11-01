// https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1
#include<iostream>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // to store {distance, {x, y}}
    priority_queue<pair<int, pair<int,int>>>maxHeap;
    
    for(auto point : points){
        int x = point[0], y = point[1];
        int dist = x*x+y*y;
        maxHeap.push({dist, {x,y}});
        if((int)maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    vector<vector<int>> res;
    while(maxHeap.size() > 0){
        auto top = maxHeap.top();
        maxHeap.pop();
        res.push_back({top.second.first, top.second.second});
    }
    return res;
}



int main(){
    int n, m, k;
    cout<<"Enter n, m and k: ";
    cin>>n>>m>>k;
    vector<vector<int>> vec(n, vector<int>(m));
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>vec[i][j];
    }
    vector<vector<int>> res = kClosest(vec, k);
    cout<< "k closest points to origin are: \n";
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[0].size(); j++){
            cout<<res[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}