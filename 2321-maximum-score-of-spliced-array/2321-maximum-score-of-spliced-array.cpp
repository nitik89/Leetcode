class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>vec(n,0);
        vector<int>vec2(n,0);
        int sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            vec[i]=nums2[i]-nums1[i];
            vec2[i]=nums1[i]-nums2[i];
            sum1+=nums1[i];
            sum2+=nums2[i];        }
      
        int mx=INT_MIN,sum=0;
        for(int i=0;i<n;i++){
            sum+=vec[i];
            mx=max(mx,sum);
            if(sum<0){
                sum=0;
            }
        }
         int mx2=INT_MIN,sm=0;
        for(int i=0;i<n;i++){
            sm+=vec2[i];
            mx2=max(mx2,sm);
            if(sm<0){
                sm=0;
            }
        }
        // cout<<mx<<" "<<mx2<<"\n";
        // cout<<mx<<" ";
        return max({mx+sum1,sum2-mx,sum1,sum2,mx2-sum1,sum2+mx2});
    }
};