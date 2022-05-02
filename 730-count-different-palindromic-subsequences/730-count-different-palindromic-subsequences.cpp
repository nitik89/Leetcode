class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int dp[s.size()][s.size()];
        int n=s.size();
        int mod=1000000007;
        memset(dp,0,sizeof dp);
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }
                else{
                    if(s[i]!=s[j]){
                        dp[i][j]=((dp[i+1][j])%mod+(dp[i][j-1])%mod-(dp[i+1][j-1])%mod)%mod;
                    }
                    else{
                        dp[i][j]=(dp[i+1][j-1]*2)%mod;
                        
                        int low=i+1,high=j-1;
                        while(low<=high&&s[i]!=s[low]){
                            low++;
                        }
                        while(low<=high&&s[j]!=s[high]){
                            high--;
                        }
                        
                        if(low<high){
                            dp[i][j]-=dp[low+1][high-1];
                        }
                        else if(low==high){
                            dp[i][j]+=1;
                        }
                        else{
                            dp[i][j]+=2;
                        }
                        
                        
                        
                    }
                   
                }
                 if(dp[i][j]<0){
                            dp[i][j]=(dp[i][j]+mod);
                        }
                        else{
                            dp[i][j]=dp[i][j];
                        }
            }
        }
        return dp[0][n-1];
    }
};