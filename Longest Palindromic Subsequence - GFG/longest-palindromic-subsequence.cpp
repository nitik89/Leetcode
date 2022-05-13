// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string a) {
        int n=a.size();
       int dp[n][n];
       int ans=1;
       memset(dp,0,sizeof dp);
       for(int g=0;g<n;g++){
           for(int i=0,j=g;j<n;i++,j++){
               if(g==0){
                   dp[i][j]=1;
               }
               else if(g==1){
                   if(a[i]==a[j]){
                       dp[i][j]=2;
                   }
                   else{
                       dp[i][j]=1;
                   }
               }
               else{
                   if(a[i]==a[j]){
                       dp[i][j]=dp[i+1][j-1]+2;
                   }
                   else{
                       dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                   }
               }
               ans=max(ans,dp[i][j]);
           }
       }
       
       
       return ans;
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends