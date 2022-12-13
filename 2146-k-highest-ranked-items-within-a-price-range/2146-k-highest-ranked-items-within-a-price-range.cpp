class Solution
{
    public:
        vector<vector < int>> highestRankedKItems(vector<vector < int>> &grid, vector< int > &p, vector< int > &s, int k) {
            int n=grid.size(),m=grid[0].size();
            vector<vector<int>>ans;
            vector<vector<int>>vis(n,vector<int>(m,false));
            queue<pair<int,int>>q;
            q.push({s[0],s[1]});
            int dis=0;
            vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
            while(!q.empty()){
                int sz=q.size();
                while(sz--){
                    pair<int,int>x=q.front();
                    q.pop();
                    int val=grid[x.first][x.second];
                    if(vis[x.first][x.second]||val==0) continue;
                    vis[x.first][x.second]=true;
                    if(p[0]<=val&&val<=p[1]){
                        ans.push_back({dis,val,x.first,x.second});
                    }
                    for(int u=0;u<dir.size();u++){
                        int px=x.first+dir[u][0];
                        int py=x.second+dir[u][1];
                        if(px<n&&px>=0&&py<m&&py>=0&&!vis[px][py]){
                            q.push({px,py});
                        }
                    }
                    
                }
                dis++;
            }
            sort(ans.begin(),ans.end());
            vector<vector<int>>res;
            for(int i=0;i<min(k,(int)ans.size());i++){
                res.push_back({ans[i][2],ans[i][3]});
            }
            return res;
            
        }
};