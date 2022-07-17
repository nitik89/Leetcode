class Solution {
public:
    int dp[1001][1001];
//     int getAns(int n,int k){
//         if(n==0&&k==0){
//             return 1;
//         }
//         if(dp[n][k]!=-1){
//             return dp[n][k];
//         }
//         int ans=0;
       
//         for(int i=0;i<=min(k,n-1);i++){
//             ans=ans%mod+getAns(n-1,k-i)%mod;
//         }
//         return dp[n][k]=ans%mod;
//     }
    int kInversePairs(int n, int k) {
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
         int mod=1e9+7;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0){
                    dp[i][j]=1;
                }
                else{
                    int ans=0;
                    for(int f=0;f<=min(j,i-1);f++){
            ans=ans%mod+dp[i-1][j-f]%mod;
                    }
                    dp[i][j]=dp[i][j]%mod+ans%mod;
                }
            }
        }
        return dp[n][k];
    }
};