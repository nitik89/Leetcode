class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        stack<long long>lf;
        stack<long long>rg;
        vector<long long>lft(n,-1);
        vector<long long>rgt(n,n);
        for(int i=0;i<n;i++){
            while(!lf.empty() && nums[lf.top()]>=nums[i])
                lf.pop();
            lft[i]=lf.empty()?-1:lf.top();
            lf.push(i);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!rg.empty() && nums[rg.top()]>=nums[i])
                rg.pop();
            rgt[i]=rg.empty()?n:rg.top();
            rg.push(i);
        }
        long long ans=INT_MIN;
        for(int i=0;i<n;i++){
            int l=lft[i]+1;
            int m=rgt[i]-1;
            if(l<=k&&m>=k){
             
            ans=max(ans,(long long)(m-l+1)*nums[i]);
            }
        }
        return ans;
    }
};