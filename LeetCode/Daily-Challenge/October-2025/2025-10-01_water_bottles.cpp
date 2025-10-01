// https://leetcode.com/problems/water-bottles/submissions/1787831372/?envType=daily-question&envId=2025-10-01

#include<iostream>
using namespace std;


// Approach : 1 
// TC : O(numBottles/numExchange)
int numWaterBottles(int numBottles, int numExchange) {
    int sum = numBottles;
    while(numBottles >= numExchange){
        int exchange = numBottles/numExchange;
        int remaining = numBottles%numExchange;
        sum += exchange;
        numBottles = exchange+remaining;
    }
    return sum;
}

// Approach : 2 (using formula)
// TC : O(1)
int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles-1) / (numExchange-1);
}


int main(){
    int numBottles, numExchange;
    cout<<"Enter numBottles and numExchange: ";
    cin>>numBottles>>numExchange;

    int res = numWaterBottles(numBottles, numExchange);
    cout<<res<<endl;
    return 0;
}