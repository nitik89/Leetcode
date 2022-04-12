class Solution {
public:
  	vector<vector<int>> graph;
	vector<vector<int>> ans; 

	int time;
	vector<int> low, tin, visited;

	void dfs(int node, int parent = -1) {
		visited[node]=true;
        low[node]=tin[node]=time;
        time++;
        for(auto x:graph[node]){
            if(x==parent){
                continue;
            }
            if(visited[x]){ //Backedge
                low[node]=min(low[node],tin[x]);
            }
            else{
                dfs(x,node);
                if(tin[node]<low[x]){ //condition for the bridge
                    ans.push_back({node,x});
                }
                else{
                    low[node]=min(low[node],low[x]);
                }
            }
        }
	}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        graph.resize(n);
        for(auto x:con){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        low.resize(n);
        tin.resize(n);
        visited.resize(n);
        
        time=0;
        // for(auto x:id){
        //     cout<<x<<" ";
        // }
        dfs(0);
        return ans;
    }
};