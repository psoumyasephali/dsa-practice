#include<iostream>
using namespace std;

bool stringStack(string &pat, string &tar) {
    int i = pat.size()-1;
    int j = tar.size()-1;

    while(i>=0 && j>=0){
        if(pat[i] == tar[j]){
            i--; j--;
        }
        else{
            i-=2;
        }
        if(j < 0) return true;
    }
    return false;
}

int main(){
    string pat, tar;
    cin>>pat>>tar;
    cout<<stringStack(pat, tar)<<endl;
    return 0;
}

//---------------------------Python--------------------------------
/*
def stringStack(self, pat, tar):
    i = len(pat)-1
    j = len(tar)-1

    while i>=0 and j>=0: 
        if pat[i] == tar[j]: 
            i-=1
            j-=1
        else:
            i-=2
        if j < 0:
            return True
    return False
*/
//-------------------------------Java-----------------------------------
/*public boolean stringStack(String pat, String tar) {
    int i = pat.length()-1;
    int j = tar.length()-1;

    while(i>=0 && j>=0){
        if(pat.charAt(i) == tar.charAt(j)){
            i--; j--;
        }
        else{
            i-=2;
        }
        if(j < 0) 
            return true;
    }
    return false;
}*/