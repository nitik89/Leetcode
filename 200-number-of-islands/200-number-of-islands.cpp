class Solution {
public:
    void  getAns(vector<vector<char>>& grid,int i,int j){
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]=='0'){
            return;
        }
        if(grid[i][j]=='1'){
            grid[i][j]='0';
            getAns(grid,i+1,j);
        getAns(grid,i-1,j);
        getAns(grid,i,j+1);
        getAns(grid,i,j-1);
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    getAns(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};