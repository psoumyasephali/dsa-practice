// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1 
// Company Tags : Google
// TC : O(nlogk)
// SC : O(k)
// Using priority queue(min Heap)

#include<iostream>
using namespace std;

void nearlySorted(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>>pq; //min heap
    int index=0;
    for(int i=0; i<arr.size(); i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            arr[index] = pq.top();
            index++;
            pq.pop();
        }
    }
    while(pq.size() > 0){
        arr[index] = pq.top();
        index++;
        pq.pop();
    }
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
    int k;
    cout<<"Enter k: ";
    cin>>k;
    nearlySorted(vec, k);
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    return 0;
}