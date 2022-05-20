class Solution {
public:
    int dp[101][101];
    int getAns(int sx,int sy,int ex,int ey,vector<vector<int>>& grid){
       
        if(sx>ex||sy>ey||grid[sx][sy]==1){
            return 0;
        }
         if(sx==ex&&sy==ey){
           
            return 1;
        }
        
        if(dp[sx][sy]!=-1){
            return dp[sx][sy];
        }
        int path1=getAns(sx+1,sy,ex,ey,grid);
        int path2=getAns(sx,sy+1,ex,ey,grid);
        dp[sx][sy]=path1+path2;
        return dp[sx][sy];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(dp,-1,sizeof dp);
        return getAns(0,0,m-1,n-1,obstacleGrid);
    }
};