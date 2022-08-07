class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp(26,0);
        dp[s[0] - 'a']=1;
        int ans=1;
        for(int i=1;i<s.size();i++){
            char my=s[i];
            int mx=0;
            for(int j='a';j<='z';j++){
                int diff=abs((j - 'a')-(my - 'a'));
               
                if(diff<=k){
                   
                    mx=max(mx,dp[j - 'a']);
                }
            }
            dp[my - 'a']=max(mx+1,dp[my - 'a']);
            ans=max(dp[my - 'a'],ans);
            
        }
        return ans;
    }
};