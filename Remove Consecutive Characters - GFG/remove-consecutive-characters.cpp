// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        char curr=S[0];
        string str="";
        str+=curr;
        for(int i=0;i<S.size();i++){
            if(S[i]==curr){
                continue;
            }
            else{
                str+=S[i];
                curr=S[i];
            }
        }
        return str;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends