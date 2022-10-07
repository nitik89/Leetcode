class Solution {
public:
    int countTriplets(vector<int>& nums) {
       int mp[1<<16]={0};
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[nums[i]&nums[j]]++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<(1<<16);j++){
                if((nums[i]&(j))==0){
                  cnt+=mp[j];  
                }
            }
        }
        return cnt;
    }
};
