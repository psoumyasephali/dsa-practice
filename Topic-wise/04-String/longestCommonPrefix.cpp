#include<iostream>
using namespace std;
/*
//Approach 1: Using sorting 
//TC: 0(m*nlogn), where m = maximum no. of characters in any string
//SC: O(1)
string longestCommonPrefix(vector<string> &strs){
    int n = strs.size();
    if(n == 0) return "";
    if(n == 1) return strs[0];

    sort(strs.begin(), strs.end());

    int minlen = min(strs[0].size(), strs[n-1].size());

    string first=strs[0], last=strs[n-1];
    int i=0;
    while(i<minlen && first[i] == last[i]){
        i++;
    }
    return first.substr(0, i);
}

int main(){
    int n;
    cin>>n;
    vector<string> vec(n);
    for(int i=0; i<vec.size(); i++){
        cin>>vec[i];
    }
    cout<<"longest common prefix: "<<longestCommonPrefix(vec)<<endl;
    return 0;
}*/
/*
//Approach 2: word by word matching
TC: O(nm), n=no.of string, m = length of largest string
SC: O(m)
string commonPrefixUtil(string &s1, string &s2){
    string res= "";
    int len = min(s1.size(), s2.size());
    for(int i=0; i<len; i++){
        if(s1[i] != s2[i]){
            break;
        }
        res += s1[i];
    }
    return res;
}

string commonPrefix(string arr[], int n){
    string prefix = arr[0];
    for(int i=1; i<n; i++){
        prefix = commonPrefixUtil(prefix, arr[i]);
    }
    return prefix;
}

int main(){
    string arr[]={"geeksforgeeks", "geeks", "geezer", "hgseek"};
    int n = sizeof(arr)/sizeof(arr[0]);
    string ans = commonPrefix(arr, n);
    if(ans.length()){
        cout<<"common prefix: "<<ans<<endl;
    }
    else{
        cout<<"There is no common prefix."<<endl;
    }
    return 0;
}
*/


//Approach 3: using divide & conquer
string commonPrefixUtil(string &s1, string &s2){
    string res= "";
    int n1 = s1.size(), n2 = s2.size();
    for(int i=0; i<n1 && i<n2; i++){
        if(s1[i] != s2[i]){
            break;
        }
        res += s1[i];
    }
    return res;
}

string commonPrefix(string arr[], int low, int high){
    if(low == high){
        return arr[low];
    }
    if(high > low){
        int mid = low+(high-low)/2;
        string s1 = commonPrefix(arr, low, mid);
        string s2 = commonPrefix(arr, mid+1, high);

        return commonPrefixUtil(s1, s2);
    }
    return "";
}

int main(){
    string arr[]={"geeksforgeeks", "geeks", "geezer", "geek"};
    int n = sizeof(arr)/sizeof(arr[0]);
    string ans = commonPrefix(arr, 0, n-1);
    if(ans.length()){
        cout<<" The longest common prefix is: "<<ans<<endl;
    }
    else{
        cout<<"There is no common prefix."<<endl;
    }
    return 0;
}
