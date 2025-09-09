#include<iostream>
using namespace std;

//TC:O(n*logn)
int assignHole(vector<int>& mices, vector<int>& holes) {
    sort(mices.begin(), mices.end());
    sort(holes.begin(), holes.end());
    int ans = 0;
    for(int i=0; i<mices.size(); i++){
        int diff = abs(mices[i] - holes[i]);
        ans = max(ans, diff);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>vec1(n), vec2(n);

    cout<<"Insert elements for vec1: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec1[i];
    }
    
    cout<<"Insert elements for vec2: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec2[i];
    }
    int res = assignHole(vec1, vec2);
    cout<<res<<endl;
    return 0;
}