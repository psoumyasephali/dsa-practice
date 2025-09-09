#include<iostream>
using namespace std;

//Approach:1 
//TC:O(nlogn)
vector<int> getNoZeroIntegers(int n) {
        for(int A=1; A<n; A++){
            int B = n-A;
            if((to_string(A) + to_string(B)).find('0') == string::npos){
                return {A, B};
            }
        }
        return {};
}

/*
//---------------------------
//Approach:2
//TC:O(nlogn)
bool noZero(int num){
    while(num){
        if(num%10 == 0) return false;
        num /= 10;
    }
    return true;
}
vector<int> getNoZeroIntegers(int n) {
    vector<int> res;
    for(int i=1; i<=n/2; i++){
        if(noZero(i) && noZero(n-i)){
            res.push_back(i);
            res.push_back(n-i);
            return res;
        }
    }
    return res;
}

*/
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>vec = getNoZeroIntegers(n);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}