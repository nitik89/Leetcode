class Solution {
public:
    int dp[101][101];
    int getAns(int endx,int endy,int startx,int starty){
        if(startx==endx&&starty==endy){
            return 1;
        }
        if(startx>endx||starty>endy){
            return 0;
        }
        if(dp[startx][starty]!=-1){
            return dp[startx][starty];
        }
        int path1=getAns(endx,endy,startx+1,starty);
        int path2=getAns(endx,endy,startx,starty+1);
         dp[startx][starty]=path1+path2;
        return dp[startx][starty];
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
       return getAns(m-1,n-1,0,0);
    }
};