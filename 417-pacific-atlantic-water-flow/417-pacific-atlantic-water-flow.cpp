class Solution {
public:
    bool isSafe(int i,int j,vector<vector<int>>& vis,
                vector<vector<int>>& heights){
        if(i>=0 && j>=0 && i<heights.size() && j<heights[0].size()
          && vis[i][j]==0)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& vis,
            int i,int j){
        
        vis[i][j]=1;
        
        if(isSafe(i+1,j,vis,heights) && heights[i][j]<=heights[i+1][j])
            dfs(heights,vis,i+1,j);
        
        if(isSafe(i-1,j,vis,heights) && heights[i][j]<=heights[i-1][j])
            dfs(heights,vis,i-1,j);
        
        if(isSafe(i,j+1,vis,heights) && heights[i][j]<=heights[i][j+1])
            dfs(heights,vis,i,j+1);
        
        if(isSafe(i,j-1,vis,heights) && heights[i][j]<=heights[i][j-1])
            dfs(heights,vis,i,j-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>> pac(n,vector<int>(m,0));
        
        vector<vector<int>> alt(n,vector<int>(m,0));
        
        // left 
        for(int i=0;i<n;i++)
            dfs(heights,pac,i,0);
        
        // top
        for(int i=0;i<m;i++)
            dfs(heights,pac,0,i);
        
        // right
         for(int i=0;i<n;i++)
            dfs(heights,alt,i,m-1);
        
        // bottom
         for(int i=0;i<m;i++)
            dfs(heights,alt,n-1,i);
        
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]==1 && alt[i][j]==1) res.push_back({i,j});
            }
        }
        return res;
    }
};