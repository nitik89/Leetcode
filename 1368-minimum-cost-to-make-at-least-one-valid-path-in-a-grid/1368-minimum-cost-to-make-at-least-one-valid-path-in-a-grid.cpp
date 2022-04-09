class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dist[n][m];
            // int dist[m][n];
        int max=1e9;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            dist[i][j] = max;
        }
    }

        
        queue<pair<int,int>>q;
        dist[0][0]=0;
        q.push({0,0});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            // cout<<i<<" "<<j<<" "<<dist[i][j]<<"\n";
            q.pop();
            if(j+1<m){
             if(grid[i][j]==1){
                 if(dist[i][j]<dist[i][j+1]){
                     dist[i][j+1]=dist[i][j];
                     q.push({i,j+1});
                 }
             }   
             else{
                 if(dist[i][j]+1<dist[i][j+1]){
                     dist[i][j+1]=dist[i][j]+1;
                     q.push({i,j+1});
                 }
                 
             }
            }
            if(j-1>=0){
                 if(grid[i][j]==2){
                 if(dist[i][j]<dist[i][j-1]){
                     dist[i][j-1]=dist[i][j];
                     q.push({i,j-1});
                 }
             }   
             else{
                 if(dist[i][j]+1<dist[i][j-1]){
                     dist[i][j-1]=dist[i][j]+1;
                     q.push({i,j-1});
                 }
                 
             }
            }
            if(i+1<n){
                 if(grid[i][j]==3){
                 if(dist[i][j]<dist[i+1][j]){
                     dist[i+1][j]=dist[i][j];
                     q.push({i+1,j});
                 }
             }   
             else{
                 if(dist[i][j]+1<dist[i+1][j]){
                     dist[i+1][j]=dist[i][j]+1;
                     q.push({i+1,j});
                 }
                 
             }
            }
            if(i-1>=0){
                 if(grid[i][j]==4){
                 if(dist[i][j]<dist[i-1][j]){
                     dist[i-1][j]=dist[i][j];
                     q.push({i-1,j});
                 }
             }   
             else{
                 if(dist[i][j]+1<dist[i-1][j]){
                     dist[i-1][j]=dist[i][j]+1;
                     q.push({i-1,j});
                 }
                 
             }
            }
        }
        return dist[n-1][m-1];
    }
};