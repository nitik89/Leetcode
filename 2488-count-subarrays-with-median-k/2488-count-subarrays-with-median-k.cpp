class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int b=0,s=0,ans=0;
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                idx=i;
                break;
            }
        }
        for(int i=idx-1;i>=0;i--){
            if(nums[i]>k){
                b++;
            }
            else{
                s++;
            }
            int diff=b-s;
            mp[diff]++;
            if(diff==0||diff==1){
                ans++;
            }
        }
     b=0,s=0;
        for(int i=idx+1;i<nums.size();i++){
            if(nums[i]>k){
                b++;
            }
            else{
                s++;
            }
            int diff=b-s;
            int a=-1*(diff);
            int c=-1*(diff)+1;
            // cout<<a<<" "<<c<<" "<<diff<<"\n";
            ans+=mp[a];
            ans+=mp[c];
        }
        return ans+1;
    }
};