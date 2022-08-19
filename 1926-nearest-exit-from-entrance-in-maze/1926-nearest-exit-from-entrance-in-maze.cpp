class Solution {
public:
   
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int x=entrance[0];
        int y=entrance[1];
        queue<vector<int>>q;
        int a=x,b=y;
        
        q.push({x,y,0});
        int n=maze.size(),m=maze[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>vec={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int x=q.front()[0];
            int y=q.front()[1];
            int dis=q.front()[2];
            q.pop();
            if(vis[x][y]){
                continue;
            }
         if(a!=x||y!=b){
         if(x==0||y==0||x==maze.size()-1||y==maze[0].size()-1){
               return dis;
            }
        }
            vis[x][y]=1;
            
            
            for(int i=0;i<vec.size();i++){
                if(x+vec[i][0]>=0&&x+vec[i][0]<maze.size()&&y+vec[i][1]>=0&&y+vec[i][1]<maze[0].size()){
                    int x1=x+vec[i][0];
                    int y1=y+vec[i][1];
                    if(maze[x1][y1]=='.'){
                    q.push({x1,y1,dis+1});
                    }
                }
            }
            
        }
        return -1;
    }
};