class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qu) {
        vector<vector<int>>mp(n);
        vector<int>indeg(n,0);
        vector<vector<bool>>dep(n,vector<bool>(n,false));
        for(auto x:pre){
            mp[x[0]].push_back(x[1]);
            indeg[x[1]]++;
            dep[x[1]][x[0]]=true;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int idx=0;
         vector<bool>ans(qu.size(),false);
        
        while(!q.empty()){
           int x=q.front();
           
            idx++;
            q.pop();
            for(auto y:mp[x]){
                
                for(int i=0;i<n;i++){
                    if(dep[x][i]){
                        dep[y][i]=true;
                    }
                }
                indeg[y]--;
                
                if(indeg[y]==0){
                    q.push(y);
                }
            }
        }
        
        
        for(int i=0;i<qu.size();i++){
            ans[i]=dep[qu[i][1]][qu[i][0]];
        }
        return ans;
    }
};