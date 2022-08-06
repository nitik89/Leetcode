class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long>mp;
        long long ans=0;
        vector<long long>dp(tasks.size());
        long long currspace;
        for(int i=0;i<tasks.size();i++){
            if(mp.find(tasks[i])==mp.end()){
                mp[tasks[i]]=i;
                ans++;
                dp[i]=ans;
            }
            else{
                ans++;
                long long time=ans-dp[mp[tasks[i]]]-1;
                long long diff=max(0LL,space-time);
                ans+=diff;
                mp[tasks[i]]=i;
                
                dp[i]=ans;
            }
        }
        return dp[tasks.size()-1];
    }
};