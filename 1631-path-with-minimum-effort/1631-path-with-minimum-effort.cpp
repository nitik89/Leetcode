class Solution {
public:
    bool isSafe(vector<vector<int>>&heights,int i,int j,vector<vector<int>>&vis){
         if(i>=heights.size()||j>=heights[0].size()||i<0||j<0||vis[i][j]==1){
                return false;
            }
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>>vis(heights.size(),vector<int>(heights[0].size(),0));
      q.push({0,{0,0}});
        int ans=INT_MAX;
    
        while(!q.empty()){
            int mark=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            
            if(i==heights.size()-1&&j==heights[i].size()-1){
               return mark;
            }
            if(vis[i][j]){
                q.pop();
                continue;
            }
            q.pop();
            vis[i][j]=1;
            if(isSafe(heights,i+1,j,vis)){
             int h=max(mark,abs(heights[i+1][j]-heights[i][j]));
            
                q.push({h,{i+1,j}});
            }
            if(isSafe(heights,i,j+1,vis)){
             int h=max(mark,abs(heights[i][j+1]-heights[i][j]));
                q.push({h,{i,j+1}});
            }
            if(isSafe(heights,i-1,j,vis)){
             int h=max(mark,abs(heights[i-1][j]-heights[i][j]));
                q.push({h,{i-1,j}});
            }
            if(isSafe(heights,i,j-1,vis)){
             int h=max(mark,abs(heights[i][j-1]-heights[i][j]));
                q.push({h,{i,j-1}});
            }
            
        }
        return ans==INT_MIN?0:ans;
        
    }
};