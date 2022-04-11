class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int total=n*m;
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr=m*i+j;
                int next=(curr+k)%total;
                int r=next/m;
                int c=next%m;
                ans[r][c]=grid[i][j];
            }
        }
        return ans;
    }
};