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
            long long sum=0;
            if(mp.find(s[i])==mp.end()){
                for(int j=0;j<i;j++){
                    sum+=dp[j]%mod;
                }
                sum+=1;
            }
            else{
                int idx=mp[s[i]];
                for(int j=idx;j<i;j++){
                    sum+=dp[j]%mod;
                }
            }
            dp[i]=sum%mod;
            mp[s[i]]=i;
            ans=ans%mod+sum%mod;
        }
       
        return ans%mod;
    }
};