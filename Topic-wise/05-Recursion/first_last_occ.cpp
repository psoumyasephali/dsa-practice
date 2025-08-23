#include<iostream>
using namespace std;

/*
// Approach: 1 (iterative linear search) 
// TC: O(n)
vector<int> find(vector<int>& arr, int x) {
    int first = -1, last = -1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == x){
            if(first == -1){
                first = i;
            }
            last = i;
        }
    }
    return {first, last};
}
*/



/*
// Approach: 2 (It gives TLE, beacuse of recursively linear search)
// TC : O(n)
int getFirstOcc(vector<int> &arr, int x, int start, int end){
        if(start > end) return -1;
        if(arr[start] == x) return start;
        else return getFirstOcc(arr, x, start+1, end);
    }
    
int getLastOcc(vector<int> &arr, int x, int start, int end){
    if(start > end) return -1;
    int index = getLastOcc(arr, x, start+1, end);
    if(index == -1 && arr[start] == x){
        return start;
    }
    return index;
}
vector<int> find(vector<int>& arr, int x) {
    int n = arr.size();
    int firstOcc = getFirstOcc(arr, x, 0, n-1);
    int lastOcc  = getLastOcc(arr, x, 0, n-1);
    return {firstOcc, lastOcc};
}
*/



//Approach: 3 (using binary search) for sorted array
//TC: O(logn)
int getFirstOcc(vector<int>& arr, int x){
    int start=0, end=arr.size()-1, ans = -1;
    while(start <= end){
        int mid = start+(end-start)/2;
        if(arr[mid] == x){
            ans = mid;
            end = mid-1; //searching left
        }
        else if(arr[mid] > x){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int getLastOcc(vector<int>& arr, int x){
    int start=0, end=arr.size()-1, ans = -1;
    while(start <= end){
        int mid = start+(end-start)/2;
        if(arr[mid] == x){
            ans = mid;
            start = mid+1; //searching right
        }
        else if(arr[mid] > x){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

vector<int> find(vector<int>& arr, int x) {
    int firstOcc = getFirstOcc(arr, x);
    int lastOcc  = getLastOcc(arr, x);
    return {firstOcc, lastOcc};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x; cin>>x;
    
    vector<int> res = find(arr, x);
    for(int ele : res){
        cout<<ele<<" ";
    }
    return 0;
}


// sort(arr.begin(), arr.end());
// int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
// int last  = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
