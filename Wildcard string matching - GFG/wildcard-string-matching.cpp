// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string p, string s)
    {
        bool dp[p.size()+1][s.size()+1];
        for(int i=0;i<=p.size();i++){
            for(int j=0;j<=s.size();j++){
                if(i==0&&j==0){
                    dp[i][j]=true;
                }
                else if(i==0){
                    dp[i][j]=false;
                }
                else if(j==0){
                    if(p[i-1]=='*'){
                        dp[i][j]=dp[i-1][j]; 
                    }
                   else{
                       dp[i][j]=false;
                   }
                }
                else {
                    if(p[i-1]=='*'){
                        dp[i][j]=dp[i-1][j]||dp[i][j-1]||dp[i-1][j-1];
                    }
                    else if(p[i-1]=='?'){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[i-1]==s[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
    }
    return dp[p.size()][s.size()];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends