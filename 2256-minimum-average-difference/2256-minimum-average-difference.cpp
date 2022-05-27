class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
     vector<long long>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<prefix.size();i++){
            prefix[i]+=prefix[i-1]+nums[i];
        }
        long long ans=LONG_MAX,idx=-1;
        for(int i=0;i<n;i++){
            long long left=prefix[i]/(i+1);
            long long right=0;
            if(n-(i+1)!=0){
            right=(prefix[n-1]-prefix[i])/(n-(i+1));
            }
            long long diff=abs(left-right);
            // cout<<diff<<" ";
            if(ans>diff){
                ans=diff;
                idx=i;
            }
        }
        return idx;
    }
};