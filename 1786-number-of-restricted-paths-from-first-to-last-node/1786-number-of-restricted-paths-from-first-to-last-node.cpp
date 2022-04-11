class Solution {
public:
    int MOD=1e9+7;
	
	
	// Step 3.
    // to calculate the required output using dfs and memorization
    // storing the number of paths from a node (index of mem) that leads to the nth node with ntoxSD in decreasing order in vector mem
    int computeRequiredAnswer(int cnode, int n, vector<int> &mem, vector<int> &dist, int &ans, vector<vector<pair<int, int>>> &graph) {
		// if we have reached the node n
        if(cnode==n-1)
            return 1;
        
		// if we have already computed for the current node
        if(mem[cnode]!=-1)
            return mem[cnode];
        
		// to compute mem[current node]
        int cval=0;
        for(auto a : graph[cnode]) {
            if(dist[a.first]<dist[cnode]) {
                cval=(cval+computeRequiredAnswer(a.first, n, mem, dist, ans, graph))%MOD;
            }
        }
        mem[cnode]=cval;
        return cval;
    }
    
	
	// Step 2.
    // to calculate shortest distance of all the nodes from nth node
    vector<int> computeShortestPath(int n, vector<vector<pair<int, int>>> &graph) {
        vector<int> dist(n, INT_MAX);
        dist[n-1]=0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, n-1});
        
		//Dijkstra's Algorithm
        while(!pq.empty()) {
            int cnode=pq.top().second;
            int cdist=pq.top().first;
            pq.pop();
            for(auto a : graph[cnode]) {
                if(dist[a.first] > cdist+a.second) {
                    dist[a.first]=cdist+a.second;
                    pq.push({dist[a.first], a.first});
                }
            }
        }
        return dist;
    }
    
	
	// Step 1.
    // main function
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : edges) {
            graph[e[0]-1].push_back({e[1]-1, e[2]});
            graph[e[1]-1].push_back({e[0]-1, e[2]});
        }
        
		// to store the required shortest path
        vector<int> dist;
        dist=computeShortestPath(n, graph);
		
		// to store the number of paths that follows the given condition for each node
        vector<int> mem(n, -1);
        int ans=computeRequiredAnswer(0, n, mem, dist, ans, graph);
		
        return ans;
    }
};