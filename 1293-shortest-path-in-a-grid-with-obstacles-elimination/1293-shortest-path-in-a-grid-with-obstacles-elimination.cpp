class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>>q;
        int n=grid.size(),m=grid[0].size();
        q.push({0,0,0,0});
      vector<vector<int>>vis(n,(vector<int>(m,0)));
         vector<vector<int>>obs(n,vector<int>(m,INT_MAX));
         // cout<<n<<" "<<m<<"\n";
        int ans=INT_MAX;
        while(!q.empty()){
        
            auto vec=q.front();
            int i=vec[0];
            int j=vec[1];
            int steps=vec[2];
            int count=vec[3];
              // cout<<i<<" "<<j<<"\n";
            if(i==n-1&&j==m-1){
                cout<<count<<" ";
                return steps;
            }
            q.pop();
           
            
            
            if(i+1<n){
                if(count+grid[i+1][j]<=k&&!vis[i+1][j]){
                     vis[i+1][j]=1;
                     obs[i+1][j]=count+grid[i+1][j];
                    q.push({i+1,j,steps+1,count+grid[i+1][j]});
                }
                else if(vis[i+1][j]&&count+grid[i+1][j]<obs[i+1][j]){
                    obs[i+1][j]=count+grid[i+1][j];
                    q.push({i+1,j,steps+1,count+grid[i+1][j]});
                }
            }
            if(j+1<m){
               if(count+grid[i][j+1]<=k&&!vis[i][j+1]){
                     vis[i][j+1]=1;
                    obs[i][j+1]=count+grid[i][j+1];
                    q.push({i,j+1,steps+1,count+grid[i][j+1]});
                }
                else if(vis[i][j+1]&&count+grid[i][j+1]<obs[i][j+1]){
                    obs[i][j+1]=count+grid[i][j+1];
                    q.push({i,j+1,steps+1,count+grid[i][j+1]});
                }
            }
            if(j-1>=0){
               if(count+grid[i][j-1]<=k&&!vis[i][j-1]){
                     vis[i][j-1]=1;
                    obs[i][j-1]=count+grid[i][j-1];
                    q.push({i,j-1,steps+1,count+grid[i][j-1]});
                }
                else if(vis[i][j-1]&&count+grid[i][j-1]<obs[i][j-1]){
                    obs[i][j-1]=count+grid[i][j-1];
                    q.push({i,j-1,steps+1,count+grid[i][j-1]});
                }
            }
            if(i-1>=0){
               if(count+grid[i-1][j]<=k&&!vis[i-1][j]){
                     vis[i-1][j]=1;
                    obs[i-1][j]=count+grid[i-1][j];
                    q.push({i-1,j,steps+1,count+grid[i-1][j]});
                }
                else if(vis[i-1][j]&&count+grid[i-1][j]<obs[i-1][j]){
                    obs[i-1][j]=count+grid[i-1][j];
                    q.push({i-1,j,steps+1,count+grid[i-1][j]});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};




