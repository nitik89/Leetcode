class Solution {
public:
    int dp[(1<<14)+1][16];
    int getAns(vector<int>&tasks,int cs,int sum,int mask){
        // cout<<mask<<" "<<((1<<tasks.size())-1)<<"\n";
        if(mask==((1<<tasks.size())-1)){
            return 0;
        }
        
        if(dp[mask][cs]!=-1){
            return dp[mask][cs];
        }
        int mn=1e9;
        for(int i=0;i<tasks.size();i++){
            if((mask&(1<<i)))continue;
            if(cs+tasks[i]<=sum){
               mn=min(mn,getAns(tasks,cs+tasks[i],sum,mask|(1<<i)));
            }
            else{
                mn=min(mn,1+getAns(tasks,tasks[i],sum,mask|(1<<i)));
            }
            
        }
        return dp[mask][cs]=mn;
    }
    int minSessions(vector<int>& tasks, int st) {
        memset(dp,-1,sizeof dp);
      return getAns(tasks,0,st,0)+1;
    }
};