class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        queue<int>q;
        vector<int>vis(n,0);
        
        vector<int>indeg(n,0);
        for(auto x:left){
            if(x!=-1){
            indeg[x]++;
            }
        }
        for(auto x:right){
            if(x!=-1){
            indeg[x]++;
            }
        }
        int cnt=0,root=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                root=i;
                cnt++;
            }
        }
        if(cnt>1){
            return false;
        }
        q.push(root);
        vis[root]=1;
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(left[x]!=-1){
                if(!vis[left[x]]){
                    vis[left[x]]=1;
                    q.push(left[x]);
                }
                else{
                    return false;
                }
            }
            if(right[x]!=-1){
                if(!vis[right[x]]){
                    vis[right[x]]=1;
                    q.push(right[x]);
                }
                else{
                    return false;
                }
            }
            
        }
        for(auto x:vis){
            if(x==0){
                return false;
            }
        }
        return true;
    }
};