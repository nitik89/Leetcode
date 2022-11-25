class Solution {
public:
    int dfs(vector<vector<int>>&vec,vector<int>&nums,int x,int parent,int tar){
        
        int sum=nums[x];
        for(auto y:vec[x]){
            if(parent==y) continue;
            sum+=dfs(vec,nums,y,x,tar);
        }
        if(sum==tar) return 0;
        return sum;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum=0,n=nums.size();
        for(auto x:nums){
            sum+=x;
        }
        vector<vector<int>>vec(n+1);
        for(auto x:edges){
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);
        }
        int ans=0;
        for(int i=sum;i>=1;i--){
            if(sum%i==0){
                if(!dfs(vec,nums,0,-1,sum/i)){
                    ans=max(ans,i-1);
                }
            }
        }
        return ans;
    }
};