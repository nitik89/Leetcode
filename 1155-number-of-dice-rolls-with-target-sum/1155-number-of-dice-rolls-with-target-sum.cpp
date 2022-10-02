class Solution {
public:
    long long mod = 1000000007;
    int dp[1001][1001];
    int getAns(int d,int f,int target){
        if(target<0||d<0){
            return 0;
        }
        if(target==0&&d==0){
            return 1;
        }
        if(dp[d][target]!=-1){
            return dp[d][target];
        }
        
        
        int ways=0;
        for(int i=1;i<=f;i++){
            ways=(ways%mod+(getAns(d-1,f,target-i))%mod)%mod;
        }
        return dp[d][target]=ways;
        
    }
    int numRollsToTarget(int d, int f, int target) {
        memset(dp,-1,sizeof dp);
       return getAns(d,f,target);
    }
};