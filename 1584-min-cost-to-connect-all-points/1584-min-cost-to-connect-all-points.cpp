class Solution {
private:
    void initialize(vector<int>& parent, vector<int>& rank, int n) {
        for(int i=0; i<n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int find(vector<int>& parent, int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent, parent[x]);
    }
    void _union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int x_rep = find(parent, x);
        int y_rep = find(parent, y);
        
        if(x_rep == y_rep) return;
        
        if(rank[x_rep] < rank[y_rep]) parent[x_rep] = y_rep;
        else if(rank[x_rep] > rank[y_rep]) parent[y_rep] = x_rep;
        else {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Instead of sorting the edges, we are using a priority queue
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> edges;
        vector<int> parent(n);
        vector<int> rank(n);
        initialize(parent, rank, n);
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            int curr_x = points[i][0];
            int curr_y = points[i][1];
            
            for(int j=i+1; j<n; j++) {
                int next_x = points[j][0];
                int next_y = points[j][1];
                
                int wt = abs(curr_x - next_x) + abs(curr_y - next_y);
                edges.push({wt, i, j});
            }
        }
        
        int cnt = 0;
        while(!edges.empty() && cnt < n-1) {
            auto edge = edges.top();
            edges.pop();
            int x = find(parent, edge[1]);
            int y = find(parent, edge[2]);
            
            if(x != y) {
                ans += edge[0];
                _union(parent, rank, x, y);
                cnt++;
            }
        }
        return ans;
    }
};