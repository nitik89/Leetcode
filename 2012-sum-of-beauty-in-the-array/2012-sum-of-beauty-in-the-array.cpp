class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,-1);
        vector<int>suff(n,n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(nums[i],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=min(nums[i],suff[i+1]);
        }
        int ans=0;
        for(int i=1;i<=n-2;i++){
            
            if(nums[i]>pre[i-1]&&nums[i]<suff[i+1]){
                ans+=2;
            }
            else if(nums[i]>nums[i-1]&&nums[i+1]>nums[i]){
                ans++;
            }
        }
        return ans;
    }
};