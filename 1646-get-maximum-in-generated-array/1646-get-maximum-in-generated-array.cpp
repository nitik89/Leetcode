class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
      vector<int>dp(n+1,0);
        dp[1]=1;
        int mx=1;
        for(int i=2;i<=n;i++){
          int idx=i/2;
          if(i%2==0){
           dp[i]=dp[idx];
          }
          else{
               dp[i]=dp[idx]+dp[idx+1];  
          }
            mx=max(dp[i],mx);
        }
        return mx;
    }
};