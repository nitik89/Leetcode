class Solution {
public:
    int dp[1001];
    int dfs(vector<int>&arr,int idx,int d){
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=0;
        for(int i=idx+1;i<arr.size()&&i<=d+idx&&arr[i]<arr[idx];i++){
            ans=max(ans,1+dfs(arr,i,d));
        }
        for(int i=idx-1;i>=0&&i>=idx-d&&arr[i]<arr[idx];i--){
            ans=max(ans,1+dfs(arr,i,d));
        }
        return dp[idx]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int ans=INT_MIN;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            ans=max(1+dfs(arr,i,d),ans);
        }
        return ans;
    }
};