// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int>stk;
	void dfs(int i,vector<int>vec[],vector<int>&vis){
	    vis[i]=1;
	    for(auto x:vec[i]){
	        if(!vis[x]){
	        dfs(x,vec,vis);
	        }
	    }
	    stk.push(i);
	}
	void dfs1(int i,vector<int>vec[],vector<int>&vis){
	    vis[i]=1;
	    for(auto x:vec[i]){
	        if(!vis[x]){
	        dfs(x,vec,vis);
	        }
	    }
	   
	}
    int kosaraju(int V, vector<int> adj[])
    {
        
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis);
        }
    }
            vector<int>transpose[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto x:adj[i]){
                transpose[x].push_back(i);
            }
        }
        int cnt=0;
        while(stk.size()>0){
            if(!vis[stk.top()]){
                cnt++;
                dfs1(stk.top(),transpose,vis);
            }
            stk.pop();
        }
        return cnt;
    }
    
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends