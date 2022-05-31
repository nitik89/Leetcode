class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>>obs(n,vector<int>(m,INT_MAX));
        q.push({0,0});
        vector<vector<int>>dirs{{-1,0},{0,1},{1,0},{0,-1}};
        obs[0][0]=0;
        int ans=INT_MAX;
        while(!q.empty()){
            int sz=q.size();
            for(int p=0;p<sz;p++){
            auto vec=q.front();
           
            int i=vec.first;
            int j=vec.second;
            
            
            q.pop();
            
            for(int k=0;k<dirs.size();k++){
                int nx=i+dirs[k][0];
                int ny=j+dirs[k][1];
                if(nx>=n||ny>=m||nx<0||ny<0){
                    continue;
                }
              
                 if(obs[i][j]+grid[nx][ny]<obs[nx][ny]){
                     obs[nx][ny]=obs[i][j]+grid[nx][ny];
                    q.push({nx,ny});
                }
            }
            }
        }
        return obs[n-1][m-1];
    }
};