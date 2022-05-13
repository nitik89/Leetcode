// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
     bool isSafe(vector<vector<int>>&grid,int i,int j){
        if(i>=grid.size()||j>=grid[i].size()||i<0||j<0||grid[i][j]!=-1){
            return false;
        }
        return true;
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	      queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    q.push({0,{i,j}});
                }
                else{
                    grid[i][j]=-1;
                }
            }
        }
       
        while(!q.empty()){
            int dis=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
           
            q.pop();
            if(isSafe(grid,x+1,y)){
                grid[x+1][y]=dis+1;
                q.push({dis+1,{x+1,y}});
            }
            if(isSafe(grid,x-1,y)){
                 grid[x-1][y]=dis+1;
                q.push({dis+1,{x-1,y}});
            }
            if(isSafe(grid,x,y+1)){
                 grid[x][y+1]=dis+1;
                q.push({dis+1,{x,y+1}});
            }
            if(isSafe(grid,x,y-1)){
                 grid[x][y-1]=dis+1;
                q.push({dis+1,{x,y-1}});
            }
            
        }
        return grid;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends