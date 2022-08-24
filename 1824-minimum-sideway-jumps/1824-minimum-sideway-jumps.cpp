class Solution {
public:
    int dp[500001][4];
    int getAns(vector<int>&obs,int curr,int i){
        if(i == obs.size()-1){
            return 0;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        int mn=1e9;
        if(obs[i+1]==curr){
            if(curr-1>=1&&obs[i]!=curr-1){
                mn=min(mn,1+getAns(obs,curr-1,i+1));
            }
            if(curr+1<=3&&obs[i]!=curr+1){
                mn=min(mn,1+getAns(obs,curr+1,i+1));
            }
            if(curr+2<=3&&obs[i]!=curr+2){
                mn=min(mn,1+getAns(obs,curr+2,i+1));
            }
            if(curr-2>=1&&obs[i]!=curr-2){
                mn=min(mn,1+getAns(obs,curr-2,i+1));
            }
        }
        else{
            //move in the same
            mn=min(mn,getAns(obs,curr,i+1));
        }
        return dp[i][curr]=mn;
        
    }
    int minSideJumps(vector<int>& obs) {
        memset(dp,-1,sizeof dp);
        return getAns(obs,2,0);
    }
};