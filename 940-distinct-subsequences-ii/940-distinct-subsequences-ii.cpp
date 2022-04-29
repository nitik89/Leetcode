class Solution {
public:
    int distinctSubseqII(string s) {
        unordered_map<char,int>mp;
        int dp[s.size()];
        int ans=1;
        int mod=1e9+7;
        memset(dp,0,sizeof dp);
        dp[0]=1;
        mp[s[0]]=0;
        for(int i=1;i<s.size();i++){
            
            dp[i]=(2*(dp[i-1]%mod)%mod)+1;
            if(mp.find(s[i])!=mp.end()){
                int idx=mp[s[i]];
                if(idx-1>=0){
                dp[i]-=dp[idx-1];
                    
                }
                dp[i]--;
            }
            dp[i]=(dp[i]+mod)%mod;
            mp[s[i]]=i;
        }
        
       
        return dp[s.size()-1];
    }
};