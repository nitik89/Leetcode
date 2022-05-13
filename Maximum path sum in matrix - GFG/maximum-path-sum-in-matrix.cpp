// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1001][1001];
int solve(int i,int j, vector<vector<int>>& mat){
       int r= mat.size(), col= mat[0].size();
       if(j<0 || j>col-1){
           return 0;
       }
       if(i==r-1){
           return mat[i][j];
       }
       if(dp[i][j]!= -1){
           return dp[i][j];
       }
       int a= mat[i][j]+ solve(i+1,j-1,mat);
       int b= mat[i][j]+ solve(i+1,j,mat);
       int c= mat[i][j]+ solve(i+1,j+1,mat);
       return dp[i][j]=max({a,b,c});
   }
   int maximumPath(int N, vector<vector<int>> Matrix)
   {
       memset(dp,-1,sizeof dp);
       int ans= 0;
       for(int i=0;i<N;i++){
           // check all the columns path then take max sum
           ans=max(ans,solve(0,i,Matrix));
       }
       return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends