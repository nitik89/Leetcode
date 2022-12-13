class Solution {
public:
    int dp[101][101];
    int getAns(vector<vector<int>>&matrix,int r,int c){
        if(r>=matrix.size()||c>=matrix[0].size()){
            return INT_MAX;
        }
        if(r==matrix.size()-1){
            return matrix[r][c];
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int down=getAns(matrix,r+1,c);
        int left=getAns(matrix,r+1,c-1);
        int right=getAns(matrix,r+1,c+1);
        return dp[r][c]=min(right,min(down,left))+matrix[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mn=INT_MAX;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<matrix.size();i++){
            int ret=getAns(matrix,0,i);
            if(ret<mn){
                mn=ret;
            }
        }
        return mn;
    }
};