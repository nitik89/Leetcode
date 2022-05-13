// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
      bool fn(int i , int j , int k , string s1, string s2 ,string s3, vector<vector<vector<int>>>& dp){
        if(i < 0){
            while(k >= 0 && j >= 0){
                if(s3[k--] != s2[j--]) return false;   
            }
            return k<0 && j <0;
        }
        if(j < 0){
            while(k >= 0 && i >= 0){
                if(s3[k--] != s1[i--]) return false;
            }
            return k<0 && i<0;
        }
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        if(s3[k] == s1[i] && s3[k] == s2[j]) {
            return dp[i][j][k] = fn(i-1,j,k-1,s1,s2,s3,dp) || fn(i,j-1,k-1,s1,s2,s3,dp);
        }
        if(s3[k] == s1[i]) return dp[i][j][k] = fn(i-1,j,k-1,s1,s2,s3,dp);
        else if(s3[k] == s2[j]) return dp[i][j][k] = fn(i,j-1,k-1,s1,s2,s3,dp);
        
        return dp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
         if(s1 == "") return s2 == s3;
        if(s2 == "") return s1 == s3;
        int n1=s1.size() , n2 = s2.size() , n3 = s3.size();
        if(n1 + n2 != n3) return false;
        vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
        return fn(n1-1,n2-1,n3-1 , s1,s2,s3, dp);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends