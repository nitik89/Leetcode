class Solution {
public:
    int dp[1<<8+1][9];
    int getAns(int i,vector<vector<int>>&st,vector<vector<int>>&men,int mask){
        if(i>=st.size()){
            return 0;
        }
        if(dp[mask][i]!=-1){
            return dp[mask][i];
        }
        int ans=INT_MIN;
        for(int k=0;k<men.size();k++){
            if((mask&(1<<k))){
               continue; 
            }
            int score=0;
            for(int j=0;j<men[k].size();j++){
                if(st[i][j]==men[k][j]){
                    score++;
                }
            }
            ans=max(ans,score+getAns(i+1,st,men,mask|(1<<k)));
        }
        return dp[mask][i]=ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        memset(dp,-1,sizeof dp);
      return getAns(0,students,mentors,0);
    }
};