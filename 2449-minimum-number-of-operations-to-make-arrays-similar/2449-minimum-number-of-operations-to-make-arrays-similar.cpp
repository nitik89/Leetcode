class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& tar) {
        sort(nums.begin(),nums.end());
        sort(tar.begin(),tar.end());
        vector<int>odd1,odd2,even1,even2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even1.push_back(nums[i]);
            }
            else{
                odd1.push_back(nums[i]);
            }
            
            if(tar[i]%2==0){
                even2.push_back(tar[i]);
            }
            else{
                odd2.push_back(tar[i]);
            }
        }
        long long cnt=0;
        for(int i=0;i<odd1.size();i++){
            if(odd2[i]>odd1[i]){
                cnt+=(odd2[i]-odd1[i])/2;
            }
        }
        for(int i=0;i<even1.size();i++){
            if(even2[i]>even1[i]){
                cnt+=(even2[i]-even1[i])/2;
            }
        }
        return cnt;
    }
};