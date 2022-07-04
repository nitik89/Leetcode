class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    int getAns(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long sum=0;
        for(int k=0;k<dir.size();k++){
            int x=dir[k][0],y=dir[k][1];
            if(i+x<grid.size()&&i+x>=0&&j+y<grid[0].size()&&j+y>=0&&grid[i+x][j+y]>grid[i][j]){
                sum=sum%mod+getAns(i+x,j+y,grid,dp)%mod+1;
            }
        }
        return dp[i][j]=sum%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=ans%mod+getAns(i,j,grid,dp)%mod;
            }
        }
        return ans%mod+(m*n)%mod;
        
    }
};