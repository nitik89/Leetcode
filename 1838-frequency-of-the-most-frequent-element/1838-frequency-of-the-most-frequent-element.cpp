class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        int ans=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            int s=0,e=i,save=i;
            while(s<=e){
                int mid=(s+e)/2;
                long long sm=pre[i+1]-pre[mid];
                long long people=(i-mid+1);
                long long big=(long long)people*((long long)nums[i]);
                long long diff=big-sm;
                if(diff>k){
                    s=mid+1;
                    
                }
                else{
                    save=mid;
                    e=mid-1;
                }
            }
            ans=max(ans,i-save+1);
        }
        return ans;
    }
};