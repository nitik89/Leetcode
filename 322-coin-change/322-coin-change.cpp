class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==1&&amount%coins[0]!=0){
            return -1;
        }
        vector<int>dp(amount+1,0);
        dp[0]=0;
        for(int i=1;i<dp.size();i++){
            int mn=INT_MAX;
            for(int j=0;j<coins.size();j++){
                
                if(i>=coins[j]){
                    if(mn>dp[i-coins[j]]){
                    mn=1+dp[i-coins[j]];
                    }
                }
                
            }
            
           
            dp[i]=mn;
            
        }
       
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};