class Solution {
public:
    int dp[101][101][205];
    int getAns(vector<vector<char>>& grid,int i,int j,int open){
        if(i>=grid.size()||j>=grid[0].size()){
            return false;
        }
        
        
        if(i==grid.size()-1&&j==grid[0].size()-1){
            // cout<<open<<" ";
            if(grid[i][j]==')'){
                open--;
            }
            else{
                open++;
            }
            return (open==0);
            
        }
         if(grid[i][j]=='('){
            open++;
        }
        else {
            open--;
        }
        if(open<0) {
            return false;
        }
         if(dp[i][j][open]!=-1){
            return dp[i][j][open];
        }
      
        // cout<<"h";
        return dp[i][j][open]=(getAns(grid,i+1,j,open)||getAns(grid,i,j+1,open));
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        return getAns(grid,0,0,0);
    }
};