class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>q;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>obs(n,vector<int>(m,INT_MAX));
        q.push({0,0,0});
        vector<vector<int>>dirs{{0,1},{-1,0},{0,-1},{1,0}};
        obs[0][0]=0;
        int ans=INT_MAX;
        while(!q.empty()){
            auto vec=q.top();
            int count=vec[0];
            int i=vec[1];
            int j=vec[2];
            
            
            q.pop();
            
            for(int k=0;k<dirs.size();k++){
                int nx=i+dirs[k][0];
                int ny=j+dirs[k][1];
                if(nx>=n||ny>=m||nx<0||ny<0){
                    continue;
                }
              
                 if(count+grid[nx][ny]<obs[nx][ny]){
                     obs[nx][ny]=count+grid[nx][ny];
                    q.push({count+grid[nx][ny],nx,ny});
                }
            }
            
        }
        return obs[n-1][m-1];
    }
};