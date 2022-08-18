class Solution {
public:
    unordered_map<int,vector<int>>mp;
    vector<int>dp;
    vector<int>score;
    int gentree(int node){
        
        int cnt=0;
        for(auto x:mp[node]){
           cnt+=gentree(x);
        }
        dp[node]+=cnt+1;
        return cnt+1;
    }
    pair<long long,long long> getMax(int node,vector<int>&parent,int root){
        long long ans=1;
        if(parent[node]==-1){
            
            for(auto &x:mp[node]){
                ans*=dp[x];
            }
        }
        else{
            
            long long v=dp[root]-dp[node];
            ans*=v;
            for(auto &x:mp[node]){
                ans*=dp[x];
            }
        }
        long long myval=ans,count=1;
        for(auto &x:mp[node]){
                pair<long long,long long>pr=getMax(x,parent,root);
                long long v=pr.first;
                long long cnt=pr.second;
              // cout<<v<<" "<<cnt<<" "<<myval<<" "<<node<<" "<<x<<"\n";
            if(v>myval){
                myval=v;
                count=pr.second;
            }
            else if(myval==v){
                count+=pr.second;
            }
            }
        // cout<<ans<<" "<<node<<"\n";
        return {myval,count};
        
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int root;
        for(int i=0;i<parents.size();i++){
            if(parents[i]!=-1){
                mp[parents[i]].push_back(i);
            }
            else if(parents[i]==-1){
                root=i;
            }
        }
        dp.resize(parents.size(),0);
        score.resize(parents.size(),0);
        gentree(0);
    auto x=getMax(0,parents,root);
        return x.second;
       
    }
};