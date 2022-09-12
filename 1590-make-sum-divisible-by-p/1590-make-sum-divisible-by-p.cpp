class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        unordered_map<long long,int>mp;
        vector<long long>suff(n,0);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=nums[i]+suff[i+1];
        }
        long long sum=0;
        mp[0]=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            // cout<<sum<<" "<<suff[i]<<"\n";
            if(sum%p==0){
                ans=min(ans,n-i-1);
            }
            if(suff[i]%p==0){
                ans=min(ans,i);
            }
             if(mp.find(p-suff[i]%p)!=mp.end()){
                 int v=i-1-mp[p-suff[i]%p];
                 // cout<<v<<" ";
                ans=min(v,ans);
            }
            mp[sum%p]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};