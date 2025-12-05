// https://leetcode.com/problems/maximum-running-time-of-n-computers/description/?envType=daily-question&envId=2025-12-02

#include<iostream>
#include<numeric>
using namespace std;

// Approach 1: Using Binary Search 
// TC: O(m*log(total/n))
// SC: O(1)

typedef long long ll;
bool possible(vector<int>& batteries, ll mid, int n){
    ll target = n * mid;
    for(int i=0; i<batteries.size(); i++){
        target -= min((ll)batteries[i], mid);
        if(target <= 0)
            return true;
    }
    return target <= 0;
}
long long maxRunTime(int n, vector<int>& batteries) {
    ll total = accumulate(batteries.begin(), batteries.end(), 0LL);
    ll left = *min_element(batteries.begin(), batteries.end());
    ll right = total/n;
    ll result = 0;
    while(left <= right){
        ll mid = left + (right-left)/2;
        if(possible(batteries, mid, n)){
            result = mid;
            left = mid + 1; 
        }
        else{
            right = mid - 1;
        }
    }
    return result;
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
    int m;
    cout<<"Enter m: ";
    cin>>m;
    long long res = maxRunTime(m, vec);
    cout<<res<<endl;
    return 0;
}