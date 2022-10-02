class Solution {
public:
    int minimizeXor(int nums1, int nums2) {
        vector<int>vec(32);
        vector<int>ans(32);
        int cnt=0;
        for(int i=0;i<32;i++){
            int mask=(1<<i)&(nums2);
            vec[i]=mask;
            if(mask){
                cnt++;
            }
        }
        
        for(int i=31;i>=0;i--){
            int mask=(1<<i)&(nums1);
            
            if(mask&&(cnt>0)){
                // cout<<i<<" ";
                ans[i]=1;
                cnt--;
            }
        }
        // cout<<cnt<<" ";
        if(cnt>0){
            for(int i=0;i<31;i++){
                 int mask=(1<<i)&(nums1);
                if((mask==0)&&cnt){
                    ans[i]=1;
                    cnt--;
                }
            }
        }
        // cout<<cnt<<" ";
        int num=0;
        for(int i=0;i<31;i++){
            if(ans[i]){
            num+=(1<<i);
            }
        }
        return num;
        
    }
};