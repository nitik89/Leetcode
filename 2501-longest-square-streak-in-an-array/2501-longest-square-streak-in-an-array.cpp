class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        int mx=INT_MIN;
        for(auto x:nums){
            mp[x]++;
            mx=max(mx,x);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            long long x=nums[i];
            int cnt=0;
            while(x<=mx){
                if(mp.find(x)==mp.end())break;
                cnt++;
                x*=x;
            }
            if(cnt>1){
                
                ans=max(ans,cnt);
            }
        }
        return ans==1||ans==0?-1:ans;
    }
};