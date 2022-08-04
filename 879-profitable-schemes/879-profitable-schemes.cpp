class Solution {
public:
    int dp[101][101][101];
    int mod=1e9+7;
    int getAns(int i,int n,int minp,vector<int>&group,vector<int>&profit){
        if(i>=group.size()){
           return 0;
        }
        if(n<0){
            return 0;
        }
        
        if(dp[i][n][minp]!=-1){
            return dp[i][n][minp];
        }
        int inc=getAns(i+1,n-group[i],max(minp-profit[i],0),group,profit);
        int exc=getAns(i+1,n,minp,group,profit);
        if((max(minp-profit[i],0)==0)&&(n-group[i]>=0)){
            return dp[i][n][minp]=inc%mod+exc%mod+1;
        }
        return dp[i][n][minp]=inc%mod+exc%mod;
    }
    int profitableSchemes(int n, int min, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof dp);
        int ans=0;
        if(min==0){
            ans=1;
        }
         ans=ans%mod+getAns(0,n,min,group,profit);
        return ans%mod;
    }
};