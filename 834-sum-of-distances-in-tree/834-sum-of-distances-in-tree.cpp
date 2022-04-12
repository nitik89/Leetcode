class Solution {
public:
    void dfs(vector<vector<int>>&grp,int i,vector<int>&count,vector<int>&dis,int parent){
        
        for(auto x:grp[i]){
            if(x==parent){
                continue;
            }
            dfs(grp,x,count,dis,i);
            count[i]+=count[x];
            dis[i]+=count[x]+dis[x];
        }
    }
    void dfs2(vector<vector<int>>&grp,int i,vector<int>&count,vector<int>&dis,int parent,int N){
        
        for(auto x:grp[i]){
            if(x==parent){
                continue;
            }
            dis[x]=dis[i]-count[x]+(N-count[x]);//make change for the nodes as u go upper wale ka answer correct bna hona chahiye
            dfs2(grp,x,count,dis,i,N);
            //source has the correct answer making the answer for it children
            
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>count(n,1);
        vector<int>dis(n,0);
        vector<vector<int>>grp(n);
        for(auto x:edges){
            grp[x[0]].push_back(x[1]);
            grp[x[1]].push_back(x[0]);
        }
        dfs(grp,0,count,dis,-1);
        dfs2(grp,0,count,dis,-1,n);
        return dis;
    }
};