class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        long long sum1=0,sum2=0;
        long long mod=1e9+7;
        while(i<n&&j<m){
            if(nums1[i]<nums2[j]){
                sum1=sum1+nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j]){
                sum2=sum2+nums2[j];
                j++;
            }
            else{
                long long curr_best=max(sum1,sum2);
                sum1=curr_best+nums1[i];
                sum2=curr_best+nums2[j];
                i++;
                j++;
            }
            
        }
        // cout<<sum1<<" "<<sum2<<"\n";
        while(i<n){
            sum1=sum1+nums1[i];
            i++;
        }
        while(j<m){
            sum2=sum2+nums2[j];
            j++;
        }
        return max(sum1,sum2)%mod;
    }
};