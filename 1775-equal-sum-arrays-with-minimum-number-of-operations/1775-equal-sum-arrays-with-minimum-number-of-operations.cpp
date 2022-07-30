class Solution {
public:
    int getAns(vector<int>&nums1,vector<int>&nums2,int sum1,int sum2){
       int i=nums1.size()-1,j=0;
        int op=0;
        while(i>=0||j<nums2.size()){
            int diff=sum1-sum2;
            // cout<<i<<" "<<j<<"\n";
            if(j==nums2.size()||i>=0&&nums1[i]-1>6-nums2[j]){
                if(nums1[i]-1<=diff){
                    sum1-=(nums1[i]-1);
                }
                else{
                    sum1-=diff;
                }
                i--;
            }
            else if(i==-1||j<nums2.size()){
                // cout<<j<<"\n";
                if(6-nums2[j]<=diff){
                    sum2+=(6-nums2[j]);
                }
                else{
                    sum2+=diff;
                }
                 j++;
            }
            op++;
            diff=sum1-sum2;
            if(diff<=0){
                return op;
            }
            
           
        }
        // cout<<sum1<<" "<<sum2<<"\n";
        return -1;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int sum1=0,sum2=0;
        for(auto x:nums1){
            sum1+=x;
        }
        for(auto x:nums2){
            sum2+=x;
        }
        if(sum1>sum2){
            return getAns(nums1,nums2,sum1,sum2);
        }
        else if(sum2>sum1){
            return getAns(nums2,nums1,sum2,sum1);
        }
        else{
            return 0;
        }
        return -1;
    }
};