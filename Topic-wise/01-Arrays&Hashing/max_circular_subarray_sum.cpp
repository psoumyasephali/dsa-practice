#include<iostream>
#include<numeric>
using namespace std;

/*//Approach: 1
// Bruteforce solution: TC: O(n^2)
int maxCircularSum(vector<int> &arr) {
    int n = arr.size();
    int maxSum = arr[0];
    for(int i=0; i<n; i++){
        int currSum = 0;
        for(int j=0; j<n; j++){
            int idx = (i+j)%n;
            currSum += arr[idx];
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}
*/
//Approach: 2 (using kadanes algorithm) TC: O(n)
int kadanesMin(vector<int>& arr){
    int n = arr.size();
    int sum = arr[0], minSum = arr[0];
    for(int i=1; i<n; i++){
        sum = min(sum+arr[i], arr[i]);
        minSum = min(minSum, sum);
    }
    return minSum;
}
int kadanesMax(vector<int>& arr){
    int n = arr.size();
    int sum = arr[0], maxSum = arr[0];
    for(int i=1; i<n; i++){
        sum = max(sum+arr[i], arr[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int maxCircularSum(vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0); //<numeric>
    int minSum = kadanesMin(arr);
    int maxSum = kadanesMax(arr);
    int circSum = sum - minSum;
    if(maxSum > 0) return max(maxSum, circSum);
    return maxSum;
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
    int res = maxCircularSum(vec);
    cout<<res<<endl;
    return 0;
}