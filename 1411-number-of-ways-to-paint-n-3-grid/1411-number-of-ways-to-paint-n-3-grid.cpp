class Solution {
public:
    int dp[15001][4][4][4];
    int mod=1e9+7;
    int getAns(int n,int prev,int prev1,int prev2){
        if(n==0){
            return 1;
        }
        if(dp[n][prev][prev1][prev2]!=-1){
            return dp[n][prev][prev1][prev2];
        }
        int cnt=0;
        for(int i=1;i<=3;i++){
            if((i!=prev||n%3==0)&&i!=prev2){
                cnt=cnt%mod+getAns(n-1,i,prev,prev1)%mod;
            }
        }
        return dp[n][prev][prev1][prev2]=cnt%mod;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof dp);
      return  getAns(n*3,0,0,0);
    }
};