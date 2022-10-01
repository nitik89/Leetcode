class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),n2=nums2.size();
        if(n%2==0&&n2%2==0){
            return 0;
        }
        else if(n%2==0){
            int ans=nums1[0];
            for(int i=1;i<n;i++){
                ans^=nums1[i];
            }
            return ans;
        }
        else if(n2%2==0){
            int ans=nums2[0];
            for(int i=1;i<n2;i++){
                ans^=nums2[i];
            }
            return ans;
        }
        else{
            int ans=nums1[0];
            for(int i=1;i<n;i++){
                ans^=nums1[i];
            }
           
            for(int i=0;i<n2;i++){
                ans^=nums2[i];
            }
            return ans;
        }
        return 0;
    }
};