class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int n=heightMap.size(),m=heightMap[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    pq.push({heightMap[i][j],i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
        int water=0;
        
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            for(int i=0;i<dir.size();i++){
                int x1=x[1]+dir[i][0];
                int y1=x[2]+dir[i][1];
                int height=x[0];
                if(x1>=0 and y1>=0 and x1<n and y1<m and !vis[x1][y1]){
                    vis[x1][y1]=1;
                   if(height>heightMap[x1][y1]){
                       water+=height-heightMap[x1][y1];
                       pq.push({height,x1,y1});
                   }
                    else{
                     pq.push({heightMap[x1][y1],x1,y1});   
                    }
                   
                }
            }
        }
        return water;
    }
};