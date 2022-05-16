class Solution {
public:
    bool isSafe(vector<vector<int>>& grid,int i,int j){
        if(i>=grid.size()||j>=grid[i].size()||i<0||j<0||grid[i][j]==1){
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        grid[0][0]=1;
        bool yes=true;
        int save=-1;
        while(!q.empty()&&yes){
            int path=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            if(i==grid.size()-1&&j==grid[i].size()-1){
                save=path;
                yes=false;
            }
            if(isSafe(grid,i+1,j)){
                grid[i+1][j]=1;
             q.push({path+1,{i+1,j}});   
            }
            if(isSafe(grid,i-1,j)){
                grid[i-1][j]=1;
             q.push({path+1,{i-1,j}});   
            }
            if(isSafe(grid,i,j+1)){
                grid[i][j+1]=1;
             q.push({path+1,{i,j+1}});   
            }
            if(isSafe(grid,i,j-1)){
                grid[i][j-1]=1;
             q.push({path+1,{i,j-1}});   
            }
            if(isSafe(grid,i+1,j+1)){
                grid[i+1][j+1]=1;
             q.push({path+1,{i+1,j+1}});   
            }
            if(isSafe(grid,i-1,j+1)){
                grid[i-1][j+1]=1;
             q.push({path+1,{i-1,j+1}});   
            }
            if(isSafe(grid,i+1,j-1)){
                grid[i+1][j-1]=1;
             q.push({path+1,{i+1,j-1}});   
            }
            if(isSafe(grid,i-1,j-1)){
                grid[i-1][j-1]=1;
             q.push({path+1,{i-1,j-1}});   
            }
            
        }
        return save;
    }
};