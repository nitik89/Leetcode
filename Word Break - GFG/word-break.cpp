// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
unordered_set<string>st;
bool getAns(string A){
    if(A.size()==0){
        return true;
    }
    bool ans=false;
    for(int i=0;i<A.size();i++){
        string str=A.substr(0,i+1);
        if(st.find(str)!=st.end()){
            ans|=getAns(A.substr(i+1));
        }
    }
    return ans;
}
    int wordBreak(string A, vector<string> &B) {
        for(auto x:B){
            st.insert(x);
        }
        return getAns(A);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends