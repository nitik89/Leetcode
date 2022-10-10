class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>>vec;
    int getAns(vector<vector<int>>& grid,int k,int i,int j,int c){
        if(i==grid.size()-1&&j==grid[0].size()-1){
            return c%k==0;
        }
        int ans=0;
        if(vec[i][j][c]!=-1){
            return vec[i][j][c];
        }
        if(i+1<grid.size()){
         ans=ans%mod+getAns(grid,k,i+1,j,grid[i+1][j]%k+c%k);
        }
        if(j+1<grid[0].size()){
        ans=ans%mod+getAns(grid,k,i,j+1,grid[i][j+1]%k+c%k);
        }
        return vec[i][j][c]=ans%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vec.resize(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(100,-1)));
       return getAns(grid,k,0,0,grid[0][0]);
    }
};