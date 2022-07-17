class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int cnt=0;
        int cnt2=0;
        for(auto x:mp){
            if(x.second%2!=0){
                cnt++;
            }
            cnt2+=x.second/2;
            
        }
        return {cnt2,cnt};
    }
};