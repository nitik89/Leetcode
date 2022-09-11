class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
       unordered_map<int,int>mp;
        int mx=INT_MIN;
        for(auto x:in){
            mp[x[0]]++;
            mp[x[1]+1]--;
            mx=max(mx,x[1]+1);
        }
        vector<int>dp(mx+1);
        for(auto x:mp){
            dp[x.first]=x.second;
        }
        int ans=INT_MIN;
        for(int i=1;i<mx;i++){
            dp[i]+=dp[i-1];
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};