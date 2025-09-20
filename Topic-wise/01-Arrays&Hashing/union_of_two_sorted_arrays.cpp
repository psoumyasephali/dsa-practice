// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
#include<iostream>
using namespace std;

// Using merge sort
// TC:O(n+m), SC:O(1)
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int m = b.size();
    vector<int> res;
    int i=0, j=0;
    while(i<n && j<m){
        if(i>0 && a[i-1] == a[i]){
            i++;
            continue;
        }
        if(j>0 && b[j-1] == b[j]){
            j++;
            continue;
        }
        if(a[i] < b[j]){
            res.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]){
            res.push_back(b[j]);
            j++;
        }
        else{
            res.push_back(a[i]);
            i++; j++;
        }
    }
    while(i<n){
        if(i>0 && a[i-1] == a[i]){
            i++;
            continue;
        }
        
        res.push_back(a[i]);
        i++;
    }
    while(j<m){
        if(j>0 && b[j-1] == b[j]){
            j++;
            continue;
        }

        res.push_back(b[j]);
        j++;
    }
    return res;
    
}

int main() {
  
    vector<int> a = {1, 1, 2, 2, 2, 4};
    vector<int> b = {2, 2, 4, 4};
  
    vector<int> res = findUnion(a, b);
    for (int x : res) {
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}