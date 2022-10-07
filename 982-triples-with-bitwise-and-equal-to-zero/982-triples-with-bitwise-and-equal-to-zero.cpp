class Solution {
public:
    int countTriplets(vector<int>& nums) {
       int mp[1<<16]={0};
        int n=nums.size();
        for(auto x:nums){
            for(auto y:nums){
                mp[x&y]++;
            }
        }
        int cnt=0;
        for(auto x:nums){
            for(int j=0;j<(1<<16);j++){
                if((x&(j))==0){
                  cnt+=mp[j];  
                }
            }
        }
        return cnt;
    }
};
