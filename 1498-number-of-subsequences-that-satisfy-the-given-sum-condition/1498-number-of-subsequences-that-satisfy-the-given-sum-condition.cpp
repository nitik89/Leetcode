class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>fac(nums.size()+1,0);
        int mod=1e9+7;
        long long v=1;
        fac[0]=1;
        for(int i=1;i<(fac.size());i++)
        {
            v=(2LL*v)%mod;
            fac[i]=(fac[i-1]+v)%mod;
            fac[i]%=mod;
            
        }
        long long sum=0;
        sum+=(nums[0]*2<=target);
        for(int i=1;i<nums.size();i++){
            int idx=upper_bound(nums.begin(),nums.begin()+i,target-nums[i])-nums.begin();
            long long v=target-nums[i];
            if(v<0){
                continue;
            }
            // cout<<idx<<" "<<i<<"\n"; 
            if((long long)(nums[i]*2) <= target){
                sum=sum%mod+1;
            }
            // cout<<i<<" "<<idx<<"\n";

           idx--;
            if(idx<0){
                continue;
            }
            int j=(i-idx-2);
            // cout<<j<<" ";
            
            
             sum=(sum%mod+(fac[i-1]-((j>=0)?fac[j]:0))+mod)%mod;
            
           
        }
        return sum%mod;
    }
};