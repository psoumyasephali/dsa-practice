#include<iostream>
using namespace std;

//TC: O(n^2)
int countTriangles(vector<int>& arr) {
    int n = arr.size(), count=0;
    if(n<3) return 0;
    sort(arr.begin(), arr.end());
    
    for(int k=n-1; k>=2; k--){
        int i=0, j=k-1;
        while(i<j){
            if(arr[i]+arr[j] > arr[k]){
                count += (j-i);
                j--;
            }
            else{
                i++;
            }
        }
    }
    return count;
}


int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>vec(n);
    cout<<"Insert elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    int res = countTriangles(vec);
    cout<<res<<endl;
    return 0;
}