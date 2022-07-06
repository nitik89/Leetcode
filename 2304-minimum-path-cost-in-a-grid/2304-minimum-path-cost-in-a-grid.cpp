class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1){
                    dp[i][j]=grid[i][j];
                }
                else{
                    int mn=INT_MAX;
                    for(int k=0;k<=m-1;k++){
                        int idx=grid[i][j];
                        mn=min(mn,dp[i+1][k]+idx+moveCost[idx][k]);
                    }
                    dp[i][j]=mn;
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};