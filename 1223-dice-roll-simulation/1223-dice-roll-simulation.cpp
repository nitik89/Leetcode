class Solution {
public:
 // int dp[5001][5001][7];
    int mod=1e9+7;
    int dfs(int n,vector<int>&roll,int prev,int currlen,vector<vector<vector<int>>>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n][prev][currlen]!=-1){
            return dp[n][prev][currlen];
        }
        int cnt=0;
        for(int i=1;i<=6;i++){
            if(prev==i&&currlen+1<=roll[i-1]){
            cnt=cnt%mod+dfs(n-1,roll,i,currlen+1,dp)%mod;
            }
            else if(prev==i&&currlen+1>roll[i-1]){
                continue;
            }
            else{
                cnt=cnt%mod+dfs(n-1,roll,i,1,dp)%mod;
            }
        }
        return dp[n][prev][currlen]=cnt%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(7,vector<int>(16,-1)));
        // memset(dp,-1,sizeof dp);
        
       return dfs(n,rollMax,0,0,dp);
    }
};