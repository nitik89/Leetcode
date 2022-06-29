class Solution {
public:
    int mod=1e9+7;
    int dp[10001][7][7];
    int dfs(int n,int prev,int parso){
        if(n==0){
            return 1;
        }
        if(dp[n][prev][parso]!=-1){
            return dp[n][prev][parso];
        }
        int cnt=0;
        for(int i=1;i<=6;i++){
            if((__gcd(prev,i)==1&&prev!=i&&parso!=i)||prev==0){
                // cout<<prev<<" "<<i<<"\n";
                cnt=(cnt%mod+dfs(n-1,i,prev)%mod)%mod;
            }
        }
        return dp[n][prev][parso]=cnt%mod;
    }
    int distinctSequences(int n) {
        memset(dp,-1,sizeof dp);
    return dfs(n,0,0);    
    }
};