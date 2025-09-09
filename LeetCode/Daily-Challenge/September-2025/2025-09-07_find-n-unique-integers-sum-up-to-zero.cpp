#include<iostream>
using namespace std;

//TC: O(n)
vector<int> sumZero(int n) {
    vector<int> res;
    if(n%2) res.push_back(0);
    for(int i=1; i<=n/2; i++){
        res.push_back(i);
        res.push_back(-i);
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>vec = sumZero(n);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}