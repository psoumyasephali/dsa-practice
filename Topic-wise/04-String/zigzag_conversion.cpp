#include<iostream>
using namespace std;

string zigzagConversion(string s, int numRows){
    if(numRows == 1) return s;
    string res = "";

    for(int i=0; i<numRows; i++){
        int idx = i;
        int deltaSouth = 2 * (numRows - i - 1);
        int deltaNorth = 2 * i;
        bool goingSouth = true;

        while(idx < s.length()){
            res += s[idx];
            if(i == 0){
                idx += deltaSouth;
            }
            else if(i == numRows-1){
                idx += deltaNorth;
            }
            else{
                if(goingSouth){
                    idx += deltaSouth;
                }
                else{
                    idx += deltaNorth;
                }
                goingSouth = !goingSouth;
            }
        }
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    int row;
    cin>>row;
    string res = zigzagConversion(s, row);
    cout<<res<<endl;
    return 0;
}