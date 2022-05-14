// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>grp){
	     vector<int>ans(n+1,INT_MAX);
    ans[1]=0;
    for(int i=1;i<=n-1;i++){ //covering the v-1 interations 
        for(int j=0;j<grp.size();j++){//on all the edges
           int u=grp[j][0];
                int v=grp[j][1];
                int wt=grp[j][2];
                
                if(ans[u]==INT_MAX){
                    continue;
                }
                if(ans[u]+wt<ans[v]){ //relaxing the neighbours
                   ans[v]=ans[u]+wt; 
                }
        }
    }
    int fl=0;
    for(int j=0;j<grp.size();j++){//on all the edges
           int u=grp[j][0];
                int v=grp[j][1];
                int wt=grp[j][2];
                        if(ans[u]==INT_MAX){
                    continue;
                }
                if(ans[u]+wt<ans[v]){ //relaxing the neighbours
                fl=1;
                   ans[v]=ans[u]+wt; 
                   break;
                }
        }
        return fl;
  
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends