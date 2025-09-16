#include<iostream>
using namespace std;
/*
// Bruteforce approach
// TC:O(n^2)
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int fuel = 0;
    vector<int> startP;
    for(int i=0; i<n; i++){
        if(gas[i] >= cost[i]){
            startP.push_back(i);
        }
    } 
    for(int idx=0; idx<startP.size(); idx++){
        int start = startP[idx];
        int fuel = 0;
        int i = start;
        int count = 0;
        while(count < n){
            fuel += gas[i] - cost[i];
            if(fuel < 0) break;
            i = (i+1)%n;
            count++;
        }
        if(count == n) return start;
    }
    return -1;
}
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int totalGas = 0, totalCost = 0, tank = 0, start = 0;
    for(int i=0; i<n; i++){
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];
        if(tank < 0){
            start = i+1; 
            tank = 0;
        }
    }
    return totalGas >= totalCost ? start : -1;
}

int main(){
    int n;
    cin>>n;
    vector<int>gas(n), cost(n);
    for(int i=0; i<n; i++){
        cin>>gas[i];
    }
    for(int i=0; i<n; i++){
        cin>>cost[i];
    }
    int res = canCompleteCircuit(gas, cost);
    cout<< res<<endl;
    return 0;
}