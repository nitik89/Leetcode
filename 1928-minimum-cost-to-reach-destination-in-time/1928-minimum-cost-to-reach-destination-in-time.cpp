class Solution {
public:
    int dp[1001][1001];
    int getAns(int curr,int maxTime,int time,vector<vector<pair<int,int>>>&vec,vector<int>&fees,int n){
        if(time>maxTime){
            return 1e9;
        }
        if(curr==n-1){
            if(time<=maxTime){
                return fees[curr];
            }
            else{
                return 1e9;
            }
        }
        if(dp[curr][time]!=-1){
            return dp[curr][time];
        }
        int mx=1e9;
        for(auto x:vec[curr]){
             // cout<<x<<" ";
            
                mx=min(mx,getAns(x.first,maxTime,time+x.second,vec,fees,n)+fees[curr]);
            
        }
        return dp[curr][time]=mx;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n=fees.size();
        // cout<<n<<" ";
        memset(dp,-1,sizeof dp);
        vector<vector<pair<int,int>>>vec(n);
        int idx=0;
        for(auto x:edges){
            int curr=x[0];
            int ed=x[1];
            int cost=x[2];
            // cout<<curr<<" ";
           
            vec[curr].push_back({ed,cost});
            vec[ed].push_back({curr,cost});
            
        }
         int ans=getAns(0,maxTime,0,vec,fees,n);
        return ans==1e9?-1:ans;
        // return 1;
        
    }
};