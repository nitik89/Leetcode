class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
  
        int dp[cost.size()+1];
        memset(dp,0,sizeof dp);
        dp[0]=0;
        dp[1]=0;
        
        for(int i=2;i<=cost.size();i++){
            dp[i]=min(cost[i-2]+dp[i-2],cost[i-1]+dp[i-1]);
        }
        return dp[cost.size()];
    }
};