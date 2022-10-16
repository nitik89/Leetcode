class Solution {
public:
    int dp[11][301];
    int getAns(vector<int>& job,int d,int idx){
        if(d==0&&idx==job.size()){
            return 0;
        }
        if(d==0||idx==job.size()){
            return -1;
        }
        if(dp[d][idx]!=-1){
            return dp[d][idx];
        }
        
        int mx=INT_MIN;
        int ans=30001;
        for(int i=idx;i<job.size();i++){
            mx=max(job[i],mx);
            int x=getAns(job,d-1,i+1);
            if(x!=-1&&x!=30001){
            ans=min(ans,mx+x);
            }
        }
        return dp[d][idx]=ans;
        
    }
    int minDifficulty(vector<int>& job, int d) {
        memset(dp,-1,sizeof dp);
       int val=getAns(job,d,0);
        if(val==30001){
            return -1;
        }
        else{
            return val;
        }
    }
};