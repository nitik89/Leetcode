class Solution {
public:
    int mod=1e9+7;
    int firstDayBeenInAllRooms(vector<int>& nxt) {
        int n=nxt.size();
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=1;i<n-1;i++){
            if(nxt[i]!=i){
               
                dp[i]=((dp[i-1]%mod*2)%mod+1-((nxt[i]-1>=0)?dp[nxt[i]-1]:0)+mod)%mod;
            }
            else{
                dp[i]=dp[i-1]%mod+1;
            }
            dp[i]=dp[i]%mod;
        }
        
        return (dp[n-2]%mod*2)%mod;
    }
};